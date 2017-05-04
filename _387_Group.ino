//allows the arduino to access the libraries
#include <Wire.h>
#include <Adafruit_MMA8451.h>
#include <Adafruit_Sensor.h>

Adafruit_MMA8451 mma = Adafruit_MMA8451();
#include <Servo.h>
//initializes the servo and other variables
Servo myservo;
double i;
int accel;
int led1=9,led2=10,led3=11,led4=12;
sensors_event_t event; 
void setup(void) {
  //assigns a mode to the digital pins
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  

  if (! mma.begin()) {
    while (1);
  }
  
  mma.setRange(MMA8451_RANGE_2_G);
  
  myservo.attach(8);
  myservo.write(85);
}
int pos=85;
//depending on the degree of the cup that is needed it 
//tells the servo to react a certain amount
void react(){
  switch(accel){
    case -39:
    case -38:
        myservo.write(60);
        break;
    case -37:
    case -36:
        myservo.write(61);
        break;
    case -35:
    case -34:
        myservo.write(62);
        break;
    case -33:
    case -32:
        myservo.write(63);
        break;
    case -31:
    case -30:
        myservo.write(64);
        break;
    case -29:
    case -28:
        myservo.write(65);
        break;
    case -27:
        myservo.write(66);
        break;
    case -26:
    case -25:
        myservo.write(67);
        break;
    case -24:
    case -23:
        myservo.write(68);
        break;
    case -22:
        myservo.write(69);
        break;
    case -21:
    case -20:
        myservo.write(70);
        break;
    case -19:
    case -18:
        myservo.write(71);
        break;
    case -17:
        myservo.write(72);
        break;
        
    case -16:
    case -15:
        myservo.write(73);
        break;
        
    case -14:
    
        myservo.write(74);
        break;
    case -13:
    
        myservo.write(75);
        break;
    case -12:
        myservo.write(76);
        break;
    case -11:
        myservo.write(77);
        break;
    case -10:
    case -9:
        myservo.write(78);
        break;
    case -8:
        myservo.write(79);
        break;
    case -7:
        myservo.write(80);
        break;
    
    case -6:
    case -5:
        myservo.write(81);
        break;
    
    case -4:
        myservo.write(82);
        break;
        
    case -3:
    case -2:
        myservo.write(83);
        break;
    
    case -1:
        myservo.write(84);
        break;
    case 0:
        myservo.write(85);
        break;
    case 1:
        myservo.write(86);
        break;
    
    case 2:
    case 3:
        myservo.write(87);
        break;
    case 4:
        myservo.write(88);
        break;
    
    case 5:
    case 6:
        myservo.write(89);
        break;
    
    case 7:
        myservo.write(90);
        break;
        
    case 8:
        myservo.write(91);
        break;
    
    case 9:
    case 10:
        myservo.write(92);
        break;
    case 11:
        myservo.write(93);
        break;
    case 12:
        myservo.write(94);
        break;
        
    case 13:
    case 14:
        myservo.write(95);
        break;
    
    case 15:
        myservo.write(96);
        break;
    
    case 16:
    case 17:
        myservo.write(97);
        break;
        
    case 18:
        myservo.write(98);
        break;
    
    case 19:
    case 20:
        myservo.write(99);
        break;
    case 21:
        myservo.write(100);
        break;
    case 22:
    case 23:
        myservo.write(101);
        break;
        
    case 24:
        myservo.write(102);
        break;
    
    case 25:
    case 26:
        myservo.write(103);
        break;
    
    case 27:
    case 28:
        myservo.write(104);
        break;
        
    case 29:
        myservo.write(105);
        break;
    
    case 30:
    case 31:
        myservo.write(106);
        break;
    case 32:
    case 33:
        myservo.write(107);
        break;
        
    case 34:
    case 35:
        myservo.write(108);
        break;
    
    case 36:
    case 37:
        myservo.write(109);
        break;
    
    case 38:    
    case 39:
        myservo.write(110);
        break;
        
    default:
      if(accel<0){
        myservo.write(65);
      }
      else{
        myservo.write(110);
      }
      break;
      
  }
  if(accel<0){
        accel=-accel;
  }
  //controls the LEDs so 
  //that when the acceleration is too much they all light up
  switch(accel/10){
    case 0:
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
      digitalWrite(led4,LOW);
      break;
    case 1:
      digitalWrite(led1,HIGH);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
      digitalWrite(led4,LOW);
      break;
    case 2:
      digitalWrite(led1,HIGH);
      digitalWrite(led2,HIGH);
      digitalWrite(led3,LOW);
      digitalWrite(led4,LOW);
      break;
    case 3:
      digitalWrite(led1,HIGH);
      digitalWrite(led2,HIGH);
      digitalWrite(led3,HIGH);
      digitalWrite(led4,LOW);
      break;
   default:
      digitalWrite(led1,HIGH);
      digitalWrite(led2,HIGH);
      digitalWrite(led3,HIGH);
      digitalWrite(led4,HIGH);
      break;
  }
  
  
}
//increases the magnitude of the acceleration
  void convert(){
    mma.read();
    mma.getEvent(&event);
    accel=event.acceleration.y*10;
  }
  
  


void loop() {
  // Read the 'raw' data in 14-bit counts
  convert();
  react();
  
  
}
