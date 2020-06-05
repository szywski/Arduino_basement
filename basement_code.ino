

int L1green = 8; //pins where i connected diode. I dont need blue beacose i have got only two states.
int L1red = 10;
int tmeter = A1; //to measure voltage value i use analog pin
int fresistor = A2;

int temperature;
int light;

void setup() {
  
pinMode(8,OUTPUT);
pinMode(10,OUTPUT);
pinMode(tmeter,INPUT); 
pinMode(fresistor,INPUT);

Serial.begin(9600);

}
//p=photoresistor break value
bool isDark(int p){
if(p >=850) return 0;
  else return 1;
}
//p=Celsius deegres
bool isCold(int p){
if(p > 15) return 0;
  else return 1;

}
bool isOk(bool a, bool b){
if(a == true && b == true) return 1;
  else return 0;

}

void loop() {
  //procedure that convert voltage value of temperature sensor. In my case it wasnt LM35 but very similar
 float tmp = (((analogRead(tmeter)*5.0) / 1024)-0.5)*100;
 Serial.print("Termomether: ");
 Serial.println(tmp);
 Serial.print("Light: ");
 Serial.println(analogRead(fresistor));
  //voltage value of photoresistor
  int light = analogRead(fresistor);
  //a procedure that checks if condidtions are apropriate, ans light up LED green or red if something is wrong
  if(isOk(isCold(tmp),isDark(light)) == true){
    digitalWrite(L1green,HIGH);
    digitalWrite(L1red,LOW);
  }else{
    digitalWrite(L1green,LOW);
    digitalWrite(L1red,HIGH);
  }

}
