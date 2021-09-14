#include <iostream>
#include <array>

void pb1(void);
int pb1Facto(int);
void pb2(void);
void Show_list(double list[], const int list_size, int count);
void Show_list(double list[], const int list_size);
int Fill_list(double list[], const int list_size);
void Reverse_list(double list[], const int list_size);

void main(void)
{
	// pb1();
	pb2();
}

void pb1(void)
{
	int num = 0, result = 0;
	std::cout << "값 입력: ";
	if (std::cin >> num)
	{
		result =pb1Facto(num);
	}

	std::cout << result;
}

int pb1Facto(int num)
{
	static int result = num;

	if (num > 1)
	{
		result = result * (num - 1);
		return pb1Facto(num - 1);
	}
	else
		return result;
}

void pb2(void)
{	
	int count = 0;
	const int list_size = 10;
	double list[list_size] = { };

	count = Fill_list(list, list_size);
	Show_list(list, list_size, count);
	Reverse_list(list, list_size);
	Show_list(list, list_size);
}

void Reverse_list(double list[], const int list_size)
{
	for (int i = 0, j = list_size-1; i < (list_size / 2); i++, j--)
	{
		double temp = list[i];
		list[i] = list[j];
		list[j] = temp;
	}
}

void Show_list(double list[], const int list_size, int count)
{
	std::cout << "입력 받은 횟수: " << count << std::endl << " | ";
	for (int i = 0; i < list_size; i++)
	{
		std::cout << list[i] << " | ";
	}
	std::cout << std::endl;
}

void Show_list(double list[], const int list_size)
{
	std::cout << " | ";
	for (int i = 0; i < list_size; i++)
	{
		std::cout << list[i] << " | ";
	}
}

int Fill_list(double list[], const int list_size)
{
	int count = 0;
	for (int i = 0; i < 10; i++)
	{
		std::cout << i+1 << "번째 배열 요소 입력: ";
		if (!(std::cin >> list[i]))
		{
			for (int x = i; x < 10; x++)
			{
				list[x] = 0;
			}
			return count;
		}
		count++;
	}
}