// second order low-pass Butterworth filter on an Arduino. 
// Note that there are many possible improvements to this code.

float x[] = {0,0,0};
float y[] = {0,0,0};
int k = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  // Señal de Prueba
  float t = micros()/1.0e6;
  x[0] = 10*sin(2*PI*2*t) + 1.5*sin(2*PI*450*t) + 3.5*sin(2*PI*120*t);

  // Señal Filtrada
  // (Filtro Butterworth de segundo orden)
  float b[] = {0.005, 0.005, 0.005};
  float a[] = {1.95558189, -0.95654717};
  y[0] = a[0]*y[1] + a[1]*y[2] +
               b[0]*x[0] + b[1]*x[1] + b[2]*x[2];

  if(k % 3 ==0)
  {
    // Esta condición extra se pone para reducir
    // la cantidad de veces que los datos se envian al serial port
    // esto debido a que transferir datos al serial port interfiere con la frecuencia de muestreo

    Serial.print(2*x[0]);
    Serial.print(" ");
    Serial.println(2*y[0]);
  }

  delay(15); // Espera 15ms
  for(int i = 1; i >= 0; i--){
    x[i+1] = x[i]; // guarda xi
    y[i+1] = y[i]; // guarda yi
  }
  
  k = k+1;
}
