#include <iostream>
#include <string>
#include <cstring>

void pb1(void);
void pb2(void);
void pb3(void);

int main()
{
	// pb1();
	// pb2();
	pb3();

	return 0;
}

void pb1(void)
{
	struct student_info
	{
		std::string first_name;
		std::string last_name;
		char score;
		short age;
	} student;

	std::cout << "���� �۽�Ʈ ���� (�̸�): ";
	std::getline(std::cin, student.first_name);
	std::cout << "���� ��Ʈ ���� (��): ";
	std::getline(std::cin, student.last_name);
	std::cout << "�л��� ���ϴ� ����: ";
	std::cin >> student.score;
	std::cout << "����: ";
	std::cin >> student.age;

	std::cout << "����: " << student.last_name << ", "
		<< student.first_name << std::endl;
	std::cout << "����: " << (char)(student.score + 1) << std::endl;
	std::cout << "����: " << student.age << std::endl;
}

void pb2(void)
{
	struct student_info
	{
		char first_name[20];
		char last_name[20];
		char full_name[100];
	} student;

	std::cout << "���� �۽�Ʈ ���� (�̸�): ";
	std::cin.get(student.first_name, 20);
	std::cin.get();
	std::cout << "���� ��Ʈ ���� (��): ";
	std::cin.get(student.last_name, 20);
	
	strcpy(student.full_name, student.first_name);
	strcat(student.full_name, ", ");
	strcat(student.full_name, student.last_name);
	strcat(student.full_name, "\0");

	std::cout << "�ϳ��� ���ڿ��� �����: " << student.full_name << std::endl;
}

void pb2(void)
{
	struct animal
	{
		int age;
		int wieght;
	};

	animal cat1, cat2, cat3;
	animal* cat[3] = { &cat1, &cat2, &cat3 };

	cat[0]->age = 3;
	cat[1]->age = 2;
	cat[2]->age = 1;
	cat[0]->wieght = 10;
	cat[1]->wieght = 9;
	cat[2]->wieght = 8;

	animal* catT = new animal[3];
	catT[0].age = 3;
	catT[1].age = 2;
	catT[2].age = 1;
	catT[0].wieght = 10;
	catT[1].wieght = 9;
	catT[2].wieght = 8;

	delete[] catT;
}