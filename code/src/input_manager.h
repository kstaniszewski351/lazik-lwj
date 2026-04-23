#pragma once

#include "controller_manager.h"
#include "motor_driver.h"

class input_manager
{
    public:
        input_manager(motor_driver* motor_r, motor_driver* motor_l);
        //~input_manager();
        void handle_button(bool state, Uint8 button);
        void handle_axis(int value, Uint8 axis);
        //void start_input();
        void end_input();
    private:
        controller_manager controller;
        motor_driver* motor_r;
        motor_driver* motor_l;
        bool r_direction;
        bool l_direction;
        bool r_turn;
        bool l_turn;
        int r_speed;
        int l_speed;
        int direction;
        static const int DIRECTION_TRESHOLD = 10000;
        static const int SPEED_TRESHOLD = 200;
};