#include <DHT11.h>    //  온습도센서 라이브러리 불러옴
#include <SoftwareSerial.h> //  블루투스 라이브러리 불러옴
int pin=2;            //  Signal이 연결된 아두이노의 핀번호
int led=7;            //  led가 연결된 아두이노의 핀번호
DHT11 dht11(pin);     //  온습도센서 변수 선언
SoftwareSerial BTSerial(2, 3) //  블루투스센서 변수 선언
void setup() {
   Serial.begin(9600); //통신속도 설정
   BTSerial.begin(9600); // 블루투스 통신속도 설정
}

void loop() {
  int err;
  float temp, humi;
  if((err=dht11.read(humi, temp))==0) {//온도, 습도 읽어와서 표시
    Serial.print("temperature:");
    Serial.print(temp);
    Serial.print(" humidity:");
    Serial.print(humi);
    Serial.println();
    BTSerial.print("temperature:");
    BTSerial.print(temp);
    BTSerial.print(" humidity:");
    BTSerial.print(humi);
    BTSerial.println();
  }
  else {                               //에러일 경우 처리
    Serial.println();
    Serial.print("Error No :");
    Serial.print(err);
    Serial.println();
    BTSerial.println();
    BTSerial.print("Error No :");
    BTSerial.print(err);
    BTSerial.println();
  }
  delay(1000);                        //1초마다 측정
  if(BTSerial.read() == 0) {
    digitalWrite(led, LOW);
  }
  else if(BTSerial.read() == 1) {
    digitalWrite(led, HIGH);
  }
}
