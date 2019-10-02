int sensorPin = A0; // select the input pin for ldr
int sensorValue = 0; // variable to store the value coming from the sensor
int i=0;
int d[32];
int temp=1;
int k=0; 
int add=0;
int mesg;

void setup()
{
  pinMode(13, OUTPUT); //pin connected to the relay
  Serial.begin(9600);
}

void loop()
{
  
  if (Serial.available()){
    Serial.println("The message to send is: ");
    mesg=Serial.parseInt();
    Serial.println(mesg);
    
    //Serial.println(sensorPin);
    int b;
    //Serial.println(Serial.available());
    while(mesg!=0)
    {
      b=mesg%2; //converts decimal to binary
      mesg=mesg/2;
      //Serial.println(b);
      //Serial.println(mesg);
      if(b==1)
      {
        digitalWrite(13,HIGH);
        delay(500);
        sensorValue=analogRead(sensorPin);
        d[i]=sensorValue; 
        Serial.println("Sending");
        //Serial.println(d[i]);
      }else {
        digitalWrite(13,LOW);
        delay(500);
        sensorValue=analogRead(sensorPin);
        d[i]=sensorValue;
        Serial.println("Sending");
        //Serial.println(d[i]);
      }
      i++;
    } 
    i--;
    
    Serial.println("The message was sent");
  
    // for converting binary to decimal
    while(i>=0)
    { 
      if(d[i]>=75 && d[i]<1005)
      {
        k=i;
        while(k!=0)
        {
          temp=temp*2;
          //Serial.println(temp);
          k--;
        }
        Serial.println("Recieving");
        delay(500);
        add=add+temp;
        //Serial.println(add);
        temp=1;
      }
      i--;
    }
    Serial.println("The message recieved is:"); // Final recieved value gets printed
    Serial.println(add);
    digitalWrite(13,LOW);
    Serial.end();
    Serial.begin(9600);
    //Serial.println(Serial.available());
  }
  
}
