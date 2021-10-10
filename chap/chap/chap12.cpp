#include <iostream>
#include "brass.h"
#include "tabtenn.h"
void ex01(void);
void ex02(void);
// 포맷팅 관련 (brass)
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);

TableTennisPlayer::TableTennisPlayer(const std::string& fn, const std::string& ln, bool ht)
	: firstname(fn), lastname(ln), hasTable(ht) { }

void TableTennisPlayer::Name() const
{
	std::cout << lastname << ", " << firstname;
}

// RatedPlayer 메서드
RatedPlayer::RatedPlayer(unsigned int r, const std::string& fn, const std::string& ln, bool ht) : TableTennisPlayer(fn, ln, ht)
{
	rating = r;
}

RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer& tp) : TableTennisPlayer(tp), rating(r)
{ }

// brass 메서드들
Brass::Brass(const std::string& s, long an, double bal)
{
	fullName = s;
	acctNum = an;
	balance = bal;
}

void Brass::Deposit(double amt)
{
	if (amt < 0)
	{
		std::cout << "마이너스 입금 불가, 입금 취소\n";
	}
	else
	{
		balance += amt;
	}
}

void Brass::Withdraw(double amt)
{
	format initialState = setFormat();
	precis prec = std::cout.precision(2);
	
	if (amt < 0)
	{
		std::cout << "마이너스 인출 불가, 인출 취소\n";
	}
	else if (amt <= balance)
	{
		balance -= amt;
	}
	else
	{
		std::cout << "인출 요구 금액: " << amt
			<< "가 현재 잔액을 초과함\n 인출 취소\n";
	}
}

double Brass::Balance() const
{
	return balance;
}

void Brass::ViewAcct() const
{
	format initialState = setFormat();
	precis prec = std::cout.precision(2);
	std::cout << "고객 이름: " << fullName << std::endl
		<< "계좌 번호: " << acctNum << std::endl
		<< "현재 잔액: $" << balance << std::endl;
	restore(initialState, prec); // 원래의 형삭울 복원
}

BrassPlus::BrassPlus(const std::string& s, long an, double bal, double ml, double r) : Brass(s, an, bal)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

BrassPlus::BrassPlus(const Brass& ba, double ml, double r) : Brass(ba) // 암시적 복사 생성자를 사용
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

void BrassPlus::ViewAcct() const
{
	format initialState = setFormat();
	precis prec = std::cout.precision(2);
	Brass::ViewAcct();
	std::cout << "당좌 대월 한도액: $" << maxLoan << std::endl
		<< "상환할 원리금: $" << owesBank << std::endl;
	std::cout.precision(3);
	std::cout << "당좌 대월 이자율: " << 100 * rate << "%\n";
	restore(initialState, prec);
}

void BrassPlus::Withdraw(double amt)
{
	format initialState = setFormat();
	precis prec = 0.0;
	double bal = Balance();
	if (amt <= bal)
	{
		Brass::Withdraw(amt);
	}
	else if (amt <= bal + maxLoan - owesBank)
	{
		double advance = amt - bal;
		owesBank += advance * (1.0 + rate);
		std::cout << "당좌 대월 금액: $" << advance << std::endl
			<< "당좌 대월 이자: $" << advance * rate << std::endl;
		Deposit(advance);
		Brass::Withdraw(amt);
	}
	else
	{
		std::cout << "당좌 대월 한도가 초과되어 거래가 취소 됩니다.\n";
	}
	restore(initialState, prec);
}

format setFormat()
{
	return std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format f, precis p)
{
	std::cout.setf(f, std::ios_base::floatfield);
	std::cout.precision(p);
}

void main(void)
{
	// ex01();
	ex02();
}

