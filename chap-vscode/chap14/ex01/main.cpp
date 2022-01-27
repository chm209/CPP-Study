#include <iostream>
#include "tv.hpp"

int main(void)
{
    Tv s42;
    std::cout << "42\" TV의 초기 설정값:\n";
    s42.settings();
    s42.onoff();
    s42.chanup();
    std::cout << "\n42\" TV의 변경된 설정값:\n";
    s42.settings();

    Remote grey;
    grey.set_chan(s42, 10);
    grey.volup(s42);
    grey.volup(s42);
    std::cout << "\n리모컨 사용 후 42\" TV의 설정값:\n";
    s42.settings();

    Tv s58(Tv::On);
    s58.set_mode();
    grey.set_chan(s58, 28);
    std::cout << "\n58\" TV의 설정값:\n";
    s58.settings();

    return 0;
}