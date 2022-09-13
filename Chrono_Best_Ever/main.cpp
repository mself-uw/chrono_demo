#include <chrono>
#include <iostream>
#include <iomanip>
#include <thread>
#include <ratio>

//Print durations using clean and intuitive duration_cast 
template <typename T>
void CheckTimingWithDurationCasts(T duration)
{
    std::cout << std::chrono::duration_cast<std::chrono::seconds>(duration) << std::endl;
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(duration) << std::endl;
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(duration) << std::endl;
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(duration) << std::endl;
}


//Print period for commonly used chrono clock types. Note that high_resolution_clock is just an alias for steady_clock
void PrintClockPeriods()
{
    std::cout << std::endl << "clock periods" << std::endl;

    std::cout << "system_clock:          " << std::chrono::system_clock::period::num          << "/" <<
                                              std::chrono::system_clock::period::den          << std::endl;
    std::cout << "steady_clock:          " << std::chrono::steady_clock::period::num          << "/" <<
                                              std::chrono::steady_clock::period::den          << std::endl;
    std::cout << "high_resolution_clock: " << std::chrono::high_resolution_clock::period::num << "/" <<
                                              std::chrono::high_resolution_clock::period::den << std::endl;
}


//Print and explore std::chrono::duration in different time units using ratios
template<typename T>
void CheckTimingDurations(T before, T after)
{
    std::chrono::duration<double> duration = after - before;
    std::cout << std::fixed << duration << std::endl;

    std::cout << std::chrono::duration<double, std::milli>(after - before) << std::endl;
    std::cout << std::chrono::duration<double, std::micro>(after - before) << std::endl;
    std::cout << std::chrono::duration<double, std::nano>(after - before) << std::endl;
    std::cout << std::chrono::duration<double, std::pico>(after - before) << std::endl;
    
    //custom ratio
    std::cout << std::chrono::duration<double, std::ratio<1, 2>>(after - before) << std::endl;
}


int main() 
{ 
    std::cout << "how long is sleep_for 1 second *really*? ";
    std::cout << std::endl << "execution time: " << std::endl;

    auto before = std::chrono::steady_clock::now();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    auto after = std::chrono::steady_clock::now();


    //Example functions to explore 
    
    CheckTimingDurations(before, after);
    //PrintClockPeriods();
    //CheckTimingWithDurationCasts(after - before);

    
    std::cout << std::endl;
    return 0;
}