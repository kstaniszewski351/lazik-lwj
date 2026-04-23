#pragma once

#include <SDL3/SDL.h>
#include <atomic>
#include <thread>
#include <condition_variable>
#include <mutex>

class input_manager;

class controller_manager
{
    public:
        controller_manager(input_manager* input);
        ~controller_manager();
        //void start_loop();
        //void stop_loop();
        void update();
    private:
        SDL_Gamepad* controller;
        //void loop();
        input_manager* input;
        //std::thread thread;
        //bool quit;
        //std::condition_variable cv;
        //std::mutex mtx;
};