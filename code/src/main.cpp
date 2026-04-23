#include <iostream>
#include <unistd.h>
#include <pigpio.h>
#include <chrono>
#include <atomic>
#include <thread>
#include <SDL3/SDL.h>
#include "motor_driver.h"
#include "input_manager.h"

input_manager* input;


int main() {
    if(gpioInitialise() < 0)
    {
        std::cout << "gpio initialization failed \n";
        return 1;
    }

    motor_driver* motor_l = new motor_driver(12, 14, 15, 3);
    motor_driver* motor_r = new motor_driver(13, 18, 23, 4);
    input = new input_manager(motor_r, motor_l);
    
    while(true) {
        input->end_input();
    }

    return 0;
}
