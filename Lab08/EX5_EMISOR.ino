
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9          // 'Configurable, see typical pin layout above'
#define SS_PIN          10         // 'Configurable, see typical pin layout above'

MFRC522 mfrc522(SS_PIN, RST_PIN);  // 'Create MFRC522 instance'

byte LecturaUID[4];
byte Usuario1[4]={0X86,0XFB,0X70,0X13};
byte Usuario2[4]={0X2C,0XEA,0XF1,0XC5};

void setup() {
  Serial.begin(9600);   // 'Initialize serial communications with the PC'
  SPI.begin();      // Init 'SPI bus'
  mfrc522.PCD_Init();   // 'Init MFRC522'
  }

void loop() {
  Serial.flush();
  // 'Look for new cards'
  if ( ! mfrc522.PICC_IsNewCardPresent())
    return;

  // 'Select one of the cards'
  if ( ! mfrc522.PICC_ReadCardSerial()) 
    return;

 // 'ALMACENA UID'
 for(byte i=0;i< mfrc522.uid.size;i++){
  LecturaUID[i]=mfrc522.uid.uidByte[i];
 }

 if(comparaUID(LecturaUID, Usuario1)){
  Serial.print("1");
 }else if(comparaUID(LecturaUID, Usuario2)){
  Serial.print("1");
 }else{
  Serial.print("0"); 
 }
    mfrc522.PICC_HaltA(); // 'DETIENE COM. CON CARD'
    delay(1000);
}

boolean comparaUID(byte lectura[], byte usuario[]){
  for(byte i=0;i< mfrc522.uid.size;i++){
  if(lectura[i]!=usuario[i])
    return(false);
  }
  return(true);
}
