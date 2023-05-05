
#include <Arduino.h>
#include "main.h"
#include <pwmWrite.h>
#include "pilote_PWM.h"



// units in degrees per second
float speed1 = 70.0;
float speed2 = 140.0;
float speed3 = 180.0;

// When easing constant (ke) < 1.0, return value is normalized, when 1.0, returns pulse width (μs)
// ke = 0.0 is linear, between 0.0 and 1.0 is tunable sigmoid, 1.0 is normal response
// Normalized Tunable Sigmoid: https://www.desmos.com/calculator/ejkcwglzd1
float ke1 = 0.0;
float ke2 = 0.6;
float ke3 = 0.8;

// go to position (degrees)
uint8_t pos1 = 90;
uint8_t pos2 = 180;
uint8_t pos3 = 135;

float ye1, ye2, ye3;

Pwm pwm = Pwm();

int pilote_PWM_Initialise()
{
    ledcSetup(0, FREQ, RES);
    ledcAttachPin(SERVO1, 0);

    return 0;
}



void write_PWM(int servoPin, int position)
{

    ye1 = pwm.writeServo(servoPin, position, speed1, ke1);

}