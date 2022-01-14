#ifndef WINE_HPP_
#define WINE_HPP_

#include <iostream>
#include <string>
#include <valarray>

template <typename T1, typename T2>
class Pair
{
private:
    T1 year;
    T2 num;
public:
    T1 first() const { return year; }
    T2 second() const { return num; }
    Pair() { }
    Pair(const T1 & y, const T2 & n) : year(y), num(n) { }
};

class Wine
{
private:
    typedef std::valarray<int> ArrayInt;
    typedef Pair<ArrayInt, ArrayInt> PairArray;
    PairArray p;
    std::string label;
    int n_year;
public:
    Wine(const char* l, int y, const int yr[], const int bot[]);
    Wine(const char* l, int y);
    void GetBottles();
    const std::string & Label() { return label; }
    int sum() const { return p.second().sum(); }
    void Show() const;
};

Wine::Wine(const char* l, int y)
{
    label = l;
    n_year = y;
}

Wine::Wine(const char* l, int y, const int yr[], const int bot[]) : label(l), n_year(y),p(ArrayInt(yr,y),ArrayInt(bot,y))
{
}

void Wine::GetBottles()
{
	ArrayInt y(n_year);
	ArrayInt n(n_year);
	std::cout << n_year << "년 간의 " << label << " 데이터를 입력하시오:\n";
	for (int i = 0; i < n_year; i++)
	{
		std::cout << "년도를 입력하시오: ";
		std::cin >> y[i];
		std::cout << "수량을 입력하시오: ";
		std::cin >> n[i];
	}
	p=Pair<ArrayInt,ArrayInt>(y, n);
}

void Wine::Show() const
{
	std::cout << "와인: " << label << '\n'
		<< "\t년도\t수량\n";
	for (int i = 0; i < n_year; i++)
	{
		std::cout << "\t" << p.first()[i] << "\t" << p.second()[i] << '\n';
	}
}

#endif