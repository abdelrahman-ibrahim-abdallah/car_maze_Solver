const int in1 = 9;

const int in2 = 8;

const int in3 = 4;

const int in4 = 3;

const int enA = 5;

const int enB = 6;

#define PWM 200

int trigger_front = A0;
int echo_front = A1;

int trigger_left = A2;
int echo_left = A3;

int trigger_right = A4;
int echo_right = A5;


void setup() {
  // put your setup code here, to run once:
  pinMode(in1,OUTPUT);   //left motors forward
  pinMode(in2,OUTPUT);   //left motors reverse
  pinMode(enA, OUTPUT);

  pinMode(in3,OUTPUT);   //right motors forward
  pinMode(in4,OUTPUT);   //rignt motors reverse
  pinMode(enB, OUTPUT);

  pinMode(trigger_front,OUTPUT);
  pinMode(echo_front,INPUT);

  pinMode(trigger_left,OUTPUT);
  pinMode(echo_left,INPUT);

  pinMode(trigger_right,OUTPUT);
  pinMode(echo_right,INPUT);
  
  analogWrite(enA, 200);
  analogWrite(enB, 88);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.begin(9600);
  long duration_front, distance_front, duration_left, distance_left, duration_right, distance_right;
    
  //Calculating distance
  
  digitalWrite(trigger_front, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger_front, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_front, LOW);
  duration_front = pulseIn(echo_front, HIGH);
  distance_front= duration_front*0.034/2;

  digitalWrite(trigger_left, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger_left, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_left, LOW);
  duration_left = pulseIn(echo_left, HIGH);
  distance_left= duration_left*0.034/2;

  digitalWrite(trigger_right, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger_right, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_right, LOW);
  duration_right = pulseIn(echo_right, HIGH);
  distance_right= duration_right*0.034/2;

  Serial.print("front = ");
  Serial.println(distance_front);
  Serial.print("Left = ");
  Serial.println(distance_left);
  Serial.print("Right = ");
  Serial.println(distance_right);  
  delay(50);


  if (distance_front >20){

    forward();
    
    if(distance_left > 10&& distance_left<20){
      forward();
    }
    if(distance_left >=20){
       left();
       delay(30);
       forward();
    }
    if(distance_left<10 && distance_left>0){
      right();
      delay(30);
      forward();
    }
 } 
  
  if(distance_front<=20&& distance_right > 20){
    Stop();
    delay(1000);
    right();
    delay(400);
    
  }

  if(distance_front<=20 && distance_right<20){
    Stop();
    delay(1000);
    right();
    delay(800);
   
  }
  
  
}

void forward()
{
  digitalWrite(in1,1);
  digitalWrite(in2,1);
  digitalWrite(in3,1);
  digitalWrite(in4,1);
  delay(1000);
}


void right(){
  digitalWrite(in1,1);
  digitalWrite(in2,0);
  digitalWrite(in3,0);
  digitalWrite(in4,1);
 delay(10);
}


void left(){
  digitalWrite(in1,0);
  digitalWrite(in2,1);
  digitalWrite(in3,1);
  digitalWrite(in4,0);
  delay(10);
}



void Stop(){
  digitalWrite(in1,0);
  digitalWrite(in2,0);
  digitalWrite(in3,0);
  digitalWrite(in4,0);
  delay(300);
}
