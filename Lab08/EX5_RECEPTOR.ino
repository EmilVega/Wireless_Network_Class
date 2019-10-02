// 'Declaration of global variables '
const int LED1 =13; // 'CORRECTO'
const int LED2 =12; // 'INCORRECTO'

int inByte = 0; // 'RECIBE ORDEN DE OTRO ARDUINO'

void setup(){
  Serial.begin(9600);
  pinMode(LED1,OUTPUT); // 'establecer que el pin digital es una señal de salida'
  pinMode(LED2,OUTPUT); // 'establecer que el pin digital es una señal de salida'
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
}

void loop(){
  Serial.flush();
  // 'RECIBE ORDEN DEL OTRO ARDUINO'
  if(Serial.available()>0){
    inByte=Serial.read();
    if(inByte=='1'){ // 'USUARIO ACEPTADO'
      digitalWrite(LED1,HIGH);
      delay(1000);
      digitalWrite(LED1,LOW);
    }
    else if(inByte=='0'){ // 'USUARIO DENEGADO'
      digitalWrite(LED2,HIGH);
      delay(1000);
      digitalWrite(LED2,LOW);
    }
  }
  delay(1000);
}
