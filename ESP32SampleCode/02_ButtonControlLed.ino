//這個程式將會對配對的裝置(Android)送出Button命令給ESP32，這些命令會使用字元'1','2','3'....等進行傳輸，ESP32則針對收到的文字來改變腳位狀態
//This code will receive button command from android, such as '1','2','3'... When ESP32 receive the command, it will change the state of pins.
// GPIO 15 -> GreenLED
// GPIO 2  -> YellowLED
// GPIO 4  -> RedLED
// GPIO 16 -> Other 
#include <BluetoothSerial.h>
BluetoothSerial SerialBT;

void setup(){
  Serial.begin(115200);
  SerialBT.begin("Your ESP32 BT Name");//請將這裡改成你喜歡的藍芽名稱
  pinMode(15,OUTPUT); //GreenLED
  pinMode(2,OUTPUT); //YellowLED
  pinMode(4,OUTPUT); //RedLED
  pinMode(16,OUTPUT); //Other(例如繼電器)
}

void loop(){
  //ESP32->Android
  if(Serial.available())  {
    String Sdata=Serial.readString();
    SerialBT.println(Sdata);
  } 
  //Android->ESP32
  if(SerialBT.available())  {
    Serial.println("");
    while(SerialBT.available())  {
      char btdata=SerialBT.read();
      if(btdata=='1') {digitalWrite(15,HIGH);}//Turn ON GreenLed
      if(btdata=='2') {digitalWrite(15,LOW);}//Turn OFF GreenLed
      if(btdata=='3') {digitalWrite(2,HIGH);}//Turn ON YellowLed
      if(btdata=='4') {digitalWrite(2,LOW);}//Turn OFF YellowLed
      if(btdata=='5') {digitalWrite(4,HIGH);}//Turn ON RedLed
      if(btdata=='6') {digitalWrite(4,LOW);}//Turn OFF RedLed
      if(btdata=='7') {digitalWrite(16,HIGH);}//Turn ON OtherDevice
      if(btdata=='8') {digitalWrite(16,LOW);}//Turn OFF OtherDevice
      Serial.print(btdata);
      }
  }  
  delay(1);
} 
