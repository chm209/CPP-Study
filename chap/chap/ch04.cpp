#include <iostream>
#include <string>
#include <ctime>

void ex01(void);
void ex02(void);
void ex03(void);

// ������ ���� ǥ����
int main()
{
	// ex01();
	// ex02();
	ex03();

	return 0;
}

void ex01(void)
{
	// for ����
	// C���� �����ߴ� for�� ����
	// ǥ����, ����, ���� ������, ���� ������, ����ǥ���� ���� ����

	// �޸� ������
	// �ΰ��� ǥ������ �ϳ��� �ν��Ѵ�. i++, --j
	int j = 10;
	for (int i = 0; i < 10; i++, j--)
	{
		//
	}
	// �޸� �����ڴ� �켱������ ���� ����.
	// �Ʒ�ó�� �ϸ� (cats = 17), 240; �̶� 17�� ���� 240�� �ƹ��͵� ������ ����.
	int cats;
	cats = 17, 240;
	std::cout << cats << std::endl;

	// C ��Ÿ�� ���ڿ� ��
	// strcmp() ���

	// string ���ڿ� ��
	std::string str = "q?erty";

	for (char ch = 'a'; str != "qwerty"; ch++)
	{
		str[1] = ch;
	}
}

void ex02(void)
{
	// while ����
	// C�� ����

	int i = 0;
	while (i != 10)
	{
		i++;
	}

	// �ð� ����, clock �Լ� ���� �� #include <ctime> �� clock() �Լ��� clock_t ���� ���ǵǾ� �ִ�.
	clock_t  delay = 5 * CLOCKS_PER_SEC; // ���� �ð��� �ý��� ���� Ŭ�� ���� ��ȯ
	clock_t start = clock();
	while (clock() - start < delay); // �ð��� ����� ������ ���, �����ݷп� ����
	int  n = 0;

	// do while ����
	do
	{
		std::cout << "�ϴ� ������";
		n++;
	} while (n != 7); // �ѹ� �����ϰ� ���� �˻�

	// range ����� for ���� / C++ 11 ������ �߰��� ���
	// ������ for �ݺ����� �޸�, ���۰� ������ �˷����� �ʾƵ� �˾Ƽ� ó������ ������ ��ȸ�� �ϴ� �ݺ���
	// STL�̳� �迭���� �ݺ����� ���� ������ ���� ����
	// C# �� foreach�� ���� ����

	double prices[5] = { 1,2,3,4,5 };
	// c#���� foreach(int i in array) �� ������ ����
	// in ��ſ� :�� ��
	for (double x : prices)
	{
		std::cout << x << std::endl;
	}

	// EOF�� �����ϱ� ���� Ư�� ���ڸ� �Է� �޴°� �������� �ʴ´�.
	// Ctrl + z �� �ֿ�����.
	// cin�� EOF�� Ž������ �� �ΰ��� ��Ʈ(eofbit, failbit)�� 1�� �����Ѵ�.
	// eof() �Լ��� fail() �Լ��� �ִ�. ������ fail() �Լ��� �� ���� ��
	// eof�� ture���� cin.clear()�� eof �÷��׸� ����� �ٽ� �Է��� �� �ֵ��� �Ѵ�.

	while (std::cin.fail() == false) // EOF���� �˻��Ѵ�.
	{
		//
	}

	// getchar�� putchar�� ���� ������ stdio.h (�ֽ����� cstdio)�� ��� ������ ���Խ�Ű�� �ȴ�.
}

void ex03(void)
{
	// ��ø ������ 2���� �迭
	// C������ 2���� �迭�� ����

	int max[2][2] =
	{
		{1,2},
		{3,4}
	};

	std::cout << max[2][2] << std::endl;
}