#define Rpin 2
#define Gpin 5
#define Bpin 21
#define ANALOGPIN 13
#define Button 25

int PWM_FREQUENCY = 1000;
int PWM_CHANEL_R = 0;
int PWM_CHANEL_G = 1;
int PWM_CHANEL_B = 2;
int PWM_RESQUTION = 8;
int valueAnalogA0 = 0;
int ButtonState = 0;
int number = 0;
int state = 1;

void setup() {
  
  Serial.begin(115200);

  pinMode(Rpin, OUTPUT);
  pinMode(Bpin, OUTPUT);
  pinMode(Gpin, OUTPUT);
  pinMode(Button, INPUT);

  ledcSetup(PWM_CHANEL_R, PWM_FREQUENCY, PWM_RESQUTION);
  ledcAttachPin(Rpin, PWM_CHANEL_R);

  ledcSetup(PWM_CHANEL_G, PWM_FREQUENCY, PWM_RESQUTION);
  ledcAttachPin(Gpin, PWM_CHANEL_G);

  ledcSetup(PWM_CHANEL_B, PWM_FREQUENCY, PWM_RESQUTION);
  ledcAttachPin(Bpin, PWM_CHANEL_B);
  
}

void loop() {

  valueAnalogA0 = analogRead(ANALOGPIN);
  ButtonState = digitalRead(Button);

  if(ButtonState == 0){

    if(state == 1){
      Serial.println("RED");
      ledcWrite(PWM_CHANEL_R, 255);
      number = 1;
      state++;
    }
    else if(state == 2){
      Serial.println("GREEN");
      ledcWrite(PWM_CHANEL_G, 255);
      number = 2;
      state++;
    }
    else if(state == 3){
      Serial.println("BLUE");
      ledcWrite(PWM_CHANEL_B, 255);
      number = 3;
      state = state - 2;
    }
    delay(200);

  }

  if(ButtonState == 1){
    if(number == 1){
      ledcWrite(PWM_CHANEL_R, map(valueAnalogA0, 0, 4095, 255, 0));
      Serial.println(valueAnalogA0);
    }
    else if(number == 2){
      ledcWrite(PWM_CHANEL_G, map(valueAnalogA0, 0, 4095, 255, 0));
      Serial.println(valueAnalogA0);
    }
    else if(number == 3){
      ledcWrite(PWM_CHANEL_B, map(valueAnalogA0, 0, 4095, 255, 0));
      Serial.println(valueAnalogA0);
    }
    delay(100);
  }

  //ledcWrite(PWM_CHANEL_R, map(valueAnalogA0, 0, 4095, 0, 255));
  //ledcWrite(PWM_CHANEL_G, map(valueAnalogA0, 0, 4095, 0, 255));
  //ledcWrite(PWM_CHANEL_B, map(valueAnalogA0, 0, 4095, 0, 255));

  //Serial.println(valueAnalogA0);
  //delay(200);
  
}
