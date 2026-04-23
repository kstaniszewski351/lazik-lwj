#include <pigpio.h>
#include <iostream>
#include "motor_driver.h"

motor_driver::motor_driver(int pwm, int in_a, int in_b, int en)
{
    this->in_a = in_a;
    this->in_b = in_b;
    this->pwm = pwm;
    this->en = en;
    
    gpioSetMode(in_a, PI_OUTPUT);
    gpioSetMode(in_b, PI_OUTPUT);
    gpioSetMode(en, PI_OUTPUT);
}

void motor_driver::set_state(motor_state state)
{
    switch (state)
    {
        case FORWARD:
            gpioWrite(in_a, 1);
            gpioWrite(in_b, 0);
            break;
        case BACKWARD:
            gpioWrite(in_a, 0);
            gpioWrite(in_b, 1);
            break;
        case GND_BRAKE:
            gpioWrite(in_a, 0);
            gpioWrite(in_b, 0);
            break;
        case VCC_BRAKE:
            gpioWrite(in_a, 1);
            gpioWrite(in_b, 1);
            break;
    }
}

void motor_driver::set_enabled(bool value)
{
    gpioWrite(en, value);
}

void motor_driver::set_speed(float speed)
{ 
    this->speed = speed;
    gpioHardwarePWM(pwm, frequency, int(1000000 * speed));
}

void motor_driver::set_frequency(int frequency)
{
    this->frequency = frequency;

    set_speed(speed);
}