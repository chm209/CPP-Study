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
	// C2572 �����Ϸ� ����. redefinition of default argument
	// �⺻ �Ű� ������ �ٽ� ������ �� �����ϴ�. �Ű� ������ �ٸ� ���� ���� �ؾ� �ϴ� ��쿡�� �⺻ �Ű� ������ ���� ���� ���� ���·� �ξ�� �մϴ�.
	// �Լ��� ����� ���Ǹ� ������ �����Ҷ� ����Ʈ �Ű������� ���� ��� ���� ������ �߻��Ѵ�.
	// ���� ����Ʈ �Ű������� ���� ���ǿ��� �� ��� ����Ʈ ���� �ٸ� ��츦 ���� ���� �����ε���
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
	std::cout << "�̸�: " << this->name << std::endl
		<< "���¹�ȣ: " << this->account_num << std::endl
		<< "�ܾ�: " << this->balance << std::endl;
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
	std::cout << "�Ҹ��� ȣ��" << std::endl;
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
			std::cout << "���� �ݾ�: ";
			std::cin >> kim.payment;
			one.pay(kim.payment);
		}
	}
}