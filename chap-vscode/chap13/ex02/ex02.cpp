#include <iostream>
#include <string>
#include <cctype>
#include "stacktp.hpp"

int main()
{
    Stack<std::string> st;
    char ch;
    std::string po;
    std::cout << "주문서를 추가하려면 A, 주문서를 처리하려면 F, \n"
        << "종료하려면 Q를 입력하십시오. \n";
    while(std::cin >> ch && std::toupper(ch) != 'Q')
    {
        while(std::cin.get() != '\n')
        {
            continue;
        }
        if(!std::isalpha(ch))
        {
            std::cout << '\a';
            continue;
        }
        switch (ch)
        {
        case 'A':
        case 'a':
            std::cout << "추가할 주문서의 번호를 입력하십시오: ";
            std::cin >> po;
            if(st.isfull())
            {
                std::cout << "스택이 가득 차 있습니다.\n";
            }
            else
            {
                st.push(po);
            }
            break;
        case 'P':
        case 'p':
            if(st.isempty())
            {
                std::cout << "스택이 비어 있습니다.\n";
            }
            else
            {
                st.pop(po);
                std::cout << "#" << po << " 주문서를 처리했습니다.\n";
                break;
            }
        default:
            break;
        }
        std::cout << "주문서를 추가하려면 A, 주문서를 처리하려면 P, \n"
            << "종료하려면 Q를 입력하십시오.\n";
    }
    std::cout << "프로그램을 종료합니다.\n";
    return 0;
}