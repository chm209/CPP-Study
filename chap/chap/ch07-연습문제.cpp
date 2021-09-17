#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

// 함수 매개변수에 구조체 참조가 들어갈경우 구조체 선언을 함수 원형보다 미리 해야한다.
struct candybar
{
	char trademark_name[50];
	double weight;
	int calorie;
};

struct stringy
{
	char* str;
	int ct;
};

void pb1(void);
void pb1Func(char* str, int func_count = 0);
void pb2(void);
void pb2Func(candybar& x, const char* name = "Millennium Munch", double weight = 2.85, int calorie = 350);
void pb2FuncShow(candybar& t);
void pb3(void);
void pb3Func(std::string& str);
void pb4(void);
void set(stringy& beany, char testing[]);
void show(stringy& beany, int n = 1);
void show(const char* testing, int n = 1);
void pb5(void);
template <typename T>
T max5(T list[5]);
void pb6(void);
template<typename T>
T maxn(T list[], int list_size);
template<> const char* maxn(const char* str[], int n);
void pb7(void);
template <typename T>
T showArray(T arr[], int n);

template <typename T>
T showArray(T* arr[], int n);

struct debts
{
	char name[50];
	double amount;
};

void main()
{
	// pb1();
	// pb2();
	// pb3();
	// pb4();
	// pb5();
	// pb6();
	pb7();
}

void pb1(void)
{
	char str[20] = "Hello, world";

	for (int i = 0; i < 2; i++)
	{
		if (i != 0)
		{
			pb1Func(str, i);
		}
		else
		{
			pb1Func(str);
		}
	}
}

void pb1Func(char* str, int func_count)
{
	if (func_count != 0)
	{
		for (int i = 0; i < func_count; i++)
		{
			std::cout << str << " 호출 횟수: " << i+1 << std::endl;
		}
	}
	else
	{
		std::cout << str << std::endl;
	}
}

void pb2(void)
{
	candybar x;
	pb2Func(x);
	pb2FuncShow(x);
}

void pb2Func(candybar & x, const char* name, double weight, int calorie)
{
	strcpy_s(x.trademark_name, name);
	x.weight = weight;
	x.calorie = calorie;
}

void pb2FuncShow(candybar& t)
{
	std::cout << t.trademark_name << std::endl
		<< t.weight << std::endl << t.calorie << std::endl;
}

void pb3(void)
{
	std::string str;
	pb3Func(str);
}

void pb3Func(std::string& str)
{
	int count = 0;
	do
	{
		count = 0;
		std::cout << "문자열을 입력하시오 (끝내려면 q): ";
		std::getline(std::cin, str);
		for (char& x : str)
		{
			if (isupper(x) == 0 && x != 'q' )
			{
				str[count] = toupper(x);
			}
			count++;
		}
		std::cout << str << std::endl;
	} while (str[0] != 'q' || count != 1);
}

void pb4(void)
{
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";

	set(beany, testing);
	show(beany);
	show(beany, 2);
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	show("Done!");
}

void show(stringy& beany, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << beany.str << std::endl;
	}
}

void show(const char* testing, int n)
{
	for (int i = 0; i < strlen(testing); i++)
	{
		std::cout << testing[i];
	}
	std::cout << std::endl;
}

void set(stringy & beany, char testing[])
{
	beany.str = new char[strlen(testing)];
	beany.str = testing;
	beany.ct = strlen(beany.str);
}

void pb5(void)
{
	int list1[5] = { 4,5,2,3,1 };
	double list2[5] = { 1.1, 5.5, 3.3, 2.2, 4.4 };
	int int_max = max5(list1);
	double double_max = max5(list2);

	std::cout << int_max << std::endl << double_max << std::endl;
}

template <typename T>
T max5(T list[5])
{
	T max;
	max = list[0];
	for (int i = 0; i < 5; i++)
	{
		if (max < list[i + 1])
		{
			max = list[i + 1];
		}
	}
	return max;
}

void pb6(void)
{
	int list1[10] = { 61, 22, 13, 14, 23, 9, 7, 8, 1, 0 };
	double list2[4] = { 9.9, 12.5, 84.5, 56.6 };
	int int_max = maxn(list1, 10);
	double double_max = maxn(list2, 4);

	const char* str_ptr[5] = {"apple", "banana", "melon", "Train", "macbookpro"};
	const char* long_str = maxn(str_ptr, 5);

	std::cout << int_max << std::endl;
	std::cout << double_max << std::endl;
	std::cout << &long_str << std::endl;
	std::cout << *&long_str << std::endl;
}

template<typename T>
T maxn(T list[], int list_size)
{
	T max;
	max = list[0];
	for (int i = 1; i < list_size; i++)
	{
		if (max < list[i])
		{
			max = list[i];
		}
	}
	return max;
}

template<> const char* maxn(const char* str[], int n)
{
	char* max = const_cast<char*>(str[0]);
	for (int i = 0; i < n-1; i++)
	{
		if (strlen(str[i]) < strlen(str[i+1]))
		{
			max = const_cast<char*>(str[i+1]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (max == str[i])
		{
			return str[i];
		}
	}
}

void pb7(void)
{
	int things[6] = { 13,31,103,301,310,130 };
	struct debts mr_E[3] =
	{
		{"PARK", 2400.0},
		{"LEE", 1300.0},
		{"KIM", 1800.0}
	};
	double* pd[3];

	for (int i = 0; i < 3; i++)
	{
		pd[i] = &mr_E[i].amount;
	}

	std::cout << "Mr. E의 재산 목록: \n";
	std::cout << showArray(things, 6) << std::endl;
	std::cout << "Mr. E의 채무 목록: \n";
	std::cout << showArray(pd, 3) << std::endl;
}

template <typename T>
T showArray(T arr[], int n)
{
	T sum = 0;

	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return sum;
}

template <typename T>
T showArray(T* arr[], int n)
{
	T sum = 0;

	for (int i = 0; i < n; i++)
	{
		sum += *arr[i];
	}
	return sum;
}