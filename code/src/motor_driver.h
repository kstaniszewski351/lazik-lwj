#pragma once

enum motor_state
{
    FORWARD,
    BACKWARD,
    GND_BRAKE,
    VCC_BRAKE 
};

class motor_driver 
{
    public:
        motor_driver(int pwm, int in_a, int in_b, int en);
        void set_state(motor_state state);
        void set_enabled(bool value);
        void set_speed(float speed);
        void set_frequency(int frequency);
        
    private:
        int pwm;
        int in_a;
        int in_b;
        int en;
        int frequency;
        float speed;
};