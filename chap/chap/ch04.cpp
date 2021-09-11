#include <iostream>
#include <string>
#include <ctime>

void ex01(void);
void ex02(void);
void ex03(void);

// 루프와 관계 표현식
int main()
{
	// ex01();
	// ex02();
	ex03();

	return 0;
}

void ex01(void)
{
	// for 루프
	// C에서 공부했던 for와 동일
	// 표현식, 구문, 증감 연산자, 감소 연산자, 관계표현식 전부 동일

	// 콤마 연산자
	// 두개의 표현식을 하나로 인식한다. i++, --j
	int j = 10;
	for (int i = 0; i < 10; i++, j--)
	{
		//
	}
	// 콤마 연산자는 우선순위가 가장 낮다.
	// 아래처럼 하면 (cats = 17), 240; 이라서 17만 들어가고 240은 아무것도 수행을 안함.
	int cats;
	cats = 17, 240;
	std::cout << cats << std::endl;

	// C 스타일 문자열 비교
	// strcmp() 사용

	// string 문자열 비교
	std::string str = "q?erty";

	for (char ch = 'a'; str != "qwerty"; ch++)
	{
		str[1] = ch;
	}
}

void ex02(void)
{
	// while 루프
	// C와 동일

	int i = 0;
	while (i != 10)
	{
		i++;
	}

	// 시간 지연, clock 함수 지원 → #include <ctime> → clock() 함수와 clock_t 형이 정의되어 있다.
	clock_t  delay = 5 * CLOCKS_PER_SEC; // 지연 시간을 시스템 단위 클록 수로 변환
	clock_t start = clock();
	while (clock() - start < delay); // 시간이 경과할 때까지 대기, 세미콜론에 유의
	int  n = 0;

	// do while 루프
	do
	{
		std::cout << "일단 저지름";
		n++;
	} while (n != 7); // 한번 수행하고 조건 검사

	// range 기반의 for 루프 / C++ 11 버전에 추가된 기능
	// 기존의 for 반복문과 달리, 시작과 끝점을 알려주지 않아도 알아서 처음부터 끝까지 순회를 하는 반복문
	// STL이나 배열에서 반복문을 쉽게 돌리기 위해 도입
	// C# 의 foreach와 동일 개념

	double prices[5] = { 1,2,3,4,5 };
	// c#에서 foreach(int i in array) 와 형식이 같음
	// in 대신에 :를 씀
	for (double x : prices)
	{
		std::cout << x << std::endl;
	}

	// EOF를 유발하기 위해 특정 문자를 입력 받는건 권장하지 않는다.
	// Ctrl + z 를 애용하자.
	// cin은 EOF를 탐지했을 때 두개의 비트(eofbit, failbit)를 1로 설정한다.
	// eof() 함수와 fail() 함수가 있다. 보통은 fail() 함수를 더 많이 씀
	// eof가 ture여도 cin.clear()로 eof 플래그를 지우고 다시 입력할 수 있도록 한다.

	while (std::cin.fail() == false) // EOF인지 검사한다.
	{
		//
	}

	// getchar와 putchar를 쓰고 싶으면 stdio.h (최신판은 cstdio)를 헤더 파일을 포함시키면 된다.
}

void ex03(void)
{
	// 중첩 루프와 2차원 배열
	// C에서의 2차원 배열과 같음

	int max[2][2] =
	{
		{1,2},
		{3,4}
	};

	std::cout << max[2][2] << std::endl;
}