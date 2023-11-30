/**
 * Sarah lives in place where municipal water comes less often,
 * as a result Sarah decided to set up a water tank which serves home
 * use and home garden. Sarah has one challenge that water get finished
 * unnoticed instead of getting an alert at some point such that some
 * unnecessary water use is avoided.
 *
 * To solve the challenge, Sarah got a systems engineer consultant who
 * suggested a kit that keeps track of water level in real time.
 *
 * The consultant made the following observations:
 * The tank has 4 meters height
 * When the tank is full of water, the distance from the top of the
 * tank to the water level is 4cm.
 * As water reduce in the tank, the distance between the top and water
 * level keeps increasing until it becomes 4 meters when water has been
 * completely used from the tank.
 *
 * The work of a consultant
 *
 * The consultant designed a circuit with the following components:
 * Arduino Uno: This is a micro-controller which coordinates all the
 * necessary operations of the circuit.
 * Ultrasonic Sensor: This is a sensor which detects the distance from
 * the tank top to the water level.
 * Piezo (buzzer): This will make sound when water gets to critical level
 * Green LED: This LED will keep up lighted up when water is still
 * in sufficient level.
 * Red LED: This LED will keep up lighted up when water is bellow sufficient
 * level but still above critical level.
 * Resistor: This controls the current flow such that voltage from the source
 * is reduced to get to the appliance in the required amount.
 *
 *
 * Expected Work
 * Write a program that will make this system work as expected.
 *
 * The system will have the green LED turned on when the level of water is
 * still above 3.5 meters of tank measured from the bottom of the tank.
 *
 * The system will have the red LED turned on when the level of water is below
 * 3.5 meters and above 1.5 meters measured from the bottom of the tank.
 *
 * The system will have the buzzer beeping every 10 seconds when the water
 * level goes below 1.5 meters. At the same time the red light will toggle
 * between on and off along with the buzzer sounding.
*/

/**
 * Note: The connection of the Buzzer and the LEDs to the resistor makes
 * that the Buzzer constantly sounds
 * when one of the LEDs is on.
 * For this reason, the Buzzer sound when the water level is below 1.5 meters
 * is different from the one when the program starts.
*/


#define GREEN_LED 7
#define RED_LED 2
#define BUZZER 0

/*The tank is full at 396 cm (400 cm - 4 cm from the top)*/
#define TANK_FULL_LEVEL 396
/*Green LED threshold in cm*/
#define GREEN_LED_THRESHOLD 350
/*Red LED threshold in cm*/
#define RED_LED_THRESHOLD 150
/*Buzzer interval in milliseconds*/
#define BUZZER_INTERVAL 10000

/*Stores the last time the buzzer was activated*/
unsigned long previousMillis = 0;

void setup()
{
	pinMode(GREEN_LED, OUTPUT);
	pinMode(RED_LED, OUTPUT);
	pinMode(BUZZER, OUTPUT);
}

/**
* loop - Entry point
*
* Return: Always 0 (Success)
*/
void loop()
{

	/*Ensure the buzzer is silent at the start of the loop iteration*/
	noTone(BUZZER);
	unsigned long currentMillis = millis();

	/*Decrease the simulated water level*/
	float distance = simulateWaterLevelDecrease();

	/*Handle the green LED state*/
	handleGreenOrRedLED(distance, currentMillis);

	/*Short delay for stability and simulation speed*/
	delay(50);
}

/**
* simulateWaterLevelDecrease - Simulates the water level decreasing
*
* Return: The simulated water level
*/
float simulateWaterLevelDecrease()
{
	static float simulatedWaterLevel = TANK_FULL_LEVEL;

	simulatedWaterLevel -= 0.01;
	if (simulatedWaterLevel < 0)
	{
		simulatedWaterLevel = TANK_FULL_LEVEL;
	}
	return (simulatedWaterLevel);
}

/**
* handleGreenOrRedLED - Handles the green and red LEDs
* @distance: Distance from the top of the tank to the water level
* @currentMillis: Current time in milliseconds
*/
void handleGreenOrRedLED(float distance, unsigned long currentMillis)
{
	if (distance >= GREEN_LED_THRESHOLD)
	{
		digitalWrite(GREEN_LED, HIGH);
		digitalWrite(RED_LED, LOW);
	}
	else if (distance >= RED_LED_THRESHOLD)
	{
		digitalWrite(GREEN_LED, LOW);
		digitalWrite(RED_LED, HIGH);
	}
	else
	{
		digitalWrite(GREEN_LED, LOW);
		handleRedLEDandBuzzer(currentMillis);
	}
}

/**
* handleRedLEDandBuzzer - Handles the red LED and buzzer
* @currentMillis: Current time in milliseconds
*/
void handleRedLEDandBuzzer(unsigned long currentMillis)
{
	if (currentMillis - previousMillis >= BUZZER_INTERVAL)
	{
		/*Turn on the buzzer and RED LED*/
		digitalWrite(RED_LED, HIGH);
		/*Start buzzer at 220 Hz for 1000 milliseconds*/
		tone(BUZZER, 220, 250);

		/*Ensure the buzzer has time to sound before continuing*/
		delay(300);

		digitalWrite(RED_LED, LOW);

		previousMillis = currentMillis;
	}
}
