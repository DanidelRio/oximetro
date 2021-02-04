// prueba para guardar archivos
// sensor, led rojo y led infrarrojo
int sensorPin = 0;
int period = 50;
int rawValue= 0;

void setup()
{
  pinMode(13, OUTPUT); //LED infrarrojo
  pinMode(12, OUTPUT); //LED rojo
  Serial.begin(9600);
  //Inaugura el puerto con una velocidad de 9600 baudios (bits por segundo)
  //para la transmición de datos en serie.
}

void loop()
{
  int i = 1;
  while(i<21){ //Ciclo de 20 iteraciones, 1 segundo
    if(i==1){
      digitalWrite(13, HIGH);
      digitalWrite(12, LOW);
      Serial.print(1); //Infrarrojo prendido
      Serial.print ("\n");
    }
    
    int rawValue = analogRead (sensorPin); //lee pin
    Serial.print (rawValue); //imprime valor de 0.05s
    Serial.print ("\n");
    i = i+1;
    delay (period);
  }
  
  while(i<41){//Otro ciclo de 20 iteraciones, 1 segundo
    if(i==21){
      digitalWrite(13, LOW);
      digitalWrite(12, HIGH);
      Serial.print(3); //Rojo prendido
      Serial.print ("\n");
    }

    int rawValue = analogRead (sensorPin);
    Serial.print (rawValue); //imprime valor cada 0.05s
    Serial.print ("\n");
    i = i+1;
    delay (period);
  }
}
