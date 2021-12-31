#include <iostream>
#include <cstdlib>
#include <ctime>
#include "stcktp1.hpp"

const int Num = 10;

int main()
{
    int stacksize;

    std::srand(std::time(0));
    std::cout << "스택의 크기를 입력하십시오: ";
    std::cin >> stacksize;
    Stack<const char *> st (stacksize);

    // in basket
    const char * in[Num] = 
    {
        " 1: 갈비뼈", " 2: 전지현",
        " 3: 이글콥", " 4: 아이유",
        " 5: 실로폰", " 6: 사딸라",
        " 7: 박진수", " 8: 김태연",
        " 9: 김두한", "10: 감기약",
    };

    // out basket
    const char* out[Num];
    int processed = 0;
    int nextin = 0;
    while (processed < Num)
    {
        if(st.isempty())
        {
            st.push(in[nextin++]);
        }
        else if(st.isfull())
        {
            st.pop(out[processed++]);
        }
        else if(std::rand() % 2 && nextin < Num)
        {
            st.push(in[nextin++]);
        }
        else
        {
            st.pop(out[processed++]);
        }
    }
    for(int i = 0 ; i < Num; i++)
    {
        std::cout << out[i] << std::endl;
    }

    std::cout << "프로그램을 종료합니다.\n";
    return 0;
}