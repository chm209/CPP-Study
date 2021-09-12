#include <iostream>
#include <string>
#include <array>

void pb1(void);
void pb2(void);
void pb3(void);
void pb4(void);

int main()
{
	// pb1();
	// pb2();
	// pb3();
	pb4();

	return 0;
}

void pb1(void)
{
	int num1 = 0, num2 = 0, sum = 0;

	std::cout << "정수1 입력: ";
	std::cin >> num1;
	std::cout << "정수2 입력: ";
	std::cin >> num2;

	if (num1 > num2)
	{
		for (int i = num1; i >= num2; i--)
		{
			sum += i;
		}
	}
	else
	{
		for (int i = num1; i <= num2; i++)
		{
			sum += i;
		}
	}
	std::cout << "결과: " << sum << std::endl;
}

void pb2(void)
{
	std::array<long double, 16> facto;
	facto[0] = facto[1] = 1.0;

	for (int i = 2; i < 16; i++)
	{
		facto[i] = i * facto[i - 1];
	}
	for (int i = 0; i < 16; i++)
	{
		std::cout << facto[i] << std::endl;
	}		
}

void pb3(void)
{
	int count_year = 0;

	struct customer
	{
		double income;
		int principal;
	};

	customer customerA = { 0.0, 100000 };
	customer customerB = { 0.0, 100000 };

	do
	{
		customerA.income = 0.10 * customerA.principal;
		customerB.income = 0.05 * customerB.principal;
		customerB.principal += customerB.income;
		count_year++;
	} while (customerB.income < customerA.income);

	std::cout << count_year << std::endl;
}

void pb4(void)
{
	int year_sales = 0;
	int monthly_sales[12] = { };
	std::string month[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

	for (int i = 0; i < 12; i++)
	{
		std::cout << month[i] << " 판매량: ";
		std::cin >> monthly_sales[i];
		year_sales += monthly_sales[i];
	}
	std::cout << "\n연간 판매량: " << year_sales << std::endl;
}