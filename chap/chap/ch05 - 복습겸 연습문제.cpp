#include <iostream>
void pb1(void);
void pb2(void);

int main()
{
	// pb1();
	pb2();

	return 0;
}

void pb1(void)
{
	const int array_size = 10;
	double donation[array_size] = { };
	double long average = 0;
	int i = 0, count = 0;

	std::cout << "기부금 입력: ";
	while (i < array_size && std::cin >> donation[i])
	{
		average += donation[i];
		if (++i < array_size)
		{
			std::cout << "기부금 입력: ";
		}
	}
	average = average / i;

	for (double x : donation)
	{
		if (average < x)
			count++;
	}
	
	std::cout << "기부금 입력 횟수: " << i
		<< std::endl << "기부금 평균 금액: "
		<< average << std::endl
		<< "평균 금액보다 큰 기부금 횟수: " << count << std::endl;
}

void pb2(void)
{
	int income = 0;
	double tax = 0;

	std::cout << "소득 입력: ";
	if (std::cin >> income)
	{
		int temp_income = income;

		if (temp_income > 5000)
		{
			temp_income -= 5000;
			if (!(temp_income == 0))
			{
				if ((temp_income - 10000) <= 0)
				{
					tax += static_cast<double>(temp_income) * 0.10;
				}
				else
				{
					temp_income -= 10000;
					tax += 10000 * 0.10;
					if ((temp_income - 20000) <= 0)
					{
						tax += static_cast<double>(temp_income) * 0.15;
					}
					else
					{
						temp_income -= 20000;
						tax += 20000 * 0.15;
						if (!(temp_income == 0))
						{
							tax += static_cast<double>(temp_income) * 0.20;
						}
					}
				}
			}
		}
	}

	std::cout << "소득세: " << tax << std::endl;
}