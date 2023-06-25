#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Servo.h>

Servo myservo_close;//定义舵机
Servo myservo_open;//定义舵机

/*WIFI*/const char* ssid = "wifi410";
/*KEYS*/const char* password = "18661205519";
/*公网ip*/const char* mqttServer = "124.220.206.170";
/*订阅主题*/const char* MySub = "dormitory410";
 
WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);
const byte ledPin = BUILTIN_LED;

//——————————————————————————————————————————————————————————————————————————

void setup() {
     Serial.begin(9600);
     WiFi.mode(WIFI_STA);
     connectWifi();
     
     mqttClient.setServer(mqttServer, 1883);
     connectMQTTServer();
     mqttClient.setCallback(callback);
     
     pinMode(ledPin,OUTPUT);
     analogWriteRange(2000);
     
     // 初始化舵机
     myservo_close.attach(2);//舵机的IO口，nodemcu的D4口
     myservo_open.attach(0);//舵机的IO口，nodemcu的D3口
     myservo_close.write(90);//上电时舵机归零垂直
     myservo_open.write(90);//上电时舵机归零垂直
}

//——————————————————————————————————————————————————————————————————————————

void loop() { 
  if (mqttClient.connected()) { // 如果开发板成功连接服务器    
    mqttClient.loop();          // 保持客户端心跳
  } else {                  // 如果开发板未能成功连接服务器
    connectMQTTServer();    // 则尝试连接服务器
  }
}

//控制板载灯和宿舍灯的四个函数——————————————————————————————————————————————————

void LED_close()
{
  analogWrite(BUILTIN_LED,2000);
}

void LED_open()
{
  analogWrite(BUILTIN_LED,0);
}

void Light_close()
{
        myservo_close.write(140);//收到的指令后舵机旋转140
        delay(1000);//延时
        myservo_close.write(90);//舵机归零垂直
        myservo_close.write(40);//长按开关按键后舵机旋转40
        delay(1000);//延时
        myservo_close.write(90);//舵机归零垂直 
}


void Light_open()
{
        myservo_open.write(140);//收到的指令后舵机旋转140
        delay(1000);//延时
        myservo_open.write(90);//舵机归零垂直
        myservo_open.write(40);//长按开关按键后舵机旋转40
        delay(1000);//延时
        myservo_open.write(90);//舵机归零垂直  
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
    case '1':LED_open();
    break;
    case '2':LED_close(); 
    break;
    case '3':Light_open();  
    break;
    case '4':Light_close();  
    break;    
    }
    
//——————————————————————————————————————————————————————————————————————————
}
