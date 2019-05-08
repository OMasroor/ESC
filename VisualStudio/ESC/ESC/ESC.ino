int driverA1_o = 3;
int driverA2_o = 5;
int driverB1_o = 6;
int driverB2_o = 9;
int driverC1_o = 10;
int driverC2_o = 11;
int pot_i = A0;

int phase = 1;

void setup() {

	Serial.begin(9600);

	pinMode(driverA1_o, OUTPUT);
	pinMode(driverA2_o, OUTPUT);
	pinMode(driverB1_o, OUTPUT);
	pinMode(driverB2_o, OUTPUT);
	pinMode(driverC1_o, OUTPUT);
	pinMode(driverC2_o, OUTPUT);
	pinMode(pot_i, INPUT);

}

void loop() {

	switch(phase) {
		case 1:
			digitalWrite(driverA1_o, LOW);
			digitalWrite(driverA2_o, LOW);
			digitalWrite(driverB1_o, LOW);
			digitalWrite(driverB2_o, HIGH);
			digitalWrite(driverC1_o, HIGH);
			digitalWrite(driverC2_o, LOW);
			break;

		case 2:
			digitalWrite(driverA1_o, HIGH);
			digitalWrite(driverA2_o, LOW);
			digitalWrite(driverB1_o, LOW);
			digitalWrite(driverB2_o, HIGH);
			digitalWrite(driverC1_o, LOW);
			digitalWrite(driverC2_o, LOW);
			break;

		case 3:
			digitalWrite(driverA1_o, HIGH);
			digitalWrite(driverA2_o, LOW);
			digitalWrite(driverB1_o, LOW);
			digitalWrite(driverB2_o, LOW);
			digitalWrite(driverC1_o, LOW);
			digitalWrite(driverC2_o, HIGH);
			break;

		case 4:
			digitalWrite(driverA1_o, LOW);
			digitalWrite(driverA2_o, LOW);
			digitalWrite(driverB1_o, HIGH);
			digitalWrite(driverB2_o, LOW);
			digitalWrite(driverC1_o, LOW);
			digitalWrite(driverC2_o, HIGH);
			break;

		case 5:
			digitalWrite(driverA1_o, LOW);
			digitalWrite(driverA2_o, HIGH);
			digitalWrite(driverB1_o, HIGH);
			digitalWrite(driverB2_o, LOW);
			digitalWrite(driverC1_o, LOW);
			digitalWrite(driverC2_o, LOW);
			break;

		case 6:
			digitalWrite(driverA1_o, LOW);
			digitalWrite(driverA2_o, HIGH);
			digitalWrite(driverB1_o, LOW);
			digitalWrite(driverB2_o, LOW);
			digitalWrite(driverC1_o, HIGH);
			digitalWrite(driverC2_o, LOW);
			break;
	}

	int v = analogRead(pot_i);
	Serial.println(v);
	int speed = map(v, 0, 1023, 250, 10);

	phase = phase + 1;
	if (phase > 6) phase = 1;
	delay(speed);

}
