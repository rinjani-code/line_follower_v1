//Untuk mengontrol motor driver
int in1 = 2;
int in2 = 3;
int in3 = 4;
int in4 = 5;

int ena = 6;
int enb = 9;

//variabel untuk mengontrol sensor
int sensor[] = {A1, A2, A3, A4, A5};
String data = "";
int kecepatan = 120;
void setup() {
  // put your setup code here, to run once:
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  for (int i = 0; i < 5; i++) {
    pinMode(sensor[i], INPUT);
  }
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(ena, kecepatan);
  analogWrite(enb, kecepatan);
  data = baca_sensor();
  Serial.println(data);
  if (data == "00000") {
    berhenti();
  }
  //  =========================== KONDISI MAJU =====================
  else if (data == "11011") {
    maju();
  }
  else if (data == "11010") {
    maju();
  }
  else if (data == "01010") {
    maju();
  }
  //  =========================== KONDISI BELOK KIRI ==================
  else if (data == "10011") {
    belok_kiri();
  }
  else if (data == "10111") {
    belok_kiri();
  }
  else if (data == "00111") {
    belok_kiri();
  }
  //  =========================== KONDISI BELOK KANAN ==================
  else if (data == "11001") {
    belok_kanan();
  }
  else if (data == "11101") {
    belok_kanan();
  }
  else if (data == "11100") {
    belok_kanan();
  }
  // ============================ SELAIN ITU ==================
  else{
    belok_kanan();
  }


}

String baca_sensor() {
  String data = "";
  for (int i = 0; i < 5; i++) {
    data = data + String(digitalRead(sensor[i]));
  }
  return data;
}

void mundur() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void maju() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void belok_kiri() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void belok_kanan() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void berhenti() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