void ex01(void)
{
	// ◆ 클래스의 상속
	// 1. 객체 지향 프로그래밍의 중요한 목적 중 하나. 코드의 재활용
	// 2. C++는 클래스를 확장하고 수정하기 위해 클래스 상속을 제공한다.
	// 3. 기초 클래스라 부르는 클래스로부터 모든 메서드와 멤버들을 상속 받아 새로운 파생 클래스를 만든다.
	// 4. 기존의 클래스에 기능을 추가할 수 있다.
	// 5. 클래스가 나타내고 있는 데이터에 다른 것을 더 추가할 수 있다.
	// 6. 클래스 메서드가 동작하는 방식을 변경할 수 있다.

	// 간단한 기초 클래스부터 시작하자

	/*
	* 기초 클래스: 어떤 클래스를 다른 클래스로부터 상속할때, 오리지널 클래스
	* 파생 클래스: 상속 받는 클래스
	*
	* 896페이지 예제.
	* ※ C 스타일 string 구문으로 된 생성자를 사용한다.
	* TableTennisPlayer p1("asd", "asd", true);
	* ※ 그러나 생성자 선언에서 매개변수들의 타입은 const string & 형이다
	* ※ 잘못 연결된 자료형이지만, 표준 string 클래스는 const char* 형의 매개변수를 지닌 생성자를 가지고 있다.
	* ※ 그리고 이 생성자는 C 스타일 string 으로 초기화된 string 객체를 생성하기 위해 자동으로 사용된다.
	*
	* ● 클래스 파생시키기
	* ※ RatedPlayer는 TableTennisPlayer 기초 클래스로부터 파생된다.
	* class RatedPlayer : public TableTennisPlayer { ... };
	* ※ 이 표제는 TableTennisPlayer가 public 기초 클래스라는 것을 나타낸다.
	* 1. 이것을 public 파생이라고 한다.
	* 2. 파생 클래스의 객체는 기초 클래스의 객체를 합병한다.
	* 3. public 파생에서는 기초 클래스의 public 멤버들이 파생 클래스의 public 멤버가 된다.
	* 4. 기초 클래스의 private 부분들도 파생 클래스의 일부가 된다.
	* 5. 그러나 그들은 기초 클래스의 protected 메서드와 public 메서드를 통해서만 접근할 수 있다.
	*
	* ↓ 무엇을 할 수 있을까
	* ※ RatedPlayer 객체를 선언한다면, 그 객체는 다음과 같은 특별한 속성을 가진다.
	* 1. 파생 클래스형의 객체 안에는 기초 클래스형의 데이터 멤버들이 저장된다. (기초 클래스의 구현들을 상속 받는다.)
	* 2. 파생 클래스형의 객체는 기초 클래스형의 메서드들을 사용할 수 있다.
	*
	* ↓ 상속받는 기능에 무엇을 추가할 필요가 있을까
	* 1. 파생 클래스는 자기 자신의 생성자를 필요로 한다.
	* 2. 파생 클래스는 부가적인 데이터 멤버들과 멤버 함수들을 필요한 만큼 추가할 수 있다.
	*
	* ● 생성자: 접근에 대하여
	* ※ 파생 클래스는 기초 클래스의 private 멤버에 직접 접근할 수 없다. 기초 클래스의 메서드들을 통해서 접근해야 한다.
	* 1. 프로그램이 파생 클래스의 객체를 생성할 때, 먼저 기초 클래스의 객체를 생성한다.
	* 파생 클래스 생성자의 몸체 안으로 들어가기 전에, 기초 클래스 객체가 먼저 생성되어야 한다는 것을 의마한다.
	* C++는 이것을 하기 위해 멤버 초기자 리스트 문법을 사용한다.
	* RatedPlayer::RatedPlayer(unsigned int r, const char * fn, const string & ln, bool ht) : TableTennisPlayer(fn, ln, ht)
	* { rating = r; }
	*
	* 멤버 초기자 리스트를 생략한다면 기초 클래스 생성자가 틀림없이 먼저 생성될 것이다.
	* 그래서 기초 클래스 생성자를 호출하는 것을 생략하면, 프로그램은 디폴트 기초 클래스 생성자를 사용한다.
	* RatedPlayer::RatedPlayer(unsigned int r, const char * fn, const string & ln, bool ht)
	* ↓ 생략하면 아래와 같이 코드를 작성한 것과 결과가 같다.
	* RatedPlayer::RatedPlayer(unsigned int r, const char * fn, const string & ln, bool ht) : TableTennisPlayer()
	* 디폴트 생성자를 사용하기를 원하지 않는다면, 올바른 가초 클래스 생성자 호출을 명시적으로 제공해야 한다.
	*
	* 2. 두번째 생성자에 해당하는 코드
	* RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer & tp) : TableTennisPlayer(tp)
	* ※ tp는 const TableTennisPlayer & 형이기 때문에 이 호출은 기초 클래스의 복사 생성자를 호출한다.
	* ※ 복사 생성자가 필요한데 그것을 정의하지 않았을 경우에는 컴파일러가 자동으로 생성한다.
	* ※ 파생 클래스의 멤버들을 위해 멤버 초기자 리스트 문법을 사용할 수 있다. 이 경우에는 멤버 초기자 리스트에 클래스 이름 대신 멤버 이름을 사용한다.
	* RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer & tp) : TableTennisPlayer(tp), rating(r)
	*
	* ↓ 파생 클래스 생성자의 요점
	* 1. 기초 클래스 객체가 먼저 생성된다.
	* 2. 파생 클래스 생성자가 멤버 초기자 리스트를 통해 기초 클래스 생성자에 기초 클래스 정보를 제공해야 한다.
	* 3. 파생 클래스 생성자는 파생 클래스에 새로 추가된 데이터 멤버들을 초기화해야 한다.
	*
	* ● 파생 클래스 사용하기
	* ※ 각각의 클래스를 별개의 헤더 파일에 넣을 수도 있지만, 두 클래스는 서로 연계되어 있기 때문에, 클래스 선언을 함께 묶어 두는 것이 더 체계적이다.
	*
	* ● 파생 클래스와 기초 클래스의 특별한 관계
	* 1. 파생 클래스 객체는 기초 클래스 메서드들이 private이 아니면 그것들을 사용할 수 있다.
	* 2. 기초 클래스 포인터는 명시적 데이터형 변환 없이도 파생 클래스 객체를 지시할 수 있다.
	* 3. 기초 클래스 참조는 명시적 데이터형 변환 없이도 파생 클래스 객체를 참조할 수 있다.
	* ※ 그러나 기초 클래스 포인터나 참조는 기초 클래스 메서드만 호출할 수 있다.
	* ※ 일반적으로 C++는, 참조형과 포인터형이 대입되는 데이터형과 일치할 것을 요구한다. 그러나
	* 상속의 경우에는 이 규칙이 완화된다.
	* ※ 그러나 이러한 규칙 완화는 일방통행적이다. 파생 클래스의 참조와 포인터에 기초 클래스의 객체와 주소를 대입할 수 없다.
	* TableTennisPlayer p1("asd", "asd", false);
	* RatedPlayer & rr = p1; // 불가능
	* RatedPlayer * pr = p1; // 불가능
	*
	* ↓ 기초 클래스 참조와 포인터가 파생 클래스 객체를 참조할 수 있다는 사실은 몇가지 재밌는 결과를 가져온다.
	* 1. 기초 클래스 참조와 포인터를 매개변수로 사용하는 함수는, 기초 클래스 객체에도 사용할 수 있고 파생 클래스 객체에도 사용할 수 있다. (ex1)
	* 2. 기초 클래스 객체를 지시하는 포인터를 형식 매개변수로 사용하는 함수에도 같은 관계가 성립된다.
	* 3. 이와 같은 참조 호환성은 기초 클래스 객체를 파생 클래스 객체로 초기화하는 것도 간접적으로나마 허용한다. (ex2)
	*
	* EX)
	* 1. void Show(const TableTennisPlayer & rt) { }
	* ※ rt는 기초 클래스에 대한 참조이다. 따라서 rt는 기초 클래스 객체도 참조할 수 있고, 파생 클래스 객체도 참조할 수 있다.
	* 2. RatedPlayer olaf1(1840, "olaf", "asd", true);
	*	   TableTennisPlayer olaf2(olaf1);
	* ※ olaf2를 초기화하는 생성자의 원형은 다음과 같을것이다.
	* TableTennisPlayer(const RatedPlayer &); // 존재하지 않는다.
	* ※ 클래스 선언에서 이와 같은 생성자를 만들지 않았기 때문에 암시적인 복사 생성자가 그 역할을 대신한다.
	* TableTennisPlayer(const TableTennisPlayer &); // 암시적인 복사 생성자
	* ※ 형식 매개변수는 기초 클래스형에 대한 참조, 따라서 파생 클래스형을 참조할 수 있다.
	* 이 복사 생성자는 RatedPlayer 객체 olaf1안에 파묻혀 있는 TableT---player 객체로 olaf2를 초기화한다.
	* ※ 같은 논리로 파생 클래스 객체를 기초 클래스 객체에 대입할 수 있다.
	* p1 = rp1;
	*
	* ※ 이러한 경우에, 프로그램은 암시적인 오버로딩 애입 연산자를 대입에 사용한다.
	* TableTennisPlayer & operator=(const TableTennisPlayer &) const;
	* ※ 같은 논리로 기초 클래스 참조가 파생 클래스 객체를 참조한다.
	*
	*
	*/

	// 상속 is-a 관계
	//
	// 1. C++ 상속의 3가지 형식. private, protected, public
	// 2. public 상속이 가장 일반적인 형식 (is-a 관계)
	// 2-1. 파생 클래스 객체가 기초 클래스 객체이기도 하다는것을 의미
	// 3. public 클래스는 is-like-a 관계를 나타내지 않는다.
	// 4. public 클래스는 is-implemented-as-a 관계를 나타내지 않는다.
	// 4-1. 스택을 배열을 사용하여 구현할 수 있다. 그러나 Array 클래스로부터 Stack 클래스를 파생시키는 것은 옳지 않다. 스택은 배열이 아니기 때문
	// 5. public 상속은 uses-a 관계를 나타내지 않는다.
	// has-a, is-implemented-as-a, uses-a 관계를 나타내기 위해 사용하는 것을 C++언어는 제한하지 않는다.
	// 그러나 일반적으로 그렇게 하면 프로그래밍 문제가 발생한다.
	// 그러므로 is-a 관계만 사용하도록 하자.

	// public 다형 상속
	// 호출하는 객체에 따라 메서드의 행동이 달라질 수 있기 때문에, 여러가지 형식을 가지고 있다는 의미에서 그러한 복잡한 행동을 다형이라 한다.

	/*
	* ↓ public 다형 상속을 구현하는 두 가지 중요한 방법
	* 1. 기초 클래스 메서드를 파생 클레스에서 다시 정의한다.
	* 2. 가상 메서드를 사용한다.
	*
	* ※ 가상 메서드
	* 1. virtual 이라는 키워드를 사용함
	* 2. 클래스의 public 섹샨에 선언한다.
	* 3. 가상 함수는 static일 수 없으며 다른 클래스의 friend 함수가 될 수도 없다.
	* 4. 가상 함수는 실행시간 다형성을 얻기위해 기본 클래스의 포인터 또는 참조를 통해 접근 해야 한다.
	* 5. 가상 함수의 프로토타입은 기본 클래스와 파생 클래스에서 동일하다.
	* 6. 가상 소멸자는 있지만 가상 생성자는 없다.
	*
	* ※ brass.h 참고사항
	* 1. 기초 클래스, 파생 클래스 모두 ViewAcct(), Withdraw() 메서드를 선언하고 있다. 다만, 클래스마다 동작이 다르다.
	* 2. Brass 클래스는 virtual 이라는 키워드를 사용하여 가상 메서드를 생성했다.
	* 2-1. 각 클래스마다 ViewAcct 원형이 선언되었는데, 이것은 서로 독립된 두 개의 메서드 정의가 있다는 것을 알려준다.
	* 3. virtual 키워드 사용은 메서드가 객체에 의해 호출되지 않고 참조나 포인터에 의해 호출되었을 때 어느 메서드를 사용할 것인지를 결정한다.
	* 3-1. virtual 키워드를 사용했을 경우에, 프로그램은 참조나 포인터에 의해 지시되는 객체형에 기초하여 메서드를 선택한다.
	*
	* ※ 가상 함수는 참조하는 객체의 클래스에 따라 메서드를 선택해준다.
	* ※ 가상 함수들의 이런 행동은 여러모로 편리하다. 그러므로 파생 클래스에서 다시 정의되는 메서드들은, 기초 클래스에서 가상으로
	* 선언하는 것이 일반적인 관행이다.
	* ※  어떤 메서드가 기초 클래스에서 가상으로 선언되었을 때, 파생 클래스에서도 자동으로 가상 메서드가 된다.
	* 파생 클래스에서도 virtual 키워드를 사용해서 어떤 함수들이 가상인지 표시하는것이 바람직하다.
	*
	* ↓ 가상 메서드의 행동
	* 앞의 예제에서 메서드들은 포인터나 참조가 아니라 객체에 의해 호출되었기 때문에 가상 함수의 기능을 이용하지 않는다.
	* 이번 예제는 가상 메서드를 사용해본다. 예를들어 Brass와 Brassplus가 혼합된 계좌들을 다루어야 한다고 가정한다.
	* 각 객체들의 혼합을 하나의 배열에 저장하면 좋겠지만, 하나의 배열에 들어갈 항목들은 데이터형이 모두 같아야하지만,
	* Brass, BrassPlus는 두 개의 서로 다른 데이터형이다.
	* 그러나 Brass를 지시하는 포인터들의 배열을 만들 수 있다. 이 경우에 배열의 모든 원소들은 데이터형이 같다.
	* 그 이유는 public 상속 모델이 적용되고 있기 때문에 Brass를 지시하는 포인터가 Brass 객체를 지시할 수 있고 BrassPlus 객체를 지시할 수도 있기 때문
	*
	* ↓ 가상 소멸자는 왜 필요할까
	* ※ 소멸자들이 가상이 아니라면, 포인터형에 해당하는 소멸자만 호출될 것이다.
	* ※ 즉, BrassPlus 객체를 지시하는 경우에도 Brass 소멸자가 호출된다는 것을 의미한다.
	* ※ 소멸자가 가상이면, 객체형에 해당하는 소멸자가 호출된다.
	*
	*
	*
	*/

	// 파생 클래스 사용하기 예제 (91라인)
	{
		TableTennisPlayer p1("TAYEON", "KIM", false);
		RatedPlayer rp1(1140, "JIEUN", "LEE", true);
		rp1.Name();
		if (rp1.HasTable())
		{
			std::cout << " 탁구대가 있다.\n";
		}
		else
		{
			std::cout << " 탁구대가 없다.\n";
		}

		p1.Name();
		if (p1.HasTable())
		{
			std::cout << " 탁구대가 있다.\n";
		}
		else
		{
			std::cout << " 탁구대가 없다.\n";
		}

		std::cout << "이름: ";
		rp1.Name();
		std::cout << " 랭킹: " << rp1.Rating() << std::endl;
		// TTP 객체를 사용하여 RP를 초기화 한다.
		RatedPlayer rp2(1212, p1);
		std::cout << "이름: ";
		rp2.Name();
		std::cout << " 랭킹: " << rp2.Rating() << std::endl;
	}

	{
		std::cout << "\n\n";
		Brass Piggy("Porcelot Pigg", 381299, 4000.00);
		BrassPlus Hoggy("Horatio Hogg", 382288, 3000.00);
		Piggy.ViewAcct();
		std::cout << std::endl;
		Hoggy.ViewAcct();
		std::cout << std::endl;
		std::cout << "Hogg 씨의 계좌에 $1000 입금:\n";
		Hoggy.Deposit(1000.00);
		std::cout << "Hogg 씨의 현재 잔액: $" << Hoggy.Balance() << std::endl;
		std::cout << "Pigg 씨의 계좌에서 $4200 인출:\n";
		Piggy.Withdraw(4200.00);
		std::cout << "Pigg 씨의 현재 잔액: $" << Piggy.Balance() << std::endl;
		std::cout << "Hogg 씨의 계좌에서 $4200 인출:\n";
		Hoggy.Withdraw(4200.00);
		Hoggy.ViewAcct();
	}

	{
		const int CLIENTS = 4;
		std::cout << "\n\n--------------------------------------------------------\n";
		Brass* p_clients[CLIENTS];
		std::string temp;
		long tempnum;
		double tempbal;
		char kind;

		for (int i = 0; i < CLIENTS; i++)
		{
			std::cout << "고객의 이름을 입력하시오: ";
			getline(std::cin, temp);
			std::cout << "계좌번호를 입력하시오: ";
			std::cin >> tempnum;
			std::cout << "계좌 개설 잔액을 입력하시오: $";
			std::cin >> tempbal;
			std::cout << "Brass 계좌는 1, BrassPlus 계좌는 2를 입력하시오: ";
			while (std::cin >> kind && (kind != '1' && kind != '2'))
			{
				std::cout << "1 아니면 2, 둘중 하나를 입력하시오: ";
			}
			if (kind == '1')
			{
				p_clients[i] = new Brass(temp, tempnum, tempbal);
			}
			else
			{
				double tmax, trate;
				std::cout << "당좌 대월 한도를 입력: ";
				std::cin >> tmax;
				std::cout << "당좌 대월 이자율을 소수점 형식으로 입력하시오: ";
				std::cin >> trate;
				p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
			}
			while (std::cin.get() != '\n')
			{
				continue;
			}
		}
		std::cout << std::endl;
		for (int i = 0; i < CLIENTS; i++)
		{
			p_clients[i]->ViewAcct();
			std::cout << std::endl;
		}

		for (int i = 0; i < CLIENTS; i++)
		{
			delete p_clients[i];
		}
	}
}

