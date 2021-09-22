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
		this->company = c;
		Stock::shares = ss;
		this->d = dd;
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
		std::cout << "파괴자" << std::endl;
	}

	void show();
	void topval();
};

void Stock::topval()
{

}

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
	* ※ 클래스도 헤더 파일에 원형을 적고 cpp 파일에 정의를 한다.
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

	/*
	* ↓↓ const 멤버 함수
	* const Stock land = Stock("test");
	* land.show();
	* ※ 컴파일러는 두번째 라인에서 에러를 발생시킨다.
	* ※ const라서 변경하면 안 되는 호출 객체를 show()에 해당하는 코드가 수정하지 않는다는 보장이 없기 때문
	* ※ 이를 해결하는 방법은 show() 함수 선언과 정의에 const를 추가한다.
	* void show() const; // 호출 객체를 변경하지 않는다고 약속한다.
	* void Stock::show() const; // 호출 객체를 변경하지 않는다고 약속한다.
	* ※ 이 방식으로 선언되고 정의된 클래스 함수들을 const 멤버 함수라고 한다.
	* 
	* ♠ 객체 들여다보기, this 포인터
	* ※ 하나의 메서드가 두 개의 객체를 동시에 처리할 필요가 있다.
	* ※ 이를 위해 this라는 특별한 포인터를 제공한다.	
	* ※ this는 그 객체의 주소
	* 
	* 1. this는 항상 호출된 객체(인스턴스)를 가리킨다.
	int main()
	{ 
		Simple A(1); // =Simple A(&A, 1); -> Simple 클래스의 생성자 내부에서: this = &A
		Simple B(2); // =Simple B(&B, 2); -> Simple 클래스의 생성자 내부에서: this = &B
		A.SetID(3); // =A.SetID(&A, 3); -> 멤버 함수 SetID 내부에서: this = &A
		B.SetID(4); // =B.SetID(&B, 4); -> 멤버 함수 SetID 내부에서: this = &B
		return 0;
	} 
	* 2. 명시적으로 this를 참조해야 하는 경우가 있다.
	class Something 
	{ 
	private: 
		int data;
	public: 
		Something(int data) 
		{ 
			this->data = data;
			// this->data는 멤버 변수이고,
			// data는 매개 변수
		} 
	};
	* 3. 멤버 함수 체이닝 기법
	* calc.Add(5).Sub(3).Mul(4); 이런게 가능함
	* 
	* ♠ 객체 배열
	* ※ 객체 배열은 표준 데이터형의 배열을 선언하는 것과 완전히 동일한 방법으로 선언한다.	
	* ※ 생성자를 사용하여 배열 원소들을 초기화 할 수 있다. 그러한 경우에 각각의 원소에 대해 생성자를 호출해야 한다.
	*/

	Stock mystuff[4] = {
		Stock("Hello1", 10, 0.8),
		Stock("Hello2", 20, 1.8),
		Stock(),
		Stock("Hello4", 40)
	};
	
	mystuff[0].show();
	mystuff[1].show();
	mystuff[2].show();
	mystuff[3].show();

	/*
	* ♠ 클래스 사용 범위
	* ※ 클래스 사용 범위는 클래스 데이터 멤버들의 이름이나 클래스 멤버 함수들의 이름과 같이, 클래스 안에서 정의되는 이름들에 적용된다.
	* ↓ 클래스 사용 범위 상수
	* ※ 클래스를 선언하는 것은 객체가 어떻게 생겼는지 서술하는 것이지, 그 객체를 생성하는 것은 아니라서 에러가 발생한다.
	class test
	{
	private:
		const int num = 10; // 에러 발생
		double costs[num]; 
	};
	* ※ 동일한 효과를 내는 두 가지 방법
	* 1. 클래스 안에 열거체를 선언할 수 있다.
	* ※ 클래스 선언 안에 주어지는 열거체는 클래스 사용 범위를 가진다.
	* ※ 따라서 열거체를 사용함으로써 클래스 사용 범위를 가지는 기호 이름들을 정수 상수들에 제공할 수 있다.
	class Bakery
	{
	private:
		enum { Months = 12 };
		double consts[Months];
	};
	* ※ 이러한 방식으로 열거체를 선언하는 것은, 클래스 데이터 멤버를 생성하지 않는다.
	* ※ 즉, 개별적인 각 객체는 그 안에 열거체를 담지 않는다.
	* 2. static을 사용하여 클래스 안에 상수를 정의할 수 있다.
	class Bakery
	{
	private:
		static const int Months = 12;
		double costs[Months];
	};
	* ↓ 범위가 정해진 열거
	* enum  egg {Small, Medium}
	* enum shirt {Small, Medium}
	* ※ 이렇게 하면 오류가 생긴다, 항목이 둘다 같아서
	* 1. C++11에서는 enum에 class 범위를 갖게 함으로써 해결했다.
	* enum class egg {Small, Medium}
	* enum class shirt {Small, Medium}
	* 2. class 대신 struct를 사용할 수 있다.
	* egg choice = egg::Small;
	* shirt red = shirt::Small;
	* 
	* ♠ 추상화
	* ※ 데이터 추상화는 데이터 객체의 명세(스펙, 사양)와 구현을 분리하는 것이다.
	* ※ TV 가 어떠한 기능들을 수행할 수 있는지는 알지만 구체적으로 그 기능이 어떻게 구현되는지는 소비자가 알 필요가 없다. 그냥 이 TV가 어떤 기능들이 있는지만 알면 됨!
	* 
	* ♠ 캡슐화
	* ※ 데이터 캡슐화는 데이터 객체가 어떻게 규현되었는지를 상세한 내용을 외부로부터 감추는 것이다.
	* ※ 생상자는 TV의 내부 구조에 대해 알 필요가 있지만 소비자는 TV의 내부 구조에 대해 알 필요도 없고 볼 필요도 없다.
	* 
	* ♠ 캡슐화 추상화 장점
	* 1. 이해하기 쉽고 수정하기 쉽다.
	*	ㄱ. 즉 관리하기가 편하다.
	*	ㄴ. 복잡한 부분은 분리되고 숨겨져 있으니 이해하기 쉽고 정확하게 어떤 기능들이 있는지만 명시되어 있으니 수정하기도 쉽다.
	* 2. 재사용이 편리하다.
	* 3. 프로그램의 효율을 높혀준다.
	* 
	* ♠ 추상 자료형
	* ※ 객체와 연산의 사양이 객체의 표현과 연산의 구현으로부터 분리 되도록 구성된 자료형
	* ※ 추상화 단계에서는 오직 스펙만 다룬다.
	* 정수: int long 등등 실존하는 정수 객체들의 추상화
	* - 정수라면 더하기, 빼기, 비교  등 연산을 가짐
	* 목록: 영화 평점 목록, 환자 리스트 등의 추상화
	* - 출력, 삽입 삭제 편집 등의 연산을 가짐
	* 
	* ♠ 인터페이스 
	* 프로그래밍 언어로 쓰여진 자료형의 명세서
	* 
	* 
	* 위임 생성자라는게 있다.
	* Stock() : Stock("asd", 0, 0.0)
	* {}
	* 이렇게 쓴다는데 굳이 이렇게 쓸 이유가 있나 싶다.
	* 저렇게 쓰느니 멤버 함수 하나 만들고 생성자 호출할때 그 함수를 호출하는 방법을 쓰겠다.
	* 다만, 쓸 이유는 아직 모르겠다.
	* 
	* https://ansohxxn.github.io/cpp/chapter8-5/
	* https://boycoding.tistory.com/248
	*/
}

