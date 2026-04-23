#include <iostream>
#include <SDL3/SDL.h>
#include "input_manager.h"
#include "controller_manager.h"
#include "motor_driver.h"
#include "utils.h"

input_manager::input_manager(motor_driver* motor_r, motor_driver* motor_l) : 
    controller(controller_manager(this)),
    motor_r(motor_r),
    motor_l(motor_l)
{
    //controller = controller_manager(this);
    //ntroller.start_loop();


    motor_r->set_frequency(20000);
    motor_l->set_frequency(20000);
    motor_r->set_enabled(1);
    motor_l->set_enabled(1);
    motor_r->set_state(motor_state::GND_BRAKE);
    motor_l->set_state(motor_state::GND_BRAKE);
}



void input_manager::handle_button(bool state, Uint8 button)
{
    //std::cout << state << " " << button << std::endl;
    if(button == SDL_GAMEPAD_BUTTON_RIGHT_SHOULDER)
    {
 
        r_direction = state;
    }
    if(button == SDL_GAMEPAD_BUTTON_LEFT_SHOULDER)
    {
        l_direction = state;
    }
}

void input_manager::handle_axis(int value, Uint8 axis)
{
    //std::cout << axis << " " << value << std::endl;
    if(axis == SDL_GAMEPAD_AXIS_RIGHT_TRIGGER)
    {
        this->r_speed = value;
    }
    else if(axis == SDL_GAMEPAD_AXIS_LEFT_TRIGGER)
    {
        this->l_speed = value;
    }
    else if(axis == SDL_GAMEPAD_AXIS_LEFTX)
    {
        this->direction = value;
    }
}


void input_manager::end_input()
{
    //std::cout << "r: " << r_speed << " analog: " << direction << std::endl;

    controller.update();
    int d_multiplier = 1;
    float speed = 0;
    if(r_speed > SPEED_TRESHOLD && l_speed < SPEED_TRESHOLD)
    {
        d_multiplier = 1;
        speed = to_float(r_speed, 0, 32786);

    }
    else if(l_speed > SPEED_TRESHOLD && r_speed < SPEED_TRESHOLD)
    {
        d_multiplier = -1;
        speed = to_float(l_speed, 0, 32786);

    }

    int d_r = 1;
    int d_l = 1;
    if(direction > DIRECTION_TRESHOLD)
    {
        d_r = -1;
    }
    else if(direction < -DIRECTION_TRESHOLD)
    {
        d_l = -1;
    }

    d_r = d_r * d_multiplier;
    d_l = d_l * d_multiplier;

    // right motor
    if(d_r == 1)
    {
        motor_r->set_state(FORWARD);
    }
    else
    {
        motor_r->set_state(BACKWARD);
    }
    
    //left motor
    if(d_l == 1)
    {
        motor_l->set_state(FORWARD);
    }
    else
    {
        motor_l->set_state(BACKWARD);
    }
    motor_r->set_speed(speed);
    motor_l->set_speed(speed);


}