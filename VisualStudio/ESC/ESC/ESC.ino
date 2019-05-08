int DA1 = 3;
int DA2 = 5;
int DB1 = 6;
int DB2 = 9;
int DC1 = 10;
int DC2 = 11;
int POT = A0;

int phase = 1;

void setup() {

	Serial.begin(9600);

	pinMode(DA1, OUTPUT);
	pinMode(DA2, OUTPUT);
	pinMode(DB1, OUTPUT);
	pinMode(DB2, OUTPUT);
	pinMode(DC1, OUTPUT);
	pinMode(DC2, OUTPUT);
	pinMode(POT, INPUT);

}

void loop() {

	switch(phase) {
		case 1:
			digitalWrite(DA1, LOW);
			digitalWrite(DA2, LOW);
			digitalWrite(DB1, LOW);
			digitalWrite(DB2, HIGH);
			digitalWrite(DC1, HIGH);
			digitalWrite(DC2, LOW);
			break;

		case 2:
			digitalWrite(DA1, HIGH);
			digitalWrite(DA2, LOW);
			digitalWrite(DB1, LOW);
			digitalWrite(DB2, HIGH);
			digitalWrite(DC1, LOW);
			digitalWrite(DC2, LOW);
			break;

		case 3:
			digitalWrite(DA1, HIGH);
			digitalWrite(DA2, LOW);
			digitalWrite(DB1, LOW);
			digitalWrite(DB2, LOW);
			digitalWrite(DC1, LOW);
			digitalWrite(DC2, HIGH);
			break;

		case 4:
			digitalWrite(DA1, LOW);
			digitalWrite(DA2, LOW);
			digitalWrite(DB1, HIGH);
			digitalWrite(DB2, LOW);
			digitalWrite(DC1, LOW);
			digitalWrite(DC2, HIGH);
			break;

		case 5:
			digitalWrite(DA1, LOW);
			digitalWrite(DA2, HIGH);
			digitalWrite(DB1, HIGH);
			digitalWrite(DB2, LOW);
			digitalWrite(DC1, LOW);
			digitalWrite(DC2, LOW);
			break;

		case 6:
			digitalWrite(DA1, LOW);
			digitalWrite(DA2, HIGH);
			digitalWrite(DB1, LOW);
			digitalWrite(DB2, LOW);
			digitalWrite(DC1, HIGH);
			digitalWrite(DC2, LOW);
			break;
	}

	int v = analogRead(POT);
	Serial.println(v);
	int speed = map(v, 0, 1023, 250, 10);

	phase = phase + 1;
	if (phase > 6) phase = 1;
	delay(speed);

}
