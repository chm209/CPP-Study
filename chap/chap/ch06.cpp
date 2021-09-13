#include <iostream>
#include <string>
#include <array>

void ex1(void);
void ex2(void);
void fix(std::array<double, 4>* pa);
double ex2Func(int);
void ex2Func2(int x, double (*ppff)(int));

void main()
{
	// ex1();
	ex2();
	
}

void ex1(void)
{
	// 함수
	// C와 동일, 새로운 기능이 조금 있음

	// 포인터와 const / 사용법이 두가지로 나뉜다.
	// 1. 상수 객체를 지시하는 포인터를 만든다
	// 2. 포인터 자신을 상수로 만드는것

	int age = 13;
	const int* pt1 = &age;
	// pt1으로는 값을 변경할 수 없지만 age는 상수가 아니라서 직접 변경할 수 있다.

	const int num1 = 10;
	const int* pt2 = &num1; // 사용가능
	// int* pt3 = &num1; 사용불가, num1은 상수인데 pt3은 상수가 아니라서 의미가 없어서 막음
	// 굳이 쓰고 싶으면 const_cast로 const를 무력화하고 써야함
	int* pt3 = const_cast<int*>(&num1);
	*pt3 = 20;
	std::cout << *pt3;

	// C 스타일 문자열과 일반 배열의 중요한 차이점 하나는 문자열에는 NULL 종결 문자가 들어 있다는것.
	// 연속된 문자를 가지고 있지만 널 문자를 가지고 있지 않는 char 배열은 문자열이 아니라 그냥 배열이다.
	// 따라서 문자열의 크기는 매개변수로 전달할 필요가 없다.

	const char* test = "qwerty";

	while (*test) // *test가 \0이면 루프를 탈출한다.
	{
		if (*test == 'y')
		{
			std::cout << "찾음";
		}
		test++;
	} 
}

void ex2(void)
{
	// 함수와 array 객체, vector도 전송 가능
	std::array<double, 4> pa;
	fix(&pa);

	// 함수 포인터의 기초
	// 함수의 주소도 전송 가능
	// exfunc(blink) → blink()의 주소를 전달
	// exfunc(blink()) → blink() 의 리턴값을 전달

	// 함수를 지시하는 포인터 / 함수 포인터
	// 함수 포인터는 주로 함수를 다른 함수에 전달할 때 유용하다. 함수 포인터를 선언하는 원시적인 방법은 보기 나쁘고 오류를 발생시키기 쉽우므로 typedef, using 또는 std::function을 사용하는 게 좋다.
	double (*pf)(int); // 함수 포인터
	typedef double (*pf)(int x); // typedef로 단순화 가능
	using pointFunc = double(*)(int); // C++11 부터는 이렇게 정의 가능
	// 포인터를 사용하여 함수 불러내기
	pf = ex2Func; // pf는 ex2Func를 지시
	double x = ex2Func(4); // 함수 이름을 사용한 호출
	double y = (*pf)(5); // 포인터 pf를 사용한 호출
	double t = pf(5); // c++은 pf도 함수 이름처럼 사용하는 것을 허용한다.

	ex2Func2(4, ex2Func);
	/* 모두 같은 표현
	* const double* fi(const double ar[], int n);
	* const double* fi(const double [], int n);
	* const double* fi(const double*, int n);
	*/
}

void fix(std::array<double, 4> *pa)
{
	for (int i = 0; i < 4; i++)
	{
		std::cin >> (*pa)[i];
	}
}

void ex2Func2(int x, double (*ppff)(int))
{
	double x = (*ppff)(x);
}