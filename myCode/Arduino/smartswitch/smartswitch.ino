#define BLINKER_WIFI
#define BLINKER_MIOT_LIGHT

#include <Blinker.h>
#include <Servo.h>

Servo myservo;//定义舵机

char auth[] = "6e3a1495d33e";  //点灯Key
char ssid[] = "Redmi K50 Pro GSP";      //wifi名称
char pswd[] = "514IchbinDu";     //wifi密码

// 新建组件对象
BlinkerButton Button1("test");


int servo_max=180;
int servo_close=0;  


int counter = 0;

void miotPowerState(const String & state)//电源类操作
{
}

// 按下按键即会执行该函数
void button1_callback(const String & state)
{
    BLINKER_LOG("get button state: ", state);
    if (state=="on") 
    {
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
}
}
// 如果未绑定的组件被触发，则会执行其中内容
void dataRead(const String & data)
{
    BLINKER_LOG("Blinker readString: ", data);
    counter++;
 
}

void setup()
{
    // 初始化串口
    Serial.begin(115200);
    BLINKER_DEBUG.stream(Serial);

    // 初始化舵机
    myservo.attach(2);//舵机的IO口，nodemcu的D4口
    myservo.write(0);//上电时舵机归零垂直
    BlinkerMIOT.attachPowerState(miotPowerState);
  
    // 初始化blinker
    Blinker.begin(auth, ssid, pswd);
    Blinker.attachData(dataRead);

    pinMode(LED_BUILTIN, OUTPUT);
    analogWriteRange(2000);
    analogWrite(LED_BUILTIN, 2000 );
}

void loop() {
    Blinker.run();
}
