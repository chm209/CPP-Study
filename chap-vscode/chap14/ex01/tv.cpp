#include <iostream>
#include "tv.hpp"

bool Tv::volup()
{
    if(volume < MaxVal)
    {
        volume++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Tv::voldown()
{
    if(volume > MinVal)
    {
        volume--;
        return true;
    }
    else
    {
        return false;
    }
}

void Tv::chanup()
{
    if(channel < maxchannel)
    {
        channel++;
    }
    else
    {
        channel--;
    }
}

void Tv::chandown()
{
    if(channel > 1)
    {
        channel--;
    }
    else
    {
        channel = maxchannel;
    }
}

void Tv::settings() const
{
    std::cout << "TV = " << (state == Off ? "OFF" : "ON") << std::endl;
    if(state == On)
    {
        std::cout << "볼륨 = " << volume << std::endl;
        std::cout << "채널 = " << channel << std::endl;
        std::cout << "모드 = " << (mode == Antenna ? "지상파 방송" : "케이블 방송") << std::endl;
        std::cout << "입력 = " << (input == TV ? "TV" : "DVD") << std::endl;
    }
}