#include <SDL3/SDL.h>
#include <chrono>
#include <thread>
#include <iostream>
#include "controller_manager.h"
#include "input_manager.h"

controller_manager::controller_manager(input_manager* input)
{
    SDL_InitSubSystem(SDL_INIT_GAMEPAD);

    this->input = input;
}

controller_manager::~controller_manager()
{
    //stop_loop();
    if(controller)
    {
        SDL_CloseGamepad(controller);
    }
    SDL_Quit();
}




void controller_manager::update()
{
    SDL_Event* event = new SDL_Event();
    //bool run = true;

    //input->start_input();
    while(SDL_PollEvent(event) != 0)
    {
        switch(event->type)
        {
            case SDL_EVENT_GAMEPAD_ADDED:
            {
                int i = event->cdevice.which;
                SDL_Gamepad* controller_new = SDL_OpenGamepad(i);
                if(controller_new)
                {
                    SDL_CloseGamepad(controller);
                    controller = controller_new;
                    std::cout << "opened controller\n";
                }
                break;
            }
            case SDL_EVENT_GAMEPAD_REMOVED:
            {
                SDL_CloseGamepad(controller);
                controller = nullptr;
                std::cout << "closed controller\n";
                break;
            }
            case SDL_EVENT_GAMEPAD_BUTTON_DOWN:
            {
                Uint8 button = event->gbutton.button;
                input->handle_button(true, button);
                break;
            }
            case SDL_EVENT_GAMEPAD_BUTTON_UP:
            {
                Uint8 button = event->gbutton.button;
                input->handle_button(false, button);
                break;
            }
            case SDL_EVENT_GAMEPAD_AXIS_MOTION:
            {
                Uint8 axis = event->gaxis.axis;
                int value = event->gaxis.value;
                input->handle_axis(value, axis);
            }
        }
    }
    //input->end_input();

        //std::unique_lock<std::mutex> lock(mtx);
        //run = !cv.wait_for(lock, std::chrono::milliseconds(20), [this] {return quit; });
    
    return;
}