#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Servo.h>

Servo myservo;//定义舵机


int servo_max=180;
int servo_close=0;  


/*WIFI*/const char* ssid = "wifi410";
/*KEYS*/const char* password = "18661205519";
/*公网ip*/const char* mqttServer = "124.220.206.170";
/*订阅主题*/const char* MySub = "dormitory410";
 
WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);
const byte ledPin = BUILTIN_LED;

//——————————————————————————————————————————————————————————————————————————

void setup() {
     Serial.begin(115200);
     WiFi.mode(WIFI_STA);
     connectWifi();
     
     mqttClient.setServer(mqttServer, 1883);
     connectMQTTServer();
     mqttClient.setCallback(callback);
     
     // 初始化舵机
      myservo.attach(D2);
      myservo.write(90);
  
      pinMode(LED_BUILTIN, OUTPUT);
      analogWriteRange(2000);
      analogWrite(LED_BUILTIN, 2000 );
}

//——————————————————————————————————————————————————————————————————————————

void loop() { 
  if (mqttClient.connected()) { // 如果开发板成功连接服务器    
    mqttClient.loop();          // 保持客户端心跳
  } else {                  // 如果开发板未能成功连接服务器
    connectMQTTServer();    // 则尝试连接服务器
  }
}

//控制开门的两个函数——————————————————————————————————————————————————
void open_door() { 
  analogWrite(LED_BUILTIN, 2000 );
  /*
    analogWrite(LED_BUILTIN, 0 );  
    //正转
    myservo.write(0);//正向最大速度
    delay(1400);//持续时间
    myservo.write(90);//停止

    //反转
    myservo.write(180);//反向最大速度
    delay(1100);
    myservo.write(90);//停止

    //回正
    BLINKER_LOG("get button state: ", servo_max);
    myservo.write(0);//正向最大速度回正
    delay(100);
    BLINKER_LOG("get button state: ", servo_close);
    myservo.write(90);//停止
    analogWrite(LED_BUILTIN, 2000 ); 
   */
}
//回正按钮
void rollback() {  
  analogWrite(LED_BUILTIN, 0 );
    /*
    analogWrite(LED_BUILTIN, 0 );
    myservo.write(0);//正向最大速度
    delay(200);
    myservo.write(90);//停止
    analogWrite(LED_BUILTIN, 2000 ); 
    */
}
//MQTT——————————————————————————————————————————————————————————————————————

 
void connectMQTTServer(){
  // 根据ESP8266的MAC地址生成客户端ID（避免与其它ESP8266的客户端ID重名）
  String clientId = "esp8266-" + WiFi.macAddress();
  // 连接MQTT服务器
  if (mqttClient.connect(clientId.c_str())) { //设置mqtt主题的id
    //连接成功后就订阅主题
    mqttClient.subscribe(MySub);//订阅主题
    Serial.print("订阅主题成功！！");
  } else {
    Serial.println(mqttClient.state());
    delay(3000);
  }   
}
 
// ESP8266连接wifi——————————————————————————————————————————————————————————

void connectWifi(){
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

  switch((char)payload[0])
  {
    case '5':open_door();
    break;
    case '6':rollback(); 
    break;
    }
    
//——————————————————————————————————————————————————————————————————————————
}
