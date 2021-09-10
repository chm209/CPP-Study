#include <iostream>
#include <string>
// ex02 확인
#include <cstring>
#include <vector>
#include <array>

void ex01(void);
void ex02(void);
void ex03(void);
void ex04(void);
void ex05(void);
void ex06(void);
void ex07(void);

// 복합 데이터형
// 챕터 3까지는 C에서 했던것들을 간략하게 훑어보면서 C++의 새로운 기능들을 맛보기로 설명하는 느낌이다.
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
	// 포인터와 메모리 해제
	// 포인터는 값 자체가 아니라 값의 주소를 저장하는 변수
	// C랑 똑같음 & 붙이면 주소 * 붙이면 그 주소안에 들어있는 값
	// 16진수 표기가 메모리를 나타내는 가장 일반적인 방법

	int num1 = 1;
	int* pointer = NULL;

	// 포인터 변수 pointer에 num1의 주소를 저장
	pointer = &num1;

	// 포인터는 정수형이 아니다.
	// pointer = 0xB8000000; 데이터형 불일치
	pointer = (int*)0xB8000000; // 데이터형 일치

	// new를 사용한 메모리 대입
	// C에서는 malloc 함수로 이름없는 메모리를 추가로 할당했다.
	// C++에서도 그렇게 할 수 있으나 new 연산자를 사용하는 더 좋은 방법이 있다.
	
	// new 연산자 사용방법
	// pointer_new가 지시하는 메모리는 이름이 없는데 이 메모리에 접근할 수 있는 이유는
	// pointer_new가 데이터 객체를 지시하고 있어서이다. (여기서 객체는 object가 아니라 어떤 대상을 의미한다.)
	int* pointer_new = new int;

	// delete를 사용한 메모리 해제
	// 이렇게 하면 pointer_new에 지시한 메모리가 해제된다.
	// 그러나 pointer_new 자체가 사라지는건 아니다.
	// 해제한걸 곧바로 다시 해제 못하고 new로 대입한 메모리가 아니면 해제 못한다.
	delete pointer_new;

	// new를 사용한 동적 배열의 생성
	// 정적 바인딩 (static binding): 선언에 의해 배열을 생성하면, 프로그램이 컴파일될 때 배열을 위한 메모리가 대입된다.
	// 프로그램이 실행될 때 이 배열은 사용하든 안 하든 항상 메모리를 차지한다. 이 방식을 정적 바인딩이라고 한다.
	// ーーー
	// 동적 바인딩 (dynamic binding): new를 사용하면 배열을 실행 시간에 생성할 수 있고, 필요 없으면 생성하지 않을 수도 있다.
	// 또는 프로그램을 실행하는 동안에 배열의 크기를 결정할 수 있다.
	//

	int* pn_array = new int[10]; // 10개의 int형 값을 저장할 블록을 대입
	delete[] pn_array; // 동적 배열 해제

	// new와 delete를 사용할 때 규칙
	// 1. new로 대입하지 않은 메모리는 delete로 해제하지 않는다.
	// 2. 같은 메모리 블록을 연달아 두 번 delete로 해제하지 않는다.
	// 3. new []로 메모리를 대입한 경우에는 delete[]로 해제한다.
	// 4. new를 대괄호 없이 사용했으면 delete로 대괄호 없이 사용한다.
	// 5. 널 포인터에는 delete를 사용하는 것이 안전하다.(아무 일도 일어나지 않는다.)

	int* pn_list = new int[3];
	pn_list[0] = 1;
	pn_list[1] = 2;
	pn_list[2] = 3;

	std::cout << pn_list[0] << std::endl;
	std::cout << pn_list[1] << std::endl;
	std::cout << pn_list[2] << std::endl;

	delete[] pn_list;
}

