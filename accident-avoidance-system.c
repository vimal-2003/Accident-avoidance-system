#define IR_SENSOR_PIN 2
#define BUZZER_PIN 3
void setup() {
  pinMode(IR_SENSOR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);  
}
void loop()
{
  int irValue = digitalRead(IR_SENSOR_PIN);
  int consecutiveDetections = 0;
  for (int i = 0; i < 3000 / 100; i++) {
    delay(100);  
    if (digitalRead(IR_SENSOR_PIN) == HIGH) {
      consecutiveDetections++;
    } else
    {
      consecutiveDetections = 0;
    }
    if (consecutiveDetections >= 30) {
      digitalWrite(BUZZER_PIN, HIGH); 
      delay(1000); 
      digitalWrite(BUZZER_PIN, LOW);  
      delay(1000);
      Serial.print("Sum of consecutive detections: ");
      Serial.println(consecutiveDetections);
      break;
    }
  }
  
} 
