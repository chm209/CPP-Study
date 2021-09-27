#include <iostream>

class StringBad
{
private:
	char* str; // 문자열을 지시하는 포인터
	int len; // 문자열의 길이
	static int num_strings; // 객체의 수
	// static 멤버변수를 만들면 클래스 객체가 몇개가 만들어지든 num_strings는 하나만 만들어진다. 그 하나를 객체들이 서로 공유한다.
public:
	StringBad(const char* s);
	StringBad();
	~StringBad();
	friend std::ostream& operator<<(std::ostream& os, const StringBad& st);
};

int StringBad::num_strings = 0;
// static 멤버 변수는 클래스 선언 안에서 초기화할 수 없다.
// static 멤버 변수는 class 밖에서 독립적으로 초기화한다.
// static 클래스 멤버가 객체의 일부분으로 저장되는 것이 아니라 별도로 저장되기 때문

StringBad::StringBad(const char* s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
	std::cout << num_strings << ": " << str << "\" 객체 생성\n";
}

StringBad::StringBad()
{
	len = 4;
	str = new char[4];
	std::strcpy(str, "C++");
	num_strings++;
	std::cout << num_strings << ": " << str << "\" 디폴트 객체 생성\n";
}

StringBad::~StringBad()
{
	std::cout << "\"" << str << "\" 객체 파괴, ";
	--num_strings;
	std::cout << "남은 객체 수: " << num_strings << "\n";
	delete[] str;
}
// delete[] str;이 있는 이유는 파괴자를 호출해도 객체의 멤버인 포인터가 지시하는 메모리는 자동으로 해제하지 않기 때문에 호출한다.

std::ostream& operator<<(std::ostream& os, const StringBad& st)
{
	os << st.str;
	return os;
}

int main(void)
{
	// ◆ 클래스와 동적 메모리 대입
	// → new와 delete를 클래스와 함께 사용하는 방법, 동적 메모리를 사용할 때 일어날 수 있는 몇가지 미묘한 문제들을 처리하는 방법을 알아본다.
	// → 간단해 보이지만 생성자 설계, 파괴자 설계, 연산자 오버로딩에 영향을 미친다.

	// 동적 메모리와 클래스
	// → C++의 메모리 대입 전략은 사용할 메모리의 크기를 컴파일할 때 결정하지 않고 프로그램을 실행할 때 상황에 따라 융통성 있게 결정하는 것이다.
	
	/* 복습과 static 클래스 멤버
	* 1. 짧은 코드를 통한 new와 delete의 복습
	* 2. static 클래스 멤버라는 새로운 기억 공간
	* § 예제로 사용) StringBad와 String 클래스 객체들은 문자열을 지시하는 하나의 포인터와 그 문자열의 길이를 나타내는 하나의 값을 가질 것이다.
	* 
	* ● 특별 멤버 함수
	* ※ StringBad 클래스가 일으키는 문제점들은 자동으로 정의된 특별 멤버 함수 때문에 일어나는 것이다.
	* ※ 즉, 특별 멤버 함수의 행동이 StringBad 클래스 설계에 어울리지 않기 때문에 그러한 문제가 발생하는 것이다.
	* ※ C++는 아래와 같은 멤버 함수를 자동으로 제공한다.
	* 1. 생성자를 전혀 정의하지 않았을 경우 디폴트 생성자
	* 2. 디폴트 파괴자를 정의하지 않았을 경우 디폴트 파괴자
	* 3. 복사 생성자를 정의하지 않았을 경우 복사 생성자
	* 4. 대입 연산자를 정의하지 않았을 경우 대입 연산자
	* 5. 주소 연산자를 정의하지 않았을 경우 주소 연산자
	* 
	* C++11이 제공하는 추가적인 멤버 함수 (추후 C++ 표준 공부에서 설명)
	* 1. move 생성자
	* 2. move 대입 연산자
	* 
	* 
	* 
	* 
	* 
	* 
	* 
	* 
	*/

	return 0;
}