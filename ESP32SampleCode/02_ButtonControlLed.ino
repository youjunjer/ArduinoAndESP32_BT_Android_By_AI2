//這個程式將會對配對的裝置(Android)送出Button命令給ESP32，這些命令會使用文元'1','2','3'....等進行傳輸，ESP32則針對收到的文字來改變腳位狀態
//This code will receive button command from android, such as '1','2','3'... When ESP32 receive the command, it will change the state of pins.
#include <BluetoothSerial.h>
BluetoothSerial SerialBT;

void setup(){
  Serial.begin(115200);
  SerialBT.begin("Your ESP32 BT Name");//請將這裡改成你喜歡的藍芽名稱
  pinMode(15,OUTPUT); //綠色LED
  pinMode(2,OUTPUT); //黃色LED
  pinMode(4,OUTPUT); //紅色LED
  pinMode(13,OUTPUT); //其他裝置(例如繼電器)
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
      if(btdata=='1') {digitalWrite(15,HIGH);}//開綠燈
      if(btdata=='2') {digitalWrite(15,LOW);}//關綠燈
      if(btdata=='3') {digitalWrite(2,HIGH);}//開黃燈
      if(btdata=='4') {digitalWrite(2,LOW);}//關黃燈
      if(btdata=='5') {digitalWrite(4,HIGH);}//開紅燈
      if(btdata=='6') {digitalWrite(4,LOW);}//關紅燈
      if(btdata=='7') {digitalWrite(13,HIGH);}//開裝置
      if(btdata=='8') {digitalWrite(13,LOW);}//關裝置
      Serial.print(btdata);
  }  
  delay(1);
}