void ex06(void)
{
	// 포인터, 배열, 포인터 연산
	double list1[3] = { 0.1, 0.2, 0.3 };
	short list2[3] = { 1,2,3 };

	// 포인터 변수에 배열을 대입하면 배열 요소의 첫번째 주소가 들어감
	double* pointer_list1 = list1; // list1은 &list1[0] 이랑 같음
	short* poineter_list2 = &list2[0];
	pointer_list1 += 1; // pointer_list1이 list1의 0번째 요소의 주소를 가지고 있어서 +1 하면 [1] 요소를 가리킴
	poineter_list2 += 1; // 마찬가지로 pointer_list2가 list2의 0번째 요소의 주소를 가지고 있어서 +1 하면 [1] 요소를 가리킴

	// 포인터의 간접 참조
	// 포인터의 간접 참조는 포인터가 지시하는 주소에 저장되어 있는 값을 참조한다는 뜻이다.

	char animal[20] = "bear";
	char* pt;

	// std::cin >> pt; 절대 하지 말것
	pt = animal;
	pt = new char[strlen(animal) + 1];
	strcpy(pt, animal);
	delete[] pt;

	// new를 사용한 동적 구조체의 생성
	// 아래 코드는 new를 사용하여 이름 없는 구조체를 생성하고, 포인터 표기를 사용하여 구조체 멤버에 접근하는 두 가지 방법을 모두 보여준다.
	struct inflatable
	{
		char name[20];
		int age;
	};

	inflatable* pps = new inflatable;
	std::cin.get(pps->name, 20); // 멤버에 접근하는 방법 1
	std::cin >> (*pps).age; // 멤버에 접근하는 방법 2

	// delete로 해제한 메모리는 new로 다시 만들어서 쓸수있다.
	// 자동 공간(= 지역 공간, 스택), 정적 공간, 동적 공간 (힙)

	// new로 스택 영역에 메모리를 만들어서 쓰는건 좋은데 다 쓰고 나면 꼭 delete 해줘야한다.
	// 흔히 저지르는 실수로 인해 메모리 누수가 발생한다.
}

void ex07(void)
{
	// 변수형의 조합
	// 구조체 변수를 포인터 변수로 생성, 구조체에서 포인터 멤버를 만들어서 자기 참조, 외부참조 
	// 구조체들의 배열, 포인터 배열, 배열에 대한 포인터 등등 C와 전부 동일하다.

	struct test
	{
		int t;
		double d;
	};

	test s01, s02, s03; // 모두 구조체
	s01.t = 1; // 접근 가능
	test* pa = &s02; // 구조체에 대한 포인터
	pa->t = 1999;
	test trio[3];
	trio[0].t = 2000; // trio[0] 은 구조체
	(trio + 1)->t = 2001; // tril[1].t 와 동일
	test* ppa[3] = { &s01, &s02, &s03 };
	std::cout << ppa[1]->t << std::endl; // 접근 가능
	const test** pppa = ppa; // 배열에 대한 포인터 생성 가능
	// 더블 포인터인 이유는 배열의 원소가 포인터라서 그럼
	// auto를 쓰면 기깔나게 쉽게 사용가능
	auto ppb = ppa; // 자동으로 변수 형을 확인한다.

	// 배열의 대안
	// 1. Vector 템플릿 클래스
	// ㄴ 동적 배열인 string 클래스와 상당히 유사
	// 2. array 탬플릿 클래스
	// ㄴ 백터 클래스는 일반 배열형보다 많은 기능을 지니고 있지만, 다소 비효울적인 면이 있다.
	// 사용자가 고정된 크기의 배열만 필요할때,  일반 배열형을 사용하면 안전성과 편리성이 다소 줄어들 수 있다.
	// 그 해결 방법이 array 탬플릿 클래스
	//

	// vector
	std::vector<int> vi; // int의 0사이즈 배열을 생성
	int nnnn;
	std::cin >> nnnn;
	std::vector<double> vd(nnnn); // nnnn개의 더블 배열을 생성

	// array
	std::array<int, 3> ai; //3개의 int array 객체를 생성
	std::array<double, 2> ad = { 1.1, 1.2 }; // vector와 다르게 '2'에 변수를 써서 만들 수 는 없다.

	// C, originl C++
	double ex1[2] = { 1.1, 1.2 };

	// C++ 98 STL
	// C++ 98 버전은 초기화 하는게 불편함
	std::vector<double> ex2(2);
	ex2[0] = 1.0;
	ex2[1] = 2.0;
	
	// C++ 11 array 객체를 생성하고 초기화
	std::array<double, 2> ex3 = { 11.1, 11.2 };
	std::array<double, 2> ex4;
}