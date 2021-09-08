#include <iostream>
#include <climits> // 데이터형의 한계값을 나타내기 위해 기호 상수를 사용한다.

// 데이터 처리

int main()
{
	// C++은 C# 처럼 자동 초기화 기능 없음
	// 두개 다름
	int poodle = 0;
	int Poodle;
	// 컴파일러와 리소스가 사용하기로 예약
	int __fire;
	// 컴파일러와 리소스가 전역 식별자로 사용하기로 예약
	int _red;
	short ss1;
	long qwerty;
	long long asd;
	// C++11은 C++98에서 배열과 구조체를 초기화할 때 사용되었던 방법을 단일 값을 가지는 변수에도 사용할 수 있다.
	int a = { 21 };
	int b = { };
	unsigned int aaa = 0x42; // 16진 정수형 상수
	int bbb = 042; // 8진 정수형 상수
	char ch;
	wchar_t cjk; // 기본 문자 세트와 확장 문자 세트를 동시에 지원, cin, cout은 처리 불가
	// C++11 에서 wcin, wout 지원
	char16_t c16;
	char32_t c32;
	bool isready = true;
	const int aaaaa = 0;
	// C++11은 초기화 하는 값을 보고 변수형을 추론할 수 있다.
	auto ccc = 100;
	auto ddd = 1.1;

	std::cout << "short = " << sizeof ss1 << std::endl;
	std::cout << "int = " << sizeof _red << std::endl;
	std::cout << "long = " << sizeof qwerty << std::endl;
	std::cout << "long long = " << sizeof asd << std::endl;
	std::cout << (long)poodle << std::endl;
	std::cout << long(poodle) << std::endl;
	std::cout << static_cast<long>(poodle) << std::endl;

	return 0;
}