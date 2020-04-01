#pragma once


#include <iostream>
#include <chrono>


class Timer {
     std::chrono::time_point<std::chrono::steady_clock> start_time;
     std::chrono::time_point<std::chrono::steady_clock> stop_time;

  public:
    void start()
    {
        start_time = std::chrono::steady_clock::now();
    }
    void stop()
    {
        stop_time = std::chrono::steady_clock::now();
    }
    void print_time_duration()
    {
        std::cout<<"This Function took: "<<std::chrono::duration_cast<std::chrono::microseconds>(stop_time - start_time).count()<<" Microseconds."<<std::endl;
    }

};

