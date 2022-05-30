// Выводы управления 2-м мотором
#define PIN_IN3 14
#define PIN_IN4 15
#define PIN_ENB 16

// Переменная для регулировки скорости вращения моторов
uint8_t SPEED = 100;
// Переменная общего состояния системы
uint8_t STATE = 0;

void setup() {
  // Настройка всех пинов в качестве выхода

  pinMode(PIN_IN3, OUTPUT);
  pinMode(PIN_IN4, OUTPUT);
  pinMode(PIN_ENB, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite(12, LOW);
}

void loop() {

  analogWrite(PIN_ENB, SPEED);
  // Вращение мотор редукторов в одну сторону с постепенным наращиванием скорости
  if(STATE == 0) {
    SPEED += 17;
    if(SPEED == 255) STATE = 1;
  
    digitalWrite(PIN_IN3, HIGH);
    digitalWrite(PIN_IN4, LOW);
    delay(500);
  }
  // Вращение моторов на максимальной скорости 5 секунд
  else if(STATE == 1) {
    delay(5000);
    STATE = 2;
  }
  // Вращение мотор редукторов в противоположную сторону с постепенным уменьшением скорости
  else if(STATE == 2) {
    SPEED -= 17;
    if(SPEED == 0) STATE = 3;

    digitalWrite(PIN_IN3, LOW);
    digitalWrite(PIN_IN4, HIGH);
    delay(500);
  }
  // Остановка моторов на 5 секунд
  else if(STATE == 3) {
    delay(5000);
    STATE = 0;
  }
}
