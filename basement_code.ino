

int L1green = 8;
int L1red = 10;
int tmeter = A1;
int fresistor = A2;

int temperature;
int light;

void setup() {
  // put your setup code here, to run once:
pinMode(8,OUTPUT);

pinMode(10,OUTPUT);
pinMode(tmeter,INPUT);
pinMode(fresistor,INPUT);

Serial.begin(9600);

}

bool isDark(int p){
if(p >=850) return 0;
  else return 1;

}
bool isCold(int p){
if(p > 15) return 0;
  else return 1;

}
bool isOk(bool a, bool b){
if(a == true && b == true) return 1;
  else return 0;

}

void loop() {
  
  float tmp = (((analogRead(tmeter)*5.0) / 1024)-0.5)*100;
  Serial.print("Termometr: ");
 Serial.println(tmp);
 Serial.print("Światełko: ");
 Serial.println(analogRead(fresistor));
  
  int light = analogRead(fresistor);
  
  if(isOk(isCold(tmp),isDark(light)) == true){
    digitalWrite(L1green,HIGH);
    digitalWrite(L1red,LOW);
  }else{
      digitalWrite(L1green,LOW);
    digitalWrite(L1red,HIGH);
  }

}
