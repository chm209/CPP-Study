#include <iostream>
#include <string>
#include <array>

void ex1(void);
void ex2(void);
void fix(std::array<double, 4>* pa);
double ex2Func(int);
void ex2Func2(int x, double (*ppff)(int));

void main()
{
	// ex1();
	ex2();
	
}

void ex1(void)
{
	// �Լ�
	// C�� ����, ���ο� ����� ���� ����

	// �����Ϳ� const / ������ �ΰ����� ������.
	// 1. ��� ��ü�� �����ϴ� �����͸� �����
	// 2. ������ �ڽ��� ����� ����°�

	int age = 13;
	const int* pt1 = &age;
	// pt1���δ� ���� ������ �� ������ age�� ����� �ƴ϶� ���� ������ �� �ִ�.

	const int num1 = 10;
	const int* pt2 = &num1; // ��밡��
	// int* pt3 = &num1; ���Ұ�, num1�� ����ε� pt3�� ����� �ƴ϶� �ǹ̰� ��� ����
	// ���� ���� ������ const_cast�� const�� ����ȭ�ϰ� �����
	int* pt3 = const_cast<int*>(&num1);
	*pt3 = 20;
	std::cout << *pt3;

	// C ��Ÿ�� ���ڿ��� �Ϲ� �迭�� �߿��� ������ �ϳ��� ���ڿ����� NULL ���� ���ڰ� ��� �ִٴ°�.
	// ���ӵ� ���ڸ� ������ ������ �� ���ڸ� ������ ���� �ʴ� char �迭�� ���ڿ��� �ƴ϶� �׳� �迭�̴�.
	// ���� ���ڿ��� ũ��� �Ű������� ������ �ʿ䰡 ����.

	const char* test = "qwerty";

	while (*test) // *test�� \0�̸� ������ Ż���Ѵ�.
	{
		if (*test == 'y')
		{
			std::cout << "ã��";
		}
		test++;
	} 
}

void ex2(void)
{
	// �Լ��� array ��ü, vector�� ���� ����
	std::array<double, 4> pa;
	fix(&pa);

	// �Լ� �������� ����
	// �Լ��� �ּҵ� ���� ����
	// exfunc(blink) �� blink()�� �ּҸ� ����
	// exfunc(blink()) �� blink() �� ���ϰ��� ����

	// �Լ��� �����ϴ� ������ / �Լ� ������
	// �Լ� �����ʹ� �ַ� �Լ��� �ٸ� �Լ��� ������ �� �����ϴ�. �Լ� �����͸� �����ϴ� �������� ����� ���� ���ڰ� ������ �߻���Ű�� ����Ƿ� typedef, using �Ǵ� std::function�� ����ϴ� �� ����.
	double (*pf)(int); // �Լ� ������
	typedef double (*pf)(int x); // typedef�� �ܼ�ȭ ����
	using pointFunc = double(*)(int); // C++11 ���ʹ� �̷��� ���� ����
	// �����͸� ����Ͽ� �Լ� �ҷ�����
	pf = ex2Func; // pf�� ex2Func�� ����
	double x = ex2Func(4); // �Լ� �̸��� ����� ȣ��
	double y = (*pf)(5); // ������ pf�� ����� ȣ��
	double t = pf(5); // c++�� pf�� �Լ� �̸�ó�� ����ϴ� ���� ����Ѵ�.

	ex2Func2(4, ex2Func);
	/* ��� ���� ǥ��
	* const double* fi(const double ar[], int n);
	* const double* fi(const double [], int n);
	* const double* fi(const double*, int n);
	*/
}

void fix(std::array<double, 4> *pa)
{
	for (int i = 0; i < 4; i++)
	{
		std::cin >> (*pa)[i];
	}
}

void ex2Func2(int x, double (*ppff)(int))
{
	double x = (*ppff)(x);
}