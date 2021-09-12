#include <iostream>
#include <fstream>
#include <cstdlib> // exit() ����

void ex01(void);
void ex02(void);
void ex03(void);

int main()
{
	// ex01();
	// ex02();
	ex03();

	return 0;
}

void ex01(void)
{
	// �б� ������ �� ������
	// if, else, elseif ����, �� ǥ���� (!, ||, &&), ���׿�����, switch case, continue, break ���� C�� ������
	// cctype ���̺귯��
	// isalpha(char ����); �������ΰ�
	// isspace(char); ȭ��Ʈ�����̽��ΰ�
	// isdigit(char); �����ΰ�
	// ispunct(char); �������ΰ�
}

void ex02(void)
{
	// �ؽ�Ʈ ���� ��� ����
	// 1. fstream ��� ������ �����Ѵ�.
	// 2. ofstream ��ü�� ����
	// 3. ofstream ��ü�� ���Ͽ� �����Ѵ�.
	// 4. ofstream ��ü�� ���Ͽ� �����Ѵ�.
	// 5. ofstream ��ü�� cout�� ������ ������� ����Ѵ�.

	char name[20] = "LeeCM";
	int age = 23;
	double d = 123500;

	std::ofstream outFile; // ����� ���� ��ü ����
	outFile.open("test.txt"); // ��ü�� ���Ͽ� ����

	outFile << std::fixed; // �� 
	outFile.precision(2); // �Ҽ��� �ڸ��� ����
	outFile.setf(std::ios_base::showpoint); // �ε� �Ҽ��� ��¿� �Ҽ��� ������ ������ ������ Ȱ��ȭ�ϰų� ��Ȱ��ȭ�Ѵ� (noshowpoint)
	outFile << name << std::endl;
	outFile << age << std::endl;
	outFile << d << std::endl;

	outFile.close();
}

void ex03(void)
{
	char name[20];
	int age = 0;
	double d = 0;

	std::string file = "test.txt";
	std::ifstream inFile; // ���� �Է��� ���� ��ü
	inFile.open(file); // inFile�� �����Ѵ�.

	if (!inFile.is_open()) // ������ ���µ� �����ϸ�
	{
		std::cout << "������ �� ��  ����";
		exit(EXIT_FAILURE);
	}

	inFile >> name;
	if (inFile.good())
		inFile >> age;
	if (inFile.good())
		inFile >> d;
	
	if (inFile.eof())
	{
		std::cout << "���� ���� ����\n";
	}
	else if (inFile.fail())
	{
		std::cout << "������ ����ġ�� �Է��� ����Ǿ����ϴ�.";
	}
	else
	{
		std::cout << "�� �� ���� ������ �Է��� ����Ǿ����ϴ�.\n";
	}
	std::cout << name << age << d;

	inFile.close();
}