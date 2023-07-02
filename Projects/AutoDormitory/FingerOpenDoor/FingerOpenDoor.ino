#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Servo.h>
#include <Adafruit_Fingerprint.h>

//指纹部分————————————————————————————————————————————————————————————————————
#if (defined(__AVR__) || defined(ESP8266)) && !defined(__AVR_ATmega2560__)

// pin #2 is IN from sensor (GREEN wire)
// pin #3 is OUT from arduino  (WHITE wire)
// Set up the serial port to use softwareserial..
SoftwareSerial mySerial(5, 3);

#else
// On Leonardo/M0/etc, others with hardware serial, use hardware serial!
// #0 is green wire, #1 is white
#define mySerial Serial1

#endif

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);  //初始化指纹模块


//舵机部分——————————————————————————————————————————————————————————————————
Servo myservo;
int servo_max = 180;
int servo_close = 0;

//MQTT部分———————————————————————————————————————————————————————————————————
/*WIFI*/ const char* ssid = "wifi410";
/*KEYS*/ const char* password = "18661205519";
/*公网ip*/ const char* mqttServer = "124.220.206.170";
/*订阅主题*/ const char* MySub = "door410";

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);
const byte ledPin = BUILTIN_LED;

//——————————————————————————————————————————————————————————————————————————

void setup() {
  Serial.begin(115200);
  //初始化Wifi
  WiFi.mode(WIFI_STA);
  connectWifi();

  //初始化服务器
  mqttClient.setServer(mqttServer, 1883);
  connectMQTTServer();
  mqttClient.setCallback(callback);

  //初始化舵机
  myservo.attach(D2);
  myservo.write(90);

  pinMode(LED_BUILTIN, OUTPUT);
  analogWriteRange(2000);
  analogWrite(LED_BUILTIN, 2000);

  //蜂鸣器I/O口初始化
  pinMode(D8, OUTPUT);
  digitalWrite(D8, LOW);

  //指纹模块初始化
  finger.begin(57600);
  delay(5);
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    //while (1) { delay(1); }
  }

  Serial.println(F("Reading sensor parameters"));
  finger.getParameters();
  Serial.print(F("Status: 0x"));
  Serial.println(finger.status_reg, HEX);
  Serial.print(F("Sys ID: 0x"));
  Serial.println(finger.system_id, HEX);
  Serial.print(F("Capacity: "));
  Serial.println(finger.capacity);
  Serial.print(F("Security level: "));
  Serial.println(finger.security_level);
  Serial.print(F("Device address: "));
  Serial.println(finger.device_addr, HEX);
  Serial.print(F("Packet len: "));
  Serial.println(finger.packet_len);
  Serial.print(F("Baud rate: "));
  Serial.println(finger.baud_rate);

  finger.getTemplateCount();

  if (finger.templateCount == 0) {
    Serial.print("Sensor doesn't contain any fingerprint data. Please run the 'enroll' example.");
  } else {
    Serial.println("Waiting for valid finger...");
    Serial.print("Sensor contains ");
    Serial.print(finger.templateCount);
    Serial.println(" templates");
  }
}

//——————————————————————————————————————————————————————————————————————————
void loop() {
  //服务器心跳
  if (mqttClient.connected()) {  // 如果开发板成功连接服务器
    mqttClient.loop();           // 保持客户端心跳
  } else {                       // 如果开发板未能成功连接服务器
    connectMQTTServer();         // 则尝试连接服务器
  }

  //指纹模块心跳
  getFingerprintID();
  delay(1000);
}

//控制开门的两个函数——————————————————————————————————————————————————
void open_door() {
  analogWrite(LED_BUILTIN, 0);
  //正转
  myservo.write(0);   //正向最大速度
  delay(1400);        //持续时间
  myservo.write(90);  //停止

  //反转
  myservo.write(180);  //反向最大速度
  delay(1050);
  myservo.write(90);  //停止

  analogWrite(LED_BUILTIN, 2000);
}
//回正按钮
void rollback() {
  analogWrite(LED_BUILTIN, 0);

  myservo.write(0);  //正向最大速度
  delay(200);
  myservo.write(90);  //停止

  analogWrite(LED_BUILTIN, 2000);
}
//MQTT——————————————————————————————————————————————————————————————————————


void connectMQTTServer() {
  // 根据ESP8266的MAC地址生成客户端ID（避免与其它ESP8266的客户端ID重名）
  String clientId = "esp8266-" + WiFi.macAddress();
  // 连接MQTT服务器
  if (mqttClient.connect(clientId.c_str())) {  //设置mqtt主题的id
    //连接成功后就订阅主题
    mqttClient.subscribe(MySub);  //订阅主题
    Serial.print("订阅主题成功！！");
  } else {
    Serial.println(mqttClient.state());
    delay(3000);
  }
}

// ESP8266连接wifi——————————————————————————————————————————————————————————

void connectWifi() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi Connected!");
  Serial.println("");
}

//执行函数——————————————————————————————————————————————————————————————————

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("]\n");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  switch ((char)payload[0]) {
    case '1':
      Serial.print("开门");
      open_door();
      break;
    case '2':
      rollback();
      Serial.print("回正");
      break;
  }
}
//指纹相关————————————————————————————————————————————————————
uint8_t getFingerprintID() {
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println("No finger detected");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  // OK success!

  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  // OK converted!
  p = finger.fingerSearch();
  if (p == FINGERPRINT_OK) {
    Serial.println("Found a print match!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    Serial.println("Did not find a match");
    IdentfyNotPass();
    return p;
  } else {
    Serial.println("Unknown error");
    return p;
  }
  // found a match!
  Serial.print("Found ID #");
  Serial.print(finger.fingerID);
  Serial.print(" with confidence of ");
  Serial.println(finger.confidence);
  IdentfyPass();
  open_door();
  delay(5000);
  return finger.fingerID;
}

// returns -1 if failed, otherwise returns ID #
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK) return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK) return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK) return -1;

  // found a match!
  Serial.print("Found ID #");
  Serial.print(finger.fingerID);
  Serial.print(" with confidence of ");
  Serial.println(finger.confidence);
  return finger.fingerID;
}


//蜂鸣器函数————————————————————————————————————————————————————————————————————
void IdentfyPass() {
  digitalWrite(D8, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);             // wait for a second
  digitalWrite(D8, LOW);   // turn the LED off by making the voltage LOW
}

void IdentfyNotPass() {
  digitalWrite(D8, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(100);              // wait for a second
  digitalWrite(D8, LOW);   // turn the LED off by making the voltage LOW

  delay(100);

  digitalWrite(D8, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(100);              // wait for a second
  digitalWrite(D8, LOW);   // turn the LED off by making the voltage LOW

  delay(100);

  digitalWrite(D8, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(100);              // wait for a second
  digitalWrite(D8, LOW);   // turn the LED off by making the voltage LOW
}
