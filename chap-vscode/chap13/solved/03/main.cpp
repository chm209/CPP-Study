#include <iostream>
#include <string>
#include "person.hpp"

int main(void)
{
    Person* lolas[3];

    for(int count = 0; count < 3; count++)
    {
        char choice;
        do
        {
            std::cout << "g: 총잡이\np: 카드쟁이\nb: 둘다\nq: 나가기" << std::endl;
            std::cout << "직종을 입력해주세요: ";
            std::cin >> choice;
        } while (std::strchr("gpbq", choice) == NULL);
        
        if(choice == 'q')
        {
            break;
        }

        switch (choice)
        {
            case 'g':
                lolas[count] = new Gunslinger;
                break;
            case 'p':
                lolas[count] = new PokerPlayer;
                break;
            case 'b':
                lolas[count] = new BadDude;
                break;
        }
        lolas[count]->Set();
    }

    std::cout << "\n사원 현황은 다음과 같습니다:\n";
    int i;
    for (i = 0; i < 3; i++)
    {
        std::cout << std::endl;
        lolas[i]->Show();
    }
    for (i = 0; i < 3; i++)
        delete lolas[i];
    std::cout << "프로그램을 종료합니다." << std::endl;

    return 0;
}