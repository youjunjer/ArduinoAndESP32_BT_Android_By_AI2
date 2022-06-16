//This code will send BT string per second
#include <BluetoothSerial.h>
BluetoothSerial BT;

void setup()
{
  Serial.begin(115200);
  BT.begin("Your ESP32 BT Name");//請將這裡改成你喜歡的藍芽名稱
}

void loop()
{
  BT.println("Hello World");
  delay(1000);
}
