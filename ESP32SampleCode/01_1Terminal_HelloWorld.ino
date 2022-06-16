//這個程式將會對配對的裝置(Android)傳送藍芽訊息一秒一次，請使用APP的Terminal 功能接收ESP32的訊息
//This code will send BT string per second to Android, please use APP Terminal function to receive ESP32 message
#include <BluetoothSerial.h>
BluetoothSerial SerialBT;

void setup(){
  Serial.begin(115200);
  SerialBT.begin("Your ESP32 BT Name");//請將這裡改成你喜歡的藍芽名稱
}

void loop(){
  SerialBT.println("Hello World");
  delay(1000);
}