void ex02(void)
{
	// 정적 결합과 동적 결합
	// ※ 소스코드에 있는 함수 호출을 특정 블록에 있는 함수 코드를 실행하는 뜻으로 해석하는것을 "함수 이름을 결합 한다" 라고 한다.
	// ※ C, C++ 컴파일러는 이와 같은 종류의 결합을 컴파일하는 동안에 수행할 수 있다.
	// ※ 컴파일하는 동안에 일어나는 결합을 정적 결합 또는 초기 결합이라 한다.
	// ※ 가상 함수를 사용하면 사용자가 객체를 결정하기 때문에, 컴파일하는 동안에는 그 객체가 어떤 종류인지 알 수 없다.
	// 그러므로 컴파일러는 프로그램을 실행할 때 올바른 가상 메서드가 선택되도록 하는 코드를 만들어야 한다.
	// ※ 이 작업을 동적 결합, 말기 결합이라고 한다.

	/*
	* ● 포인터와 참조형의 호환
	* ※ C++에서 동적 결합은 포인터와 참조에 의해 호출되는 메서드와 관련되어 있다.
	* ※ 부분적으로 상속 과정에 의해 지배를 받는다.
	* ※ 일반적으로 C++는 한 데이터형의 주소를 다른 데이터형의 포인터에 대입하는 것을 허락하지 않는다.
	* 또한 한 데이터형에 대한 참조가 다른 데이터형을 참조하는 것도 허용하지 않는다.
	* ※ 기초 클래스를 지시하는 포인터나 참조는 명시적인 강제 데이터형 변환 없이도 파생 클래스 객체를 참조할 수 있다.
	* ※ 파생 클래스 참조나 포인터를 기초 클래스 참조나 포인터로 변환하는 것을 업캐스팅 이라 한다.
	* ※ 기초 클래스 포인터나 참조를 파생 클래스 포인터나 참조로 변환하는 것을 다운캐스팅이라 한다.
	* ※ 다운 캐스팅은 명시적인 데이터형 변환 없이는 허용되지 않는다.
	* ※ 암시적 업캐스팅은 기초 클래스 포인터나 참조가 기초 클래스 객체나 파생 클래스 객체를 참조하는 것을 가능하게 만든다.
	* 
	* ● 가상 멤버 함수와 동적 결합
	* ※ 컴파일러는 가상이 아닌 함수들에 대해서는 정적 결합, 가상 함수에 대해서는 동적 결합을 사용한다.
	* ※ 대부분의 경우 동적 결합이 더 좋다.
	* 
	* 1. 왜 두 종류의 결합이 필요한가? 왜 정적 결합이 디폴트인가?
	* ※ 동적 결합은 클래스 메서드들을 다시 정의하는 것을 허용하지만, 정적 결합은 그것을 허용하지 않지만 효율성과 개념 모델이라는 두 가지 이유 때문에 필요하다.
	* 
	* 2. 가상 함수는 어떻게 동작하는가?
	* ※ 컴파일러가 가상 함수를 다루는 일반적인 방법은 각각의 객체에 숨겨진 멤버를 하나씩 추가하는 것이다.
	* 숨겨진 멤버는 함수의 주소들로 이루어진 배열을 지시하는 포인터를 저장한다. 일반적으로 그 배열을 가상 함수 테이불 (vtbl)이라 한다.
	* ※ 가상 함수를 사용하면 메모리와 속도 면에서 다음과 같은 약간의 부담이 따른다.
	* 1. 각 객체의 크기가 주소 하나를 저장하는 데 필요한 양만큼 커진다.
	* 2. 각각의 클래스에 대해, 컴파일러는 가상 함수들의 주소로 이루어진 하나의 테이블을 만든다.
	* 3. 각각의 함수 호출에 대해, 실행할 함수의 주소를 얻기 위해 테이블에 접근하는 가외의 단계가 더 필요하다.
	* ※ 가상이 아닌 함수들은 가상 함수보다 조금 더 효율적이지만, 동적 결합을 제공하지 않는다는 사실을 명심하자.
	* 
	* ● 가상 메서드에 대해 알아야 할 사항
	* ※ 이번 챕터에서 공부했던 내용 한번 정리
	* 
	* 1. 기초 클래스에서 클래스 메서드를 선언할 때 키워드 virtual로 시작하면, 그 함수는 기초 클래스, 기초 클래스에서 파생된 클래스, 파생 클래스에서 다시 파생된 클래스등 모든 클래스에 대해 가상이 된다.
	* 2. 객체에 대한 참조를 사용하여 또는 객체를 지시하는 포인터를 사용하여 가상 메서드가 호출되면, 프로그램은 그 참조나 포인터형을 위해 정의된 메서드를 사용하지 않고 객체형을 위해 정의된 메서드를 사용한다.
	* 이것을 동적 결합이라 한다. 기초 클래스 포인터나  참조가 파생 클래스 객체를 지시하는 것은 항상 가능하기 때문에 이와 같은 행동은 중요하다.
	* 3. 상속을 위해 기초 클래스로 사용할 클래스를 정의할 때, 파생 클래스에서 다시 정의해야 하는 클래스 메서드들은 가상 함수로 선언해야 한다.
	* 
	* ↓ 생성자
	* ※ 생성자는 가상으로 선언할 수 없다.
	* 
	* ↓ 소멸자
	* ※ 클래스가 기초 클래스로 사용된다면, 소멸자는 가상으로 선언해야 한다.
	* ※ 일반적으로, 소멸자가 필요 없는 기초 클래스라 하더라도 가상 소멸자를 제공해야 한다.
	* 
	* ↓ 프렌드
	* ※ 프렌드는 가상 함수가 될 수 없다.
	* 
	* ↓ 가상 함수를 다시 정의하지 않으면
	* ※ 파생 클래스가 (가상이든 아니든) 함수를 다시 정의하지 않으면, 파생 클래스는 그 함수의 기초 클래스 버전을 사용한다.
	* ※ 파생 클래스가 길게 이어진 파생 사슬의 일부라면, 그 파생 클래스는 그 함수의 가장 최근에 정의된 버전을 사용한다.
	* ※ 기초 클래스 버전이 은닉되어 있는 경우에는 예외이다.
	* 
	* ↓ 가상 함수를 다시 정의하면 메서드가 은닉된다. (940페이지)
	* ※ 새로운 정의는 매개변수를 사용하지 않는 showperks() 함수를 정의한다. 이것은 오버로딩된 두 개의 함수 버전을 생성하지 않는다.
	* ※ 예제의 재정의는 int형 매개변수를 사용하는 기초 클래스 버전을 가린다. 다시 말해 상속된 메서드를 다시 정의하는 것은 오버로딩의 변종이 아니다. 
	* ※ 어떤 함수를 파생 클래스에서 다시 정의하면, 동일한 함수 시그내처를 가지고 있는 기초 클래스 선언만 가리는 것이 아니라 매개변수 시그내쳐와는 상관 없이 같은 이름을 가진 모든 기초 클래스 메서드들을 가린다.
	* ※ 위의 이유로 두가지 규칙이 성립된다.
	* 1. 상속된 메서드를 재정의할 경우에는 오리지널 원형과 정확히 일치시킬 필요가 있다.
	* 1-1. 예외가 있다면 리턴형이 기초 클래스에 대한 참조나 포인터인 경우에 파생 클래스에 대한 참조나 포인터로 대체될 수 있다.
	* 리턴형이 클래스형과 병행하여 바뀌는 것을 허용하기 때문에 이 기능을 리턴형의 공변이라 한다.
	* 2. 기초 클래스 선언이 오버로딩되어 있다면, 파생 클래스에서 모든 기초 클래스 버전들을 재정의해야 한다.
	* 
	* 
	* 
	*/

}