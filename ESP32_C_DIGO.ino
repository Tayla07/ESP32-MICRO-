// Projeto Curto Circuito – ESP32: Controle PWM de um LED

int led = 13;                // pino D13 do ESP32
int freq = 500;             // Frequência 500 Hz
int channel = 0;           // Canal 0 
int resolution = 8;        // Resolução 8 bits
int cap;

void setup() 
{
  Serial.begin(115200);    
  ledcSetup(channel, freq, resolution);
  ledcAttachPin(led, channel);

}
void loop() 
{
  cap = touchRead(T5);             // Sensor Capacitivo T0
  Serial.println(cap);            
  ledcWrite(channel, (cap)*10);  // Reduz a luminosidade do LED de acordo com o valor do sensor x10.
  delay(500);
 }
