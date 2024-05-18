// Definição dos pinos do extensor Arduino para controle dos motores
const int motor2A = 2; // Pino de controle da direção do Motor 1
const int motor1A = 3; // Pino de controle da direção do Motor 2
const int speedPin2 = 5; // Pino de controle da velocidade do Motor 1 (PWM)
const int speedPin1 = 6; // Pino de controle da velocidade do Motor 2 (PWM)

// Definição dos pinos de entrada do sensor de linha
const int sensorEsquerda = 8; // Pino do sensor de linha esquerdo
const int sensorDireita = 9; // Pino do sensor de linha direito

void setup() {
  // Configura os pinos dos motores como saída
  pinMode(motor1A, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(speedPin1, OUTPUT);
  pinMode(speedPin2, OUTPUT);
  
  // Configura os pinos dos sensores de luminosidade como entrada
  pinMode(sensorEsquerda, INPUT);
  pinMode(sensorDireita, INPUT);
  
  // Inicializa a comunicação serial
  // Serial.begin(9600);
}

void loop() {
  // Lê os valores dos sensores de luminosidade
  int valorSensorEsquerda = digitalRead(sensorEsquerda);
  int valorSensorDireita = digitalRead(sensorDireita);
  
  // Verifica a leitura dos sensores
  if (valorSensorEsquerda == HIGH && valorSensorDireita == HIGH) {
    // Ambos os sensores detectam a linha - seguir em frente
    digitalWrite(motor1A, HIGH);
    digitalWrite(motor2A, HIGH);
    // Defina a velocidade dos motores
    analogWrite(speedPin1, 120); // Defina a velocidade máxima do Motor 1
    analogWrite(speedPin2, 120); // Defina a velocidade máxima do Motor 2
  } else if (valorSensorEsquerda == HIGH && valorSensorDireita == LOW) {
    // Apenas o sensor esquerdo detecta a linha - vire à direita
    digitalWrite(motor1A, LOW);
    digitalWrite(motor2A, HIGH);
    // Defina a velocidade dos motores
    analogWrite(speedPin1, 150); // Defina uma velocidade menor para o Motor 1
    analogWrite(speedPin2, 150); // Defina uma velocidade menor para o Motor 2
  } else if (valorSensorEsquerda == LOW && valorSensorDireita == HIGH) {
    // Apenas o sensor direito detecta a linha - vire à esquerda
    digitalWrite(motor1A, HIGH);
    digitalWrite(motor2A, LOW);
    // Defina a velocidade dos motores
    analogWrite(speedPin1, 150); // Defina uma velocidade menor para o Motor 1
    analogWrite(speedPin2, 150); // Defina uma velocidade menor para o Motor 2
  }  else {
    // Ambos os sensores não detectam a linha - pare
    digitalWrite(motor1A, LOW);
    digitalWrite(motor2A, LOW);
    // Defina a velocidade dos motores para zero
    //analogWrite(speedPin1, 0); // Motor 1 parado
    //analogWrite(speedPin2, 0); // Motor 2 parado
  } 

  // Ajuste o atraso conforme necessário para controlar a velocidade do carrinho
 // delay(100);
}
