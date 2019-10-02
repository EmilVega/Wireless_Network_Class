
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         8          // Configurable, see typical pin layout above
#define SS_PIN          10         // Configurable, see typical pin layout above
#define Buzzer          3
MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

byte LecturaUID[4];
byte Usuario1[4]={0X86,0XFB,0X70,0X13};
byte Usuario2[4]={0X2C,0XEA,0XF1,0XC5};
int led1=4;
int led2=2;

void setup() {
  Serial.begin(9600);   // Initialize serial communications with the PC
  SPI.begin();      // Init SPI bus
  pinMode(Buzzer, OUTPUT); // Set buzzer pin to an Output pin
  digitalWrite(Buzzer, LOW); // Buzzer Off at startup
  mfrc522.PCD_Init();   // Init MFRC522
  Serial.println("ready");
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
 }

void loop() {
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
    return;
 
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
    return;
  
  Serial.print("UID:");
  for (byte i=0;i<mfrc522.uid.size;i++)
  {
    if (mfrc522.uid.uidByte[i]<0*10){
      Serial.print(" 0");
    }
    else {
      Serial.print(" ");
    }
              
    Serial.print(mfrc522.uid.uidByte[i],HEX);
    LecturaUID[i]=mfrc522.uid.uidByte[i];
  }
          
  Serial.print("\t");
  if (comparaUID(LecturaUID,Usuario1)){
    digitalWrite(led2,HIGH);
    delay(500);
    digitalWrite(led2,LOW);
    digitalWrite(led1,LOW);
    Serial.println("Welcome User 1");
                 
    for (int y = 0; y < 3; y++){
      digitalWrite (Buzzer, HIGH) ;// Buzzer On
      delay (50) ;// Delay 1ms 
      digitalWrite (Buzzer, LOW) ;// Buzzer Off
      delay (50) ;// delay 1ms
    }
    delay(1500);
  }else {
    digitalWrite(led1,HIGH);
    delay(500);
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    Serial.println("Denied Acces");
    for (int y = 0; y < 3; y++){
      digitalWrite (Buzzer, HIGH) ;// Buzzer On
      delay (300) ;// Delay 1ms 
      digitalWrite (Buzzer, LOW) ;// Buzzer Off
      delay (400) ;// delay 1ms
    }
    delay(1500);
   }
   mfrc522.PICC_HaltA();
}

boolean comparaUID(byte lectura[],byte usuario[]){
  
for (byte i=0; i<mfrc522.uid.size;i++){
  if (lectura[i]!=usuario[i])
    return(false);
  }
  return(true);
}
