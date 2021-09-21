#include<iostream>
#include<string>
void ex01(void);

class Stock
{
private:
	std::string company;
	long shares;
	long double test;
	double d;
	double d1;
	double d2;
	double d3;
	double d4;
	double d5;
	double d6;
public:
	/* 생성자가 모호하면 컴파일 에러 발생
	Stock() // 기본 생성자
	{
		company = "CHM";
		shares = 0;
		d = 0.0;
	}

	Stock(const std::string c, long s, double d) // 매개변수 있는 생성자
	{
		Stock::company = c;
		Stock::shares = s;
		Stock::d = d;
	}
	*/

	Stock(const std::string c = "hi", long ss = 10, double dd = 7.6) // 생성자 매개변수 디폴트 값
	{
		Stock::company = c;
		Stock::shares = ss;
		Stock::d = dd;
		Stock::d1 = dd;
		Stock::d2 = dd;
		Stock::d3 = dd;
		Stock::d4 = dd;
		Stock::d5 = dd;
		Stock::d6 = dd;
		Stock::test = 5465;
	}

	~Stock() // 파괴자
	{
		std::cout << "뵤뵤뵤" << std::endl;
	}

	void show();
};

void Stock::show()
{
	std::cout << "뵤" << std::endl;
	std::cout << company << std::endl;
	std::cout << shares << std::endl;
	std::cout << d << std::endl;
}

int main(void)
{
	ex01();
}

void ex01(void)
{
	/*
	*  ◈ 객체와 클래스
	* ※ OOP는 프로그램 설계 방법의 하나이다.
	* 1. 추상화
	* 2. 캡슐화와 데이터 은닉
	* 3. 다형
	* 4. 상속
	* 5. 코드의 재활용
	* 
	* ♠ 추상화와 클래스
	* ※ 정보를 사용자 인터페이스로 표현화는것
	* 
	* ↓ C++의 클래스
	* ※ 추상화를 사용자 정의 데이터형으로 변환해 주는 C++의 수단이다.
	* ※ 클래스는 데이터 표현과 데이터를 조작하는 메서드들을 하나의 패키지 안에 결합한다.
	* ※ 클래스 서술은 두 부분으로 이루어진다.
	* 1. 클래스 선언:	데이터 멤버와 public 인터페이스, (메서드라고 부르는) 멤버 함수를 이용하여 데이터 표현을 서술한다.
	* 2. 클래스 메서드 정의: 클래스 멤버 함수가 어떻게 구현 되는지를 서술한다.
	* ※ 클래스 선언은 클래스의 개용를 제공하는것, 메서드 정의는 세부 사항을 제공하는것
	* 인터페이스: 두 시스템 간의 상호 작용을 위한 공통된 프레임워크
	* ↓↓ 접근제어
	* ※ private, public / 클래스 멤버에 대한 접근 제어를 서술한다.
	* 1. 특정 클래스의 객체를 사용하는 프로그램은 그 객체의 public 부분에는 직접 접근할 수 있다.
	* 2. public 멤버 함수를 통해서만 그 객체의 private 멤버에 접근할 수 있다.
	* 3. public 멤버 함수는 객체와 프로그램 사이의 인터페이스를 제공한다.
	* ※ 프로그램이 데이터에 직접 접근하지 못하게 차단하는것을 데이터 은닉이라 한다.
	* ※ 데이터 은닉은 데이터에 직접 접근하지 못하게 막아 줄 뿐만 아니라. 데이터 표현이 어떻게 되어 있는지에 대해 클래스 사용자가 신경쓰지 않도록 해준다.
	* ↓↓ 멤버 접근 제어: public 또는 private
	* 1. 일반적으로 데이터 항목들은 private 부분에 선언된다.
	* 2. 클래스 인터페이스를 구성하는 멤버 함수들은 public 부분에 선언된다.
	* 3. 클래스 객체에 대한 디폴트 접근 제어가 private로 지정되어 있기 때문에 클래스 선언에서 키워드 private는 없어도 된다.
	* 
	* ↓ 클래스 멤버 함수의 구현
	* ※ 멤버 함수의 정의는 일반 함수를 정의하는 것과 거의 같다.
	* ※ 각각 하나의 함수 머리와 하나의 함수 몸체를 가진다.
	* 1. 멤버 함수를 정의할 때, 그 멤버 함수가 어느 클래스에 속하는지를 나타내기 위해 사용 범위 결정 연산자를 사용해야 한다.
	* 2. 클래스 메서드는 그 클래스의 private 부분에만 접근할 수 있다.
	* 
	*  void exam::update(int num)
	* ※ exam 클래스의 멤버 함수인 update()를 정의
	* ※ 다른 클래스에 속해 있는 멤버 함수에 동일한 함수 이름을 사용할 수 있다.
	* ※ void exam2::update() 가능
	* 
	* ♠ 클래스 생성자와 파괴자
	* ※ 클래스 생성자: 새로운 객체를 생성하고 그들의 데이터 멤버에 값을 대입해준다.
	* ※ 생성자의 이름은 클래스의 이름과 같다.
	* ※ 생성자는 리턴값이 없음에도 void형으로 선언하지 않는다, 생성자에는 데이터형을 선언하지 않는다.
	* 
	* Stock hi = { "chm", 100, 20.1 }; → 데이터들이 private라서 직접 접근 불가
	* 
	* ※ 파괴자: delete와 비슷한 의미
	* ※ new를 사용하지 않으면 아무 일도 하지 않는 암시적인 파괴자를 컴파일러가 생성한다.
	* ※ 일반적으로 사용자가 코드에 명시적으로 파괴자를 호출하면 안 된다.
	* ※ 자동으로 호출함
	*/

	Stock test; // 디폴트 생성자 사용
	test.show();

	Stock test2("Hello", 10, 0.8);
	test2.show();
	std::cout << "메모리 크기: " << sizeof(test2) << std::endl;

	Stock* pointerNew = new Stock;
	pointerNew->show();
	std::cout << "메모리 크기: " << sizeof(pointerNew) << std::endl;;
	delete pointerNew;
}