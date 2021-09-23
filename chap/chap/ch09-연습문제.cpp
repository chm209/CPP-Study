#include <iostream>
#include <string>
#include <cstring>
void pb1(void);
void pb2(void);
void pb3(void);

typedef unsigned long customer;

class Bank_account
{
private:
	char name[40];
	std::string account_num;
	double balance;
public:
	// C2572 컴파일러 오류. redefinition of default argument
	// 기본 매개 변수는 다시 정의할 수 없습니다. 매개 변수에 다른 값을 지정 해야 하는 경우에는 기본 매개 변수를 정의 하지 않은 상태로 두어야 합니다.
	// 함수의 선언과 정의를 나눠서 구현할때 디폴트 매개변수를 양쪽 모두 쓰면 에러가 발생한다.
	// 선언에 디폴트 매개변수를 쓰고 정의에도 쓸 경우 디폴트 값이 다를 경우를 막기 위한 에러인듯함
	Bank_account(const char* client, std::string account_num, double balance);
	void show(void);
	void deposit(double cash);
	void withdrawal(double cash);
};

Bank_account::Bank_account(const char* client, std::string account_num, double balance = 0.0)
{
	strcpy_s(this->name, client);
	this->account_num = account_num;
	this->balance = balance;
}

void Bank_account::show()
{
	std::cout << "이름: " << this->name << std::endl
		<< "계좌번호: " << this->account_num << std::endl
		<< "잔액: " << this->balance << std::endl;
}

void Bank_account::deposit(double cash)
{
	this->balance += cash;
}

void Bank_account::withdrawal(double cash)
{
	this->balance -= cash;
}

class Person
{
private:
	static const short LIMIT = 25;
	std::string last_name;
	char fisrt_name[LIMIT];
public:
	Person();
	Person(const std::string& last_name, const char* first_name);
	void Show() const;
	void Formal_show() const;
};

Person::Person()
{
	this->last_name = "EMPTY DATA";
	this->fisrt_name[0] = '\0';
}

Person::Person(const std::string& last_name, const char* first_name = "TAEYEON")
{
	this->last_name = last_name;
	strcpy_s(this->fisrt_name, first_name);
}

void Person::Show() const
{
	std::cout << this->fisrt_name << " " << this->last_name << std::endl;
}

void Person::Formal_show() const
{
	std::cout << this->last_name << ", " << this->fisrt_name << std::endl;
}

class Stack
{
private:
	char name[35];
	customer income = 0;
	customer payment = 0;
public:
	Stack(const char* fullname);
	~Stack();
	void pay(customer cash);
};

Stack::Stack(const char* fullname)
{
	strcpy_s(this->name, fullname);
}

Stack::~Stack()
{
	this->income = this->payment;
	std::cout << "소멸자 호출" << std::endl;
	std::cout << this->name << std::endl
		<< this->income << std::endl;
}

void Stack::pay(customer cash)
{
	this->payment += cash;
}

int main()
{
	// pb1();
	// pb2();
	pb3();
	return 0;
}

void pb1()
{
	Bank_account client("CHM209", "12345-67890", 100.501);
	client.show();
	client.deposit(1000);
	client.show();
	client.withdrawal(10.10);
	client.show();
}

void pb2()
{
	Person one;
	Person two("KIM");
	Person three("KIM", "YONGSUN"); 
	one.Show();
	one.Formal_show();
	std::cout << std::endl;
	two.Show();
	two.Formal_show();
	std::cout << std::endl;
	three.Show();
	three.Formal_show();
}

void pb3()
{
	struct customer
	{
		char fullname[35];
		double payment;
	};
	{
		customer kim;
		strcpy_s(kim.fullname, "YONGSUN");
		Stack one(kim.fullname);
		for (int i = 0; i < 5; i++)
		{
			std::cout << "지불 금액: ";
			std::cin >> kim.payment;
			one.pay(kim.payment);
		}
	}
}