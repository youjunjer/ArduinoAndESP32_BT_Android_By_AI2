// 這個程式將會對配對的裝置(Android)送出類比訊號給ESP32，這些命令會使用字串"25,32,255"三個逗號分隔，另外可以接收ESP32傳來的"32,25"兩筆資料，顯示在APP上
// 會使用到RGB全彩LED及DHT11，請先安裝SimpleDHT及ESP32 analogWrite程式庫
// GPIO 15 -> Blue pin of RGBLED 
// GPIO 2  -> Green pin of RGBLED 
// GPIO 0  -> GND pin of RGBLED 
// GPIO 4  -> Red pin of RGBLED 
// GPIO 16 -> Signal pin of DHT 11
// 3.3V    -> Vin pin of DHT11
// GND     -> GND pin of DHT11

#include <BluetoothSerial.h>
BluetoothSerial SerialBT;
//Setup DHT11
#include <SimpleDHT.h>
int pinDHT11 = 16;
SimpleDHT11 dht11(pinDHT11);
//送出溫濕度的時間間隔，由於藍芽必須即時接收，所以不使用delay
long BTLastPublishTime;//紀錄最後送出時間
long BTPublishInterval = 10000;//每10秒送出溫濕度一次
#include <analogWrite.h>

void setup() {
  Serial.begin(115200);
  SerialBT.begin("Your ESP32 BT Name");//請將這裡改成你喜歡的藍芽名稱
  pinMode(15,OUTPUT); //Blue pin of RGBLED 
  pinMode(2,OUTPUT); //Green pin of RGBLED 
  pinMode(4,OUTPUT); //Red pin of RGBLED
}

void loop() {
  //ESP32->Android
  if(Serial.available())  {
    String Sdata=Serial.readString();
    SerialBT.println(Sdata);
  } 
  //Android->ESP32
  if(SerialBT.available())  {    
    String btdata=SerialBT.readString();
    Serial.println(btdata);
    //以 ',' 逗號拆解文字
    String Red=getValue(btdata,',',0);
    String Green=getValue(btdata,',',1);
    String Blue=getValue(btdata,',',2);
    Serial.print("Green=" + Green);Serial.print(",Red=" + Red);Serial.println(",Blue=" + Blue);
    //用類比寫入腳位4,2,15
    analogWrite(4, Red.toInt());
    analogWrite(2, Green.toInt());
    analogWrite(15, Blue.toInt());
  }
  // Send DHT11 data to Android
  if ((millis() - BTLastPublishTime) >= BTPublishInterval ) {
    BTLastPublishTime = millis(); //更新最後傳輸時間
    byte temperature = 0; byte humidity = 0;
    int err = SimpleDHTErrSuccess;
    if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
      Serial.print("Read DHT11 failed, err="); Serial.print(SimpleDHTErrCode(err));
      Serial.print(","); Serial.println(SimpleDHTErrDuration(err)); delay(1000);
      return;
    }
    Serial.print((int)temperature); Serial.print(" *C, ");
    Serial.print((int)humidity); Serial.println(" H");
    String tempAndhumi=String(temperature)+ "," +String(humidity) ;
    SerialBT.println(tempAndhumi);  
  }
  delay(1);
}

//此副程式用來拆解','分隔的字串
String getValue(String data, char separator, int index){
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;
    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
