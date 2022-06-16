//這個程式將可以讓ESP32與Android進行雙向對話，請使用Terminal功能進行測試。
//This code let you make text conversation between ESP32 and Android, please use APP Terminal function.
#include <BluetoothSerial.h>
BluetoothSerial SerialBT;

void setup(){
  Serial.begin(115200);
  SerialBT.begin("Your ESP32 BT Name");//請將這裡改成你喜歡的藍芽名稱
}

void loop(){
  //ESP32->Android
  if(Serial.available())  {
    String data=Serial.readString();
    SerialBT.println(data);
  } 
  //Android->ESP32
  if(SerialBT.available())  {
    String data=SerialBT.readString();
    Serial.println(data);
  }
  delay(1); 
}
