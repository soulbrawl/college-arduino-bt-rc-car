class UltrasonicSensor {

    private:
        // HC-04 variables
        int _trigPin;
        int _echoPin;
        long _duration;
        String _id;

    public:
        // Constructor
        UltrasonicSensor(String id) {
            _id = id;
        }

        // Deconstructor
        // ~UltrasonicSensor() { }

        int _distanceCm;

        void US_Setup(int trigPin, int echoPin) {
            // HC-04 variables
            _trigPin = trigPin;
            _echoPin = echoPin;

            //HC-SR04 setup
            pinMode(_trigPin, OUTPUT);
            pinMode(_echoPin , INPUT);
        }

        //HC-SR04 Loop
        void US_Loop() {
            // Clears the trigPin
            digitalWrite(_trigPin, LOW);
            delayMicroseconds(2);

            // Sets the trigPin on HIGH state for 10 micro seconds
            digitalWrite(_trigPin, HIGH);
            delayMicroseconds(10);
            digitalWrite(_trigPin, LOW);

            // Reads the echoPin, returns the sound wave travel time in microseconds
            _duration = pulseIn(_echoPin, HIGH, 24000); // _duration * 0.034 / 2 * 400 = 6.8??

            // Calculating the distance
            _distanceCm = _duration * 0.034 / 2;

            if (_distanceCm == 0) _distanceCm = 400;
        }

        // THINKING: Integrating this function above as well?
        // Bluetooth Display (Serial Monitor for now)
        void US_Display() {
            Serial.print(_id);
            Serial.print(": ");
            Serial.print(_distanceCm);
            Serial.print(" Cm distance");
            Serial.print("\n");
            // Serial.print("                "); // or using a Display module
        }
};

// creating each Ultrasonic Sensor class/object
UltrasonicSensor ultrasonicSensors[4] = {
    UltrasonicSensor("FL"),
    UltrasonicSensor("FR"),
    UltrasonicSensor("BL"),
    UltrasonicSensor("BR")
};

void ultrasonicSensorSetup() {
    ultrasonicSensors[0].US_Setup(US_FL_TRIG_PIN, US_FL_ECHO_PIN);
    ultrasonicSensors[1].US_Setup(US_FR_TRIG_PIN, US_FR_ECHO_PIN);
    ultrasonicSensors[2].US_Setup(US_BL_TRIG_PIN, US_BL_ECHO_PIN);
    ultrasonicSensors[3].US_Setup(US_BR_TRIG_PIN, US_BR_ECHO_PIN);
}

String sensorNames[] = {"FL", "FR", "BL", "BR"};

void ultrasonicSensorTestingRoutine() {
    for (int i = 0; i < 4; i++) {
        while (runForDuration(3000)) {
            ultrasonicSensors[i].US_Loop();
            ultrasonicSensors[i].US_Display();
        }
    }
}
