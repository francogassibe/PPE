#define BLYNK_PRINT Serial

#include <Servo.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).

// Your WiFi credentials.//////////////////
// Set password to "" for open networks.

static int  mode=0;
char ssid[] = "irdl-hs";
char pass[] = "IRDL#HS#Pw!";
char auth[] = "vREgsVJtksIoVoqGkF5FUZ2bxcroR1mP";
Servo servos[3];


void setServo1(int degrees) //Bouger le servo1 
  {
    Serial.print("Servo 1");//Verifier
    Serial.println(degrees);//Verifier
    servos[0].write((degrees ) % 180);
  }

void setServo2(int degrees) 
  {
    servos[1].write((degrees ) % 180);
  }
  
void setServo3(int degrees) 
  {
    servos[2].write((degrees ) % 180);
  }
  
  
 BLYNK_WRITE(V0)//Recuperer la valeur de V0 
   {
    int motor1=param.asInt();
    setServo1(motor1);
   }
   
BLYNK_WRITE(V1)
   {
    int motor2=param.asInt();
    setServo2(motor2);
   }    

BLYNK_WRITE(V2)
   {
    int motor3=param.asInt();
    setServo3(motor3);
   }

    
BLYNK_WRITE(V3)
   {
    
    int val3=param.asInt();
    Serial.println("dans V3");//Verifier
    Serial.print("val=");//Verifier
    Serial.println(val3);//Verifier
    Serial.print("mode=");//Verifier
    Serial.println(mode);//Verifier
    
    if((mode != 10000) && (val3==1)) //verification de conditions pour la machine d'etat
     {
      mode=mode+val3;//passer a l'etat suivant
      Serial.print("V3 mode =");
      Serial.println(mode);
     }
     
   }

   
BLYNK_WRITE(V4)
   {
    
    int val4=param.asInt();
    if (val4==1)//Verifier
      {
       mode=1;//retourner a l'atat 1
      }
      
    Serial.print("V4 mode =");//Verifier
    Serial.println(mode);//Verifier
    
   }

   
BLYNK_WRITE(V5)
   {
    int val5=param.asInt();
    if (val5==1)
      {
       mode=10000;//etat manuele
       Serial.print("V5 mode =");
       Serial.println(mode);
      }
    
   }

void pos(int i)
  {
  switch(i){
    case(1):{
      Serial.println("Je bouge en Pos 1");//Verifier
      setServo1(0);
      setServo2(0);
      setServo3(90);
      break;
      }
    case(2):{
      setServo1(0);
      setServo2(0);
      setServo3(90+88,15);
      break;
      }
    case(3):{
      setServo1(0);
      setServo2(0);
      setServo3(90-88,15);
      break;
      }
    case(4):{
      setServo1(0);
      setServo2(180);
      setServo3(90);
      break;
      }
    case(5):{
      setServo1(180);
      setServo2(180);
      setServo3(90);
      break;
      }
    case(6):{
      setServo1(180);
      setServo2(0);
      setServo3(90);
      break;
      }
    case(7):{
      setServo1(90);
      setServo2(0);
      setServo3(90);
      break;
      }
    case(8):{
      setServo1(0);
      setServo2(0);
      setServo3(90);
      break;
      }
    case(9):{
      setServo1(270);
      setServo2(0);
      setServo3(90);
      break;
      }
    case(10):{
      setServo1(270);
      setServo2(0);
      setServo3(90);
      break;
      }
    case(11):{
      setServo1(180);
      setServo2(0);
      setServo3(90);
      break;
      }
    case(12):{
      setServo1(270);
      setServo2(0);
      setServo3(90);
      break;
      }
    case(13):{
      setServo1(0);
      setServo2(0);
      setServo3(90);
      break;
      }
    
    }
  
  
  }





void setup()
  {
  
   // Debug console
   Serial.begin(115200);
   servos[0].attach(13);
   servos[1].attach(12);
   servos[2].attach(14);

   // Blynk.begin(auth, ssid, pass);
   //Blynk.begin(auth, IPAddress(xxx,xxx,xxx,xxx), 8080);
   Blynk.begin(auth, ssid, pass, IPAddress(10,3,141,1), 8080);
  }
  

void loop()
{
  Blynk.run();

 //delay(50);
 //Serial.println("loop");

 switch (mode)
 {
  case(0):
  {
    //il fait rien ici
    break;
  }
 
   case(1):
   {
    Serial.println("bouge pos 1");//Verifier
    pos(1);
    break;
   }
  case(2):
  {
   pos(2);
   break;
  }
  case(3):
  {
   pos(3);
   break;
  }
  case(4):
  {
   pos(4);
   break;
  }case(5):
  {
   pos(5);
   break;
  }case(6):
  {
   pos(6);
   break;
  }case(7):
  {
   pos(7);
   break;
  }case(8):
  {
   pos(8);
   break;
  }case(9):
  {
   pos(9);
   break;
  }case(10):
  {
   pos(10);
   break;
  }case(11):
  {
   pos(11);
   break;
  }case(12):
  {
   pos(12);
   break;
  }case(13):
  {
   pos(13);
   break;
  }
  case(10000):
  {
    BLYNK_WRITE(V0);
    BLYNK_WRITE(V1);
    BLYNK_WRITE(V2);
    break;  
  }

 }
  
}





    
