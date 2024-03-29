/*
 * --------------------------------------------------------------------------------------------------------------------
 * Example sketch/program showing how to read data from a PICC to serial.
 * --------------------------------------------------------------------------------------------------------------------
 * This is a MFRC522 library example; for further details and other examples see: https://github.com/miguelbalboa/rfid
 * 
 * Example sketch/program showing how to read data from a PICC (that is: a RFID Tag or Card) using a MFRC522 based RFID
 * Reader on the Arduino SPI interface.
 * 
 * When the Arduino and the MFRC522 module are connected (see the pin layout below), load this sketch into Arduino IDE
 * then verify/compile and upload it. To see the output: use Tools, Serial Monitor of the IDE (hit Ctrl+Shft+M). When
 * you present a PICC (that is: a RFID Tag or Card) at reading distance of the MFRC522 Reader/PCD, the serial output
 * will show the ID/UID, type and any data blocks it can read. Note: you may see "Timeout in communication" messages
 * when removing the PICC from reading distance too early.
 * 
 * If your reader supports it, this sketch/program will read all the PICCs presented (that is: multiple tag reading).
 * So if you stack two or more PICCs on top of each other and present them to the reader, it will first output all
 * details of the first and then the next PICC. Note that this may take some time as all data blocks are dumped, so
 * keep the PICCs at reading distance until complete.
 * 
 * @license Released into the public domain.
 * 
 * Typical pin layout used:
 * -----------------------------------------------------------------------------------------
 *             MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino
 *             Reader/PCD   Uno/101       Mega      Nano v3    Leonardo/Micro   Pro Micro
 * Signal      Pin          Pin           Pin       Pin        Pin              Pin
 * -----------------------------------------------------------------------------------------
 * RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST
 * SPI SS      SDA(SS)      10            53        D10        10               10
 * SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
 * SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
 * SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15
 */

#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN          10         // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

byte LecturaUID[4];
byte Usuario1[4]={0X86,0XFB,0X70,0X13};
byte Usuario2[4]={0X2C,0XEA,0XF1,0XC5};


void setup() {
  Serial.begin(9600);   // Initialize serial communications with the PC
  SPI.begin();      // Init SPI bus
  mfrc522.PCD_Init();   // Init MFRC522
  Serial.println("ready");
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
         if (comparaUID(LecturaUID,Usuario1))
          Serial.println("Welcome user 1");
         else if (comparaUID(LecturaUID,Usuario2))
          Serial.println("Welcome user 2");

          else 
          Serial.println("Denied Access");
         
         
         mfrc522.PICC_HaltA();

}

boolean comparaUID(byte lectura[],byte usuario[]){
  
         for (byte i=0; i<mfrc522.uid.size;i++){
                 if (lectura[i]!=usuario[i])
                 return(false);
                 
          }

          return(true);
 }
