int driverA1_o = 3;
int driverA2_o = 5;
int driverB1_o = 6;
int driverB2_o = 9;
int driverC1_o = 10;
int driverC2_o = 11;

int emfA = A1;
int emfB = A2;
int emfC = A3;

int pot_i = A0;
int Speed;
int v;
int phase = 1;

static int trigger1 = 0;
static int trigger2 = -1;

unsigned long time1 = 0;
unsigned long time2;

void setup() {

	Serial.begin(9600);

	pinMode(driverA1_o, OUTPUT);
	pinMode(driverA2_o, OUTPUT);
	pinMode(driverB1_o, OUTPUT);
	pinMode(driverB2_o, OUTPUT);
	pinMode(driverC1_o, OUTPUT);
	pinMode(driverC2_o, OUTPUT);

	pinMode(emfA, INPUT);
	pinMode(emfB, INPUT);
	pinMode(emfC, INPUT);

	pinMode(pot_i, INPUT);
	
	//time1 = micros();

}

void loop() {

	int emfA_read = analogRead(emfA);
	int emfB_read = analogRead(emfB);
	int emfC_read = analogRead(emfC);
	int avarage = (emfA_read + emfB_read + emfC_read) / 3;

	time2 = micros();
	if (time2 - time1 >= Speed) {
		time1 = time1 + Speed;

		switch (phase) {
		case 1:
			digitalWrite(driverA1_o, LOW);
			digitalWrite(driverA2_o, LOW);
			digitalWrite(driverB1_o, LOW);
			digitalWrite(driverB2_o, HIGH);
			digitalWrite(driverC1_o, HIGH);
			digitalWrite(driverC2_o, LOW);
			trigger1 = emfA_read - avarage;
			break;

		case 2:
			digitalWrite(driverA1_o, HIGH);
			digitalWrite(driverA2_o, LOW);
			digitalWrite(driverB1_o, LOW);
			digitalWrite(driverB2_o, HIGH);
			digitalWrite(driverC1_o, LOW);
			digitalWrite(driverC2_o, LOW);
			trigger1 = emfC_read - avarage;
			break;

		case 3:
			digitalWrite(driverA1_o, HIGH);
			digitalWrite(driverA2_o, LOW);
			digitalWrite(driverB1_o, LOW);
			digitalWrite(driverB2_o, LOW);
			digitalWrite(driverC1_o, LOW);
			digitalWrite(driverC2_o, HIGH);
			trigger1 = emfB_read - avarage;
			break;

		case 4:
			digitalWrite(driverA1_o, LOW);
			digitalWrite(driverA2_o, LOW);
			digitalWrite(driverB1_o, HIGH);
			digitalWrite(driverB2_o, LOW);
			digitalWrite(driverC1_o, LOW);
			digitalWrite(driverC2_o, HIGH);
			trigger1 = emfA_read - avarage;
			break;

		case 5:
			digitalWrite(driverA1_o, LOW);
			digitalWrite(driverA2_o, HIGH);
			digitalWrite(driverB1_o, HIGH);
			digitalWrite(driverB2_o, LOW);
			digitalWrite(driverC1_o, LOW);
			digitalWrite(driverC2_o, LOW);
			trigger1 = emfC_read - avarage;
			break;

		case 6:
			digitalWrite(driverA1_o, LOW);
			digitalWrite(driverA2_o, HIGH);
			digitalWrite(driverB1_o, LOW);
			digitalWrite(driverB2_o, LOW);
			digitalWrite(driverC1_o, HIGH);
			digitalWrite(driverC2_o, LOW);
			trigger1 = emfB_read - avarage;
			break;
		}

		if (trigger2 < 0) {
			if (trigger1 > 0) {
				trigger2 = trigger1;
				phase = phase + 1;
				if (phase > 6) phase = 1;
			}
		}
		if (trigger2 > 0) {
			if (trigger1 < 0) {
				trigger2 = trigger1;
				phase = phase + 1;
				if (phase > 6) phase = 1;
			}
		}
		v = analogRead(pot_i);
		Speed = map(v, 0, 1023, 30000, 1);

		//Serial.println(Speed);

		//Serial.print("time1 is: ");
		//Serial.println(time1);
		//Serial.print("time2 is: ");
		//Serial.println(time2);
		Serial.print("emf A is: ");
		Serial.println(emfA_read);
		Serial.print("emf B is: ");
		Serial.println(emfB_read);
		Serial.print("emf C is: ");
		Serial.println(emfC_read);
		//phase = phase + 1;
		//if (phase > 6) phase = 1;
	}
}
