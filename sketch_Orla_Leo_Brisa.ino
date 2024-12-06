#define PULSADOR 2

byte numero[10][8] = {
  {1, 1, 1, 1, 1, 1, 0, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1, 0}, // 2
  {1, 1, 1, 1, 0, 0, 1, 0}, // 3
  {0, 1, 1, 0, 0, 1, 1, 0}, // 4
  {1, 0, 1, 1, 0, 1, 1, 0}, // 5
  {1, 0, 1, 1, 1, 1, 1, 0}, // 6
  {1, 1, 1, 0, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1, 0}, // 8
  {1, 1, 1, 0, 0, 1, 1, 0}  // 9
};

bool detenido = false; 
int ultimoNumero = 0;  
unsigned long tiempoAnterior = 0; 
const int intervalo = 50; 

void setup() {
  Serial.begin(9600);
  for (int i = 3; i < 10; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(PULSADOR, INPUT);
  randomSeed(analogRead(A0));
}

void loop() {
  int valorPulsador = digitalRead(PULSADOR);


  if (valorPulsador == HIGH) {
    detenido = !detenido;
    delay(300);
  }
  if (!detenido) {
    if (millis() - tiempoAnterior > intervalo) {
      tiempoAnterior = millis();
      ultimoNumero = random(1, 7);
      for (int e = 0; e < 8; e++) {
        digitalWrite(e + 3, numero[ultimoNumero][e]);
      }
    }
  } else {
    //para que muestre el ultimo numero jeee
    for (int e = 0; e < 8; e++) {
      digitalWrite(e + 3, numero[ultimoNumero][e]);
    }
  }
}
