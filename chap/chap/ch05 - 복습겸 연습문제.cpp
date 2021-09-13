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

	std::cout << "��α� �Է�: ";
	while (i < array_size && std::cin >> donation[i])
	{
		average += donation[i];
		if (++i < array_size)
		{
			std::cout << "��α� �Է�: ";
		}
	}
	average = average / i;

	for (double x : donation)
	{
		if (average < x)
			count++;
	}
	
	std::cout << "��α� �Է� Ƚ��: " << i
		<< std::endl << "��α� ��� �ݾ�: "
		<< average << std::endl
		<< "��� �ݾ׺��� ū ��α� Ƚ��: " << count << std::endl;
}

void pb2(void)
{
	int income = 0;
	double tax = 0;

	std::cout << "�ҵ� �Է�: ";
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

	std::cout << "�ҵ漼: " << tax << std::endl;
}