int LDR_1 = A0; // select the input pin for LDR
int LDR_2 = A1;
int LDR_1Val = 0; // variable to store the value coming from the sensor
int LDR_2Val = 0;
int total = 0;
int buzzer = 8;
void setup() {
  Serial.begin(9600); //sets serial port for communication
  pinMode(buzzer, OUTPUT);
}
void loop() {
  LDR_1Val = analogRead(LDR_1); // read the value from the sensor
  LDR_2Val = analogRead(LDR_2);
  if(LDR_1Val>1010) {
    total++;
    if(total < 0){
       total = 0;
        }
    Serial.println(total);
    delay(2000);
    }
  if(LDR_2Val>1010) {
    total--;
    delay(2000);
    if(total < 0){
       total = 0;
        }
    Serial.println(total);
      }
      
  if(total > 5){
    tone(buzzer, 255, 1000);
  }
  if(total <= 5){
    tone(buzzer, 0, 1000);
  }  
}
