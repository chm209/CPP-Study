#include <iostream>
void ex01(void);

int main(void)
{
	using std::cout;
	using std::endl;
	ex01();

	return 0;
}

void ex01(void)
{
	/*
	* ♠ 클래스의 활용
	
	* ♤ 연산자 오버로딩
	* ※ 연산자 오버로딩은 C++가 가진 다형 특성의 한 예이다.
	* ※ 연산자 오버로딩은 오버로딩의 개념을 연산자에까지 확장하여 C++ 연산자들에 다중적인 의미를 부여하는것이다.
	* EX) * 연산지는 주소에 저장되어 있는 값을 가져오기도 하지만 곱셈의 역할도 한다
	* ※ 연산자를 오버로딩하려면, 연산자 함수라는 특별한 함수를 사용 해야 한다.
	* operatorop(argument-list) (원형) -> 사용) operator*()
	* ※ 여기서 op는 오버로딩할 연산자를 나타내는 기호이다.
	* 
	↓ 오버로딩 제약
	* 1. 오버로딩된 연산자는, 적어도 하나의 피연산자가 사용자 정의 데이터형일 것을 요구한다.
	* 이 제약은 표준 데이터형을 위해서 사용되는 연산자들을 오버로딩하는 것을 막아 준다.
	* 그러므로 뺼셈 연산자를 두 개의 double형 값의 차가 아닌 합을 산출하도록 재정의할 수 없다.
	* 2. 오버로딩된 연산자를, 오리지널 연산자에 적용되는 문법 규칙을 위반하는 방식으로 사용할 수 없다. 마찬가지로 연산자 우선순위도 변경할 수 없다.
	* 3. 연산자 기호를 새로 만들 수 없다.
	* 4. 몇몇 연산자는 오버로딩할 수 없다. 721~722 페이지 참고
	* ※ 연산자 오버로딩을 사용할때는 신중해야 한다. 동작이 명확하지 않을때는 차라리 메서드를 정의하는게 바람직하다.
	* 
	* ♤ 프렌드
	* ※ 일반적으로 객체의 private 부분에 접근할 수 있는 유일한 통로는 public 클래스 메서드들이다.
	* ※ 함수를 어떤 클래스에 대해 프렌드로 만들면, 그 프렌드 함수는 클래스의 멤버 함수들이 가지는것과 동일한 접근 권한을 갖는다. [프렌드 함수, 프렌드 클래스, 프렌드 멤버 함수]
	* → 프렌드 생성
	* 클래스 선언에 friend 함수 원형을 넣어주면 끝
	* friend Time operator*(double m, const Time & t);
	* 1. operator*() 함수는, 클래스 선언 안에 선언되지만 멤버 함수가 아니다. 그러므로 멤버 연산자를 사용하여 호출되지 않는다.
	* 2. operator*() 함수는, 그것이 비록 멤버 함수는 아니지만 멤버 함수와 동등한 접근 권한을 가진다.
	* 함수 정의에는 friend를 쓸 필요가 없고 멤버 함수가 아니기 때문에 Time::을 쓸 필요도 없다.
	* 
	* → 프렌드 << 연산자의 오버로딩
	* trip이 time 클래스의 객체라고 가정하고 이때까지는 객체의 내용을 출력하기 위해서는 Show()를 사용했다.
	* cout <<  trip; 사용이 가능하다.
	* void operator<<(ostream & os, const Time & t)
	* { os << t.hours << "시간"; }
	* 이렇게 오버로딩하면 사용할 수 있다.
	* 단 문제점이라면 cout << "ㅁㄴㅇ" << trip; 이렇게 하면 작동하지 않는다.
	* cout << "ㅁㄴㅇ"를 처리하면 ostream 객체가 아니라서 << trip은 수행할 수 없다.
	* ostream & operator<<(ostream & os, const Time & t)
	* { 
	*		os << t.hours << "시간"; 
	*		return os;
	* }
	* 이렇게 하면 ostream 객체를 리턴해서 사용할 수 있다.
	* 
	* ♤ 오버로딩 연산자: 멤버 함수와 멤버가 아닌 함수
	* ※ 많은 연산자들에 대해서 연산자 오버로딩을 구현할 때, 멤버 함수로 구현할 것인지 멤버가 아닌 함수로 구현할 것인지를 선택해야 한다.
	* ※ 두 형식을 모두 정의하면 모호성 에러가 발생한다.
	* ※ 일부 연산자들에 대해서는 멤버 함수가 유일하고도 적절한 선택이다. 그 외에는 별차이가 없다.
	* ※ 클래스 설계에 따라서 간혹, 그 클래스에 대한 데이터형 반환을 정의했을 경우 멤버가 아닌 버전이 유리할 수도 있다.
	* 
	* ※ 오버로딩 보충
	* 1. 상태 멤버 사용, bool 타입 변수로 객체의 상태를 나타냄
	* 2. 오버로딩된 연산자 또 오버로딩하기 (두번 오버로딩 한다는 의미가 아니라, 같은 부호로 다른 동작을하게 오버로딩을 두번 한다는 뜻)
	* 예를들어 - 연산자는 두 개의 피연산자에 사용되었을 때는 뺄셈 연산자이다. (이항 연산자)
	* -x와 같이 하나의 피연산자에 사용했을때는 마이너스 부호 연산자이다. (단한 연산자)
	* operator- ()에 대해 두개의 서로 다른 정의를 만들었다면, 두 개의 정이가 서로 다른 시그내처를 사용하므로 아무런 문제가 없다.
	* !! 단 / 나눗셈 연산자와 같이 이항 형식만을 사용하는 연산자는 이항 연산자로만 오버로딩할 수 있다.
	* 
	*/
}