#include <iostream>
#include <cmath>
#include "exc_mean.hpp"

double hmean(double a, double b);
double gmean(double a, double b);
// double hmean(double a, double b) throw(bad_hmean); C++11 이후로 사용하지 않으며 사용하지 말것
// double gmean(double a, double b) throw(bad_gmean);

int main(void)
{
    double x,y,z;

    std::cout << "두 수를 입력하십시오: ";
    while(std::cin >> x >> y)
    {
        try
        {
            z = hmean(x,y);
            std::cout << x << ", " << y << "의 조화평균은 " << z << "입니다.\n";
            std::cout << x << ", " << y << "의 기하평균은 " << gmean(x,y) << "입니다.\n";
            std::cout << "다른 두 수를 입력하십시오(끝내려면 q): ";
        }
        catch(bad_hmean & bg)
        {
            bg.mesg();
            std::cout << "다시 하십시오.\n";
            continue;
        }
        catch (bad_gmean & hg)
        {
            std::cout << hg.mesg();
            std::cout << "Values used: " << hg.v1 << ", " << hg.v2 << std::endl;
            std::cout << "죄송합니다. 더 이상 진행할 수 없습니다.\n";
            break;
        }
    }

    std::cout << "프로그램을 종료합니다.\n";
    return 0;
}

double hmean(double a, double b)
{
    if(a == -b)
    {
        throw bad_hmean(a,b);
    }
    return 2.0 * a * b / (a+b);
}

double gmean(double a, double b)
{
    if(a < 0 || b < 0)
    {
        throw bad_gmean(a,b);
    }
    return std::sqrt(a * b);
}