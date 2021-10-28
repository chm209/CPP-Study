#include <iostream>
void ex01(void);

void main()
{
	// C++ 코드의 재활용
	// ※ C++가 추구하는 중요한 목표 중의 하나가 코드의 재활용성을 높이는것
	// public 상속은 한 가지 방법일뿐, 다른 방법들도 존재한다.
	// ◈ 한가지 테그닉은 다른 클래스에 속하는 객체를클래스 멤버로 사용하는것.
	// 이것을 컨테인먼트, 컴포지션 또는 레이어링이라 부른다.
	// 
	// ◈ 또 한가지 테크닉은 private 상속이나 protected 상속을 사용하는 것
	// 
	// ◈ '객체와 클래스' 에서 함수 템플릿을 공부했다. 이번에는 클래스 템플릿에 대해서 공부한다.
	// ※ 클래스 템플릿을 사용하면 클래스를 포괄적으로 정의할 수 있다.
	// 그리고 나서 그 템플릿을 사용하여, 특정한 데이터형에 맞게 정의된 특정한 클래스를 생성할 수 있다.
	ex01();
}

void ex01(void)
{
	// 객체 멤버를 가지는 클래스
	// ※ 예제 클래스를 만들어보면서 공부

	/*
	* ※ 템플릿 클래스를 어떻게 정의하는지는 나중에 배우고 우선 사용 방법을 배운다.
	* 템플릿 측면에서 보면, 객체를 선언할 때 구체적인 데이터형을 지정해야 한다.
	* 그렇게 하려면, 객체를 선언할 때 원하는 데이터형이 들어 있는 각괄호(<>) 앞에 식별자 valarray를 붙여야 한다.
	* valarray<int> q_values; // int형의 배열
	* valarray<double> weight; // double형의 배열
	* ※ 이러한 구문을 vector와 array를 공부하면서 봤다.
	* ※ 이러한 템플릿 클래스는 숫자를 지닐 수 있지만 valarray 클래스가 하는 것처럼 모든 사칙연산을 지원하지 않는다.
	* 
	* ※ C++에서 has-a 관계를 모델링하는 일반적인 테크닉은 컴포지션(컨테인먼트)을 사용하는 것이다.
	* 즉, 다른 클래스의 객체들을 멤버로 가지는 클래스를 만드는 것이다.
	* 
	* ※ 인터페이스와 구현
	* public 상속에서, 클래스는 인터페이스와 구현을 상속한다. 인터페이스를 획득하는 것은 is-a 관계의 역할이다.
	* 반면에 컨테인먼트에서는 어떤 클래스가 인터페이스 없이 구현을 획득한다. 인터페이스를 상속하지 않는 것이 has-a 관계의 역할이다.
	* 
	* ● Student 클래스 예제 (공부하면서 코드가 많이 바뀔 예정이라 책만 보고 공부)
	* ※ 표기를 단순화하기 위해 typedef를 사용
	* typedef std::valarray<double> ArrayDb;
	* 이 typedef를 클래스 정의의 private 부분에 넣은 것은, 그것이 student 클래스의 외부 사용자들에 의해서가 아니라 student 구현에 내부적으로 사용될 수 있다는 것을 의미한다.
	* 
	* ※ explict 사용
	* 프로그래머의 실수를 막기 위해 사용
	* 
	* ※ 초기화 순서
	* 하나 이상의 항목들을 초기화하는 멤버 초기자 리스트를 사용한다면, 그 항목들은 멤버 초기자 리스트에 나타나는 순서대로 초기화되지 않고, 그들이 선언된 순서대로 초기화된다.
	* 
	* ※ 헬퍼 메서드
	* 헬퍼를 사용하는 것은, 흩어진 지역적인 사항들을 한데 모으고, 프렌드 함수의 코딩을 더 간결하게 만든다.
	* 또한, 헬퍼 함수는 그 밖의 사용자 레벨 출력 함수들을 위한 빌딩 블록 역할을 할 수도 있다.
	*/

	// private 상속 (예제 코드는 작성하지 않음)
	// ※ private 상속에서는, 기초 클래스의 public 멤버와 protected 멤버가 파생 클래스의 private 멤버가 된다.
	// 즉, 기초 클래스의 메서드들이 파생 객체의 public 인터페이스의 일부가 되지 않는다. 그러나 파생 클래스의 멤버 함수들 안에서 그것들을 사용할 수 있다.
	// ※ public 상속에서는 기초 클래스의 pubic 메서드가 파생 클래스의 public 메서드가 된다. 다시말해 파생 클래스는 기초 클래스의 인터페이스를 상속한다.
	// ※ private 상속에서는 기초 클래스의 public 메서드가 파생 클래스의 private 메서드가 된다. 즉 파생 클래스는 기초 클래스의 인터페이스를 상속하지 않는다.
	// ※ private 상속에서는 클래스가 구현을 상속한다.
	// ※ 컨테인먼트는 객체를 이름이 있는 멤버 객체로 클래스에 추가한다. 반면에 private 상속은 객체를 이름이 없는 상속된 객체로 클래스에 추가한다.
	// 이 책에서는 상속에 의해 추가된 객체나, 컨테인먼트에 의해 추가된 객체를 모두 종속 객체라고 부른다.
	// ※ private 상속은 컨테인먼트와 동일한 기능을 제공한다. 즉 구현은 획득하지만 인터페이스는 획득하지 않는다.
	// ※ 기초 클래스가 하나 이상일 경우에 그것을 다중 상속이라 부른다. (multiple inheritance; MI)
	// ※ 일반적으로 MI (특히 public MI)를 사용하면, 부가적인 문법 규칙을 통해 해결해야 하는, 몇가지 문제가 발생한다.
	// ※ private 상속은 기초 클래스 메서드를 파생 클래스 메서드의 안에서만 사용할 수 있도록 제한한다.
	// ※ private 상속에서는, 클래스 이름과 사용 범위 결정 연산자를 사용하여 기초 클래스의 메서드를 호출할 수 있다.
	// 
	//  EX) 두 개의 클래스로부터 상속받는 클래스 예제
	// class Student : private std::string, private std::valarray<double>

	/*
	* ↓ 기초 클래스 객체에 접근하기
	* Student 클래스의 컨테인먼트 버전은 name 멤버인 string 객체를 리턴하게 함으로써 Name() 메서드를 구현한다.
	* private 상속에서는 데이터형 변환을 사용한다.
	* Student가 string으로부터 상속되었기 때문에, student 객체를 string 객체로 데이터 변환을 할 수 있다.
	* 예시)
	* const string & Student::Name() const { return (const string &) *this;
	* 
	* ↓ 기초 클래스 프렌드에 접근하기
	* ※ 클래스 이름을 사용하여 함수 이름을 명시적으로 지정하는 테그닉은, 프렌드 함수가 클래스에 속하지 않기 때문에 적용되지 않는다.
	* ※ 기초 클래스로 변환하는 명시적인 데이터형 변환을 사용하여 정확한 함수를 호출할 수 있다.
	* ※ private 상속에서 명시적인 데이터형 변환이 없으면 파생 클래스에 대한 참조나 포인터를 기초 클래스에 대한 참조나 포인터에 대입할 수 없기 때문이다.	
	* 
	* ● 컨테인먼트와 private 상속
	* ※ 컨테이먼트와 private 상속 둘 중 어느 하나를 사용하여 has-a 관계를 모델링할 수 있다면, 어느 것을 사용해야 할까?
	* 대부분의 개발자들은 컨테인먼트를 선호한다.
	* 1. 컨테인먼트가 사용하기 쉽기 때문
	* 2. 하나 이상의 기초 클래스로부터 클래스를 상속할 때, 상속이 문제를 일으킬 수 있기 때문
	* 
	* ※ 일반적으로 has-a 관계를 모델링하려면 컨테인먼트를 사용해야 한다. 새 클래스가 오리지널 클래스의 protected 멤버들에 접근할 필요가 있거나,
	* 가상 함수들을 다시 정의할 필요가 있을 경우에는 private 상속을 사용해야 한다.
	* 
	* ● protected 상속
	* ※ protected 상속은 private 상속의 변종이다.
	* ※ protected 상속은 기초 클래스를 나열할 때 키워드 protected를 사용한다.
	* ※ 기초 클래스의 public 멤버와 protected 멤버가 파생 클래스의 protected 멤버가 된다.
	* ※ privtate 상속과 마찬가지로, 기초 클래스의 인터페이스를 파생 클래스에서 사용할 수 있지만, 바깥 세상에서는 사용할 수 없다.
	* ※ private 상속과 protected 상속의 주된 차이점은, 파생 클래스로부터 또 다른 클래스를 파생시킬때 드러난다.
	* 1020 페이지 특성 정리 표 있음
	* 
	* 예시)
	* class Student : protected std::string, protected std::valarray<double> { ... };
	* 
	* ● using을 사용하여 접근 다시 정의하기
	* 어떤 특정 기초 클래스의 메서드를 파생 클래스에서 public 으로 사용할 수 있게 하고 싶다고 가정
	* 해결책 1. 기초 클래스 메서들르 사용하는 파생 클래스 메서드를 정의한다.
	* 해결책 2. using 선언을 사용하여, 파생 클래스에서 사용할 특정 기초 클래스 멤버를 지정한다.
	* 해결책 3. private으로 파생된 클래스에 기초 클래스 메서드들을 다시 선언 한다.
	* (파생 클래스의 public 부분에 메서드 이름을 넣는 구식 방법) -> 사용하지 말고 using을 사용할것
	*/
}