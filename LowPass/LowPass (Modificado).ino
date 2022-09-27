float xn1 = 0;
float yn1 = 0;
int k = 0;

void setup(){
  Serial.begin(115200);
}

void loop(){
  //Señal de Prueba
  float t = micros()/1.0e6;
  float xn = 5*sin(2*PI*2*t) + sin(2*PI*120*t);

  //Señal filtrada
  float yn = 0.969*yn1 + 0.035*xn + 0.035*xn1;

  delay(20);
  xn1 = xn;
  yn1 = yn;

  if(k % 3 == 0){
    //Salida
    Serial.print(2*xn);
    Serial.print(" ");
    Serial.println(2*yn);
  }
  k = k+1;
}