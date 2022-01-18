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

/*
* Pair 코드는 지문의 예제 코드와 동일
* 변수명만 변경
*/

class Wine
{
private:
    typedef std::valarray<int> ArrayInt; // std::valarray<int>를 ArrayInt로 줄여 부른다
    typedef Pair<ArrayInt, ArrayInt> PairArray; // 줄여쓴 ArrayInt로 Pair 클래스 객체 선언을 다시 PairArray로 줄여씀
    PairArray p; // Pair 객체 선언
    std::string label;
    int n_year;
public:
    Wine(const char* l, int y, const int yr[], const int bot[]);
    Wine(const char* l, int y);
    void GetBottles();
    const std::string & Label() { return label; } // string 참조로 label 리턴
    int sum() const { return p.second().sum(); }
    /*
    * Pair 객체 p의 second 멤버함수를 호출한뒤
    * valarray 클래스안에 포함된 sum 멤버함수를 호출한다.
    * 컨테인먼트 관계인건 상관없이 second()가 T2로 선언한 num을 리턴해서 sum()을 호출가능함
    * 
    * valarray 클래스의 공용 멤버 함수 :
    * - apply(): 이 함수는 인수에 주어진 조작을 모든 valarray 요소에 한 번에 적용하고 조작된 값으로 새 valarray를 반환 합니다.
    * - sum(): 이 함수는 valarray의 모든 요소의 합을 한번에 반환합니다.
    */
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

/*
* label(l) 보고 저거 왜 저럴까라고 생각했는데 멤버 초기자 리스트 사용 방법이 콜론(:)을 붙이고 클래스멤버(값) 이다.
* ArrayInt(yr,y) 를 하는 이유는 배열과 배열 크기를 넘겨서 저장하는것 같음
*/

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

/*
* 복잡하게 생각할거 없고 그냥 wine 객체 생성할때 받은 값으로 valarray 변수 만들어서
* y는 년도 n은 수량 저장하는것
* p=Pair<ArrayInt,ArrayInt>(y, n); -> 디폴트 대입 연산자로 대입하는것, 해제할 메모리가 없으니 사용가능
*/

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