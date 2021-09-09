#include <iostream>
#include <string>
// ex02 확인
#include <cstring>
void ex01(void);
void ex02(void);
void ex03(void);
void ex04(void);
void ex05(void);
void ex06(void);
void ex07(void);

// 복합 데이터형
int main()
{
	std::cout << "배열과 문자열" << std::endl;
	// ex01();
	std::cout << "string 클래스" << std::endl;
	ex02();
	std::cout << "구조체" << std::endl;
	ex03();
	std::cout << "공용체, 열거체" << std::endl;
	ex04();
	std::cout << "포인터와 메모리 해제" << std::endl;
	ex05();
	std::cout << "포인터, 배열, 포인터 연산" << std::endl;
	ex06();
	std::cout << "변수형의 조합, 배열의 대안" << std::endl;
	ex07();
	return 0;
}

void ex01(void)
{
	// 중괄호 공백으로 모든 배열을 0으로 초기화 할 수 있다.
	int list1[4] = { };
	const int size = 5;
	// 리스트 초기화시에 축소방지를 할 수 있다.
	char list2[4] = { 'q', '1', 2, '\n' };

	char list3[5] = { 'a','b',' ','d','e' }; // 문자열 아님
	// 모든 문자열의 마지막 문자는 반드시 널 문자여야 한다.
	// 널 문자는 \0으로 쓰고 아스키 코드는 0이다.
	char list6[5] = { 'a','b','e','\0' }; // 문자열 맞음
	char list4[11] = "Mr. cheeps"; // 남는 공간에 \0을 채워준다.
	char list5[] = "Bubbles"; // 컴파일러가 알아서 처리한다.

	// 길면 이렇게 나눠서 쓸 수 있음
	std::cout << "ABCDE" " FGHI" << std::endl;
	char name[size] = "C++a";
	name[3] = '\0';
	std::cout << name << std::endl;

	char name2[size];
	//getline() 함수는 Enter 키에 의해 전다로디는 개행 문자를 읿력의 끝으로 간주하여 한 행 전체를 읽는다.
	std::cin.getline(name2, size);

	int size = 0;
	char list[20] = { 'ㄴ' };
	char list2[20] = { 'ㄴ' };
	// get() 함수는 여러 변종이 있다.
	// 1. getline() 처럼 동작한다. 매개변수를 같은 방식으로 해석하며, 행의 끝까지 읽는다.
	// 그러나 개행 문자를 읽어서 버리지 않고 입력 큐에 그대로 남겨둔다.

	std::cin.get(list, size);
	// std::cin.get(list, size); 문제 발생 !
	// 이렇ㄱ ㅔ하고 싶으면 아래 처럼 해야함
	std::cin.get(list, size);
	std::cin.get();
	std::cin.get(list, size);

	// 2. 두 개의 클래스 멤버 함수를 결합하여 사용한다.
	std::cin.get(list, size).get(); // 멤버 함수들을 결합한다.
	// cin.get(list, size)가 cin 객체를 리턴한다. 리턴된 cin 객체는 뒤에 결합된 get() 함수를 호출하는 객체로 사용된다.
	std::cin.getline(list, size).getline(list2, size);
	// 두 행의 입력을 연속해서 읽어 list, list2 배열에 각각 저장한다.

	/* C++ 에서는 매개변수 리스트를 다르게 하면 같은 이름을 가진 함수의 여러 변종을 사용할 수 있다.
	* cin.get(list, size) 를 사용하면, 컴파일러는 문자열을 읽어 배열에 저장하라는 뜻으로 알아듣고
	* cin.get() 을 사용하면 컴파일러는 문자 하나를 읽으라는 뜻으로 알아듣는다.
	* 이처럼 매개변수 리스트를 다르게 하여 같은 이름의 함수를 여러벌 만드는 것을 함수의 오버로딩이라 한다.
	*
	* getline() 대신에 get()을 사용하는 이유
	* 1. 구식 c++ 에는 getline() 이 없기 때문이다.
	* 2. get() 이 사용자를 다소 신중하게 만들기 때문이다.
	* gteline()은 사용하기가 좀 더 편하고, get()은 에러 체킹이 좀 더 쉽다.
	*
	* get()이 (getline()은 제외) 빈 행을 읽으면 failbit라는 것이 설정된다.
	* 계속되는 입력을 막고 입력을 복원하려면 cin.clear()를 사용해야 한다.
	*
	* 잠재적으로 발생할 수 있는 또 하나의 문제는 입력 문자열이 대입된 공간보다 더 길 수 있다는 것이다.
	* 입력 행이 지정된 문자 수 보다 길면 getline() 과 get() 은 나머지 문자들을 입력 큐에 그대로 남겨둔다.
	* getline()은 failbit를 설정하고 더 이상의 입력을 받지 않는다.
	*/

	int year;
	char name[50];
	/*
	std::cin >> year;
	std::cin.getline(name, 50); // 위에서 엔터 치면서 \n 개행문자가 들어가서 스킵당함, C언어에서 fgets나 getchar 쓸때 스킵 당하는거랑 똑같음 fflush 써서 해결하듯이 다른 방법 있음
	*/

	std::cin >> year;
	std::cin.get();
	// 또는 cin >> year가 cin 객체를 리턴한다는 사실을 이용하여
	// (std::cin >> year).get(); 으로 결합해서 쓸수 있다.
	std::cin.getline(name, 50);
}

void ex02(void)
{
	// string 클래스
	// 문자열을 하나의 데이터형으로 나타내는 좀 더 그럴듯한 표현을 제공한다.
	// string 헤더 파일을 포함시켜야 한다.

	std::string list_data = { "Hello, world" };
	std::string list_data2 = "Hello, mmm";
	char test[30] = { 0 };
	char test2[30] = { 0 };

	list_data = list_data2; // 대입 가능
	std::string list_data3 = list_data + list_data2; // 결합 가능
	list_data += list_data2; // 추가 가능

	// string 과 C 스타일 비교
	list_data = list_data2;
	// strcpy(test, test2); 안돌아감
	list_data += "ㅁㄴㅇㅁㄴㅇ";
	// strcat(test, " asdasdad");
	int len = list_data.size();
	int len2 = strlen(test);

	std::cin.getline(test, 30); // C 스타일
	getline(std::cin, list_data); // string 스타일

	// 다른 형태들
	wchar_t title[] = L"Chief A";
	char16_t aaaaaa[] = u"Fadssad a";
	char32_t car[] = U"Ford F150";
}

void ex03(void)
{
	// 구조체는 사용자가 정의할 수 있는 데이터형이다.
	// C++ 에서는 구조체를 매개변수, 리턴값으로 받을 수 있으며 대입 연산자 (=)를
	// 사용하여 한 구조체의 멤버 값들이 상대방 구조체의 해당 멤버에 각각 대입된다.
	struct ex04struct
	{
		char name[20];
		double price;
		std::string wow[30]; // 컴파일러마다 다르지만 요즘 컴파일러는 구조체 멤버로 string을 지원한다.
	} NOTHIS =
	{
		"Lee",
		2.1,
		"Kim"
	}; // 이렇게 구조체 선언과 동시에 구조체 변수 초기화도 가능하나
	// 템플릿의 정의와 구조체 변수의 선언을 분리해 놓는 것이 프로그램을 더 이해하기 쉽게 만든다.

	// C언어에서 구조체 변수를 선언할 때 키워드 struct를 요구한다.
	// C++ 에서는 키워드 struct를 생략할 수 있다.

	struct ex04struct test1; // C 스타일
	ex04struct test2; // C++ 스타일
	test2.price = 1.234;

	//	C++11의 구조체 초기화
	ex04struct test3{ "LEEKIM", 12.345, "Hello" }; // C++ 에서는 =을 생략할 수 있음
	// {}를 공백으로 하면 각각의 멤버들을 0으로 초기화 한다.
	test2 = test3; // 대입

	// 원소가 구조체인 배열
	ex04struct test4[2] =
	{
		{"PARK", 3.14, "KIM"},
		{"PARK", 3.14, "KIM"}
	};

	// 구조체안의 비트 필드
	// 저수준 프로그래밍에서 주로 사용된다.
	struct torgle_register
	{
		unsigned int SN : 4; // SN 값 (4비트)
		unsigned int : 4; // 사용하지 않음(4비트)
		bool goodIn : 1; // 유효한 입력 (1비트)
		bool goodTorgle : 1; // 토글에 성공 (1비트)
	};


}

void ex04(void)
{
	// 공용체는 서로 다른 데이터형을 한 번에 한 가지만 보관할 수 있는 데이터 형식이다.
	// 공용체의 크기는 멤버 변수들의 타입중 가장 큰 데이터형으로 만들어짐
	// 예를들어 8바이트짜리 공용체를 만들었을때 int형은 4바이트로 8바이트 안에 포함이어서
	// int 형 쓰다가 double 형으로 쓰면 int형은 사용불가
	union one4all
	{
		int int_val;
		double double_val;
	};

	one4all pail;
	pail.int_val = 15; // int 형을 저장
	std::cout << pail.int_val << std::endl;
	pail.double_val = 1.37; // double 형을 저장, int 형 소실
	std::cout << pail.double_val << std::endl;

	// 열거체
	// C++의 enum 기능은 const를 사용하여 기호 상수를 만드는것에 대한 또 다른 방편을 제공한다.
	enum spectrum { red, blue, yellow }; // 열거체
	spectrum band; // band는 spectrum형의 변수

	band = red; // red는 열거자라서 가능
	// band = 3000; 3000은 열거자가 아니라서 불가능
	// band = red + blue; 그럴듯하지만 틀리다.
	enum spectrum2 { red, blue = 2, yellow }; // 값을 명시적으로 지정할 수 있다, 일부만 지정할수도 있다.
	// 대입되는 값들은 정수.
	// red는 0이고 초기화되지 않은 열거자들은 바로 앞의 열거자보다 1만큼 크다. 노랑은 3
}

void ex05(void)
{

}

void ex06(void)
{

}

void ex07(void)
{

}