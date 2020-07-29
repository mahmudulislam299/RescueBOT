/* Mahmudul Islam
 * EEE,Bangladesh University of Engineering and Technology (BUET)
 * Email: mahmudulislam299@gmail.com
 */
 
#include <Servo.h>

Servo s1, s2, s3;

#define binA 2///back right
#define binB 3///back right
#define binC 4///back left
#define binD 5///back left
#define bena 6
#define benb 7

#define finA 24///front right
#define finB 26///front right
#define finC 28///front left
#define finD 30///front left
#define fena 32
#define fenb 34

int ch1 = 8; /// channel 1 to 8
int ch2 = 9; /// channel to 9
int ch3 = 10;
int ch4 = 11;

int v1, v2, v3, v4;
int s1p, s2p, s3p;
char q,p;


void setup() {
    void  fmtr_strt(); //forward motor intialization
    void  bmtr_strt(); //backward motor intialization
    pinMode(ch1, INPUT);
    pinMode(ch2, INPUT);
    pinMode(ch3, INPUT);
    pinMode(ch4, INPUT);
    Serial.begin(9600);
    s1.attach(14);
    s2.attach(15);
    s3.attach(16);
}

void loop() {
  rcfun();
  drive_bot(q);
  hand(p);
    }
    
void rcfun() {            //function for radio control remote
  v1 = pulseIn(ch1,INPUT);
  Serial.print("val1=");
  Serial.println(v1);
  v2 = pulseIn(ch2,INPUT);
   Serial.print("val2=");
  Serial.println(v2);
  v3 = pulseIn(ch3,INPUT);
  Serial.print("val3=");
  Serial.println(v3);
  v4 = pulseIn(ch4,INPUT);
  Serial.print("val4=");
  Serial.println(v4);
  delay(10);
  
  Serial.print("\n\n");
  /// SFBRLGIHJ XYUVMN 
  if( v1>16500 && v1<16900 && v2> 16500 && v2< 16900) {q= 'S';}
  else if(v1>16900 && v2> 16500 && v2< 16900) {q= 'F';}
  else if(v1<16500 && v2> 16500 && v2< 16900) {q= 'B';}
  else if(v1>16500 && v1< 16900 && v2> 16900) {q= 'R';}
  else if(v1>16500 && v1< 16900 && v2< 16500) {q= 'L';}


  if( v3>16500 && v3<16900 && v4> 16500 && v4< 16900) {p= 'O';}
  else if(v3>16900 && v4> 16500 && v4< 16900) {p= 'X';}
  else if(v3<16500 && v4> 16500 && v4< 16900) {p= 'Y';}
  else if(v3>16500 && v3< 16900 && v4> 16900) {p= 'M';}
  else if(v3>16500 && v3< 16900 && v4< 16500) {p= 'N';}

  
  Serial.println(q);
  Serial.println(p);
}

void fmtr_strt() //forward motor intialization
{
  pinMode(finA,OUTPUT);
  pinMode(finB,OUTPUT);
  pinMode(finC,OUTPUT);
  pinMode(finD,OUTPUT);
  pinMode(fena,OUTPUT);
  pinMode(fenb,OUTPUT);
  
  digitalWrite(finA,HIGH);
  digitalWrite(finB,HIGH);
  digitalWrite(finC,HIGH);
  digitalWrite(finD,HIGH);
}

void bmtr_strt() //backward motor intialization
{
  pinMode(binA,OUTPUT);
  pinMode(binB,OUTPUT);
  pinMode(binC,OUTPUT);
  pinMode(binD,OUTPUT);
  pinMode(bena,OUTPUT);
  pinMode(benb,OUTPUT);
  
  digitalWrite(binA,HIGH);
  digitalWrite(binB,HIGH);
  digitalWrite(binC,HIGH);
  digitalWrite(binD,HIGH);
}

void hand(char p){ //rescue bot hand control function
  if(p=='X')
  {
    s1.write(s1p);
    s1p++;
  }

  else if(p=='Y')
  {
    s1.write(s1p);
    s1p--;
  }

  else if(p=='U')
  {
    s2.write(s2p);
    s2p++;
  }

  else if(p=='W')
  {
    s2.write(s2p);
    s2p--;
  }

  else if(p=='M')
  {
    
  }

  else if(p=='N')
  {
    
  }
  
}


void drive_bot(char q){
  if(q=='F')
  {
    f_speed(150, 150);
    b_speed(150, 150);
  }

  else if(q=='B')
  {
    f_speed(-150, -150);
    b_speed(-150, -150);
  }

  if(q=='R')
  {
   f_speed(180, -180);
   b_speed(180, -180);
  }

  if(q=='L')
  {
   f_speed(-180, 180);
   b_speed(-180, 180);
  }

  if(q=='G')
  {
    f_speed(50, 180);
    b_speed(50, 180);
  }

  if(q=='I')
  {
    f_speed(180, 50);
    b_speed(180, 50);
  }

  if(q=='H')
  {
    f_speed(-50, -180);
    b_speed(-50, -180);
  }

  if(q=='J')
  {
    f_speed(-180, -50);
    b_speed(-180, -50);
  }

  if(q=='S')
  {
    f_speed(0,0);
    b_speed(0,0);
  }
}



void f_speed(int flm, int frm)       
{
 if(flm==0)                 
  {
    digitalWrite(finC,HIGH);
    digitalWrite(finD,HIGH);
  }
  if(flm>0)
  {
    digitalWrite(finC,HIGH);        
    digitalWrite(finD,LOW);
  }
  else if(flm<0)
  {
    digitalWrite(finC,LOW);          
    digitalWrite(finD,HIGH);
  }


  if(frm==0)
  {
    digitalWrite(finA,HIGH);
    digitalWrite(finB,HIGH);
  }
  if(frm>0)
  {
    digitalWrite(finA,HIGH);
    digitalWrite(finB,LOW);
  }
  else if(frm<0)
  {
    digitalWrite(finA,LOW);
    digitalWrite(finB,HIGH);
  }
  if(flm>254) flm=254;                
  if(flm<-254) flm=-254;
  if(frm>254) frm=254;
  if(frm<-254) frm=-254;
  
  analogWrite(fena,abs(frm));         
  analogWrite(fenb,abs(flm));         
  
}

void b_speed(int blm, int brm)       
{
 if(blm==0)                 
  {
    digitalWrite(binC,HIGH);
    digitalWrite(binD,HIGH);
  }
  if(blm>0)
  {
    digitalWrite(binC,HIGH);        
    digitalWrite(binD,LOW);
  }
  else if(blm<0)
  {
    digitalWrite(binC,LOW);          
    digitalWrite(binD,HIGH);
  }


  if(brm==0)
  {
    digitalWrite(binA,HIGH);
    digitalWrite(binB,HIGH);
  }
  if(brm>0)
  {
    digitalWrite(binA,HIGH);
    digitalWrite(binB,LOW);
  }
  else if(brm<0)
  {
    digitalWrite(binA,LOW);
    digitalWrite(binB,HIGH);
  }
  if(blm>254) blm=254;                
  if(blm<-254) blm=-254;
  if(brm>254) brm=254;
  if(brm<-254) brm=-254;
  
  analogWrite(bena,abs(brm));         
  analogWrite(benb,abs(blm));         
  
}
