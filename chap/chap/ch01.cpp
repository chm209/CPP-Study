#include <iostream>
#include <cmath>
// std ���Խ�Ű�� ����
// ���� ����� ��������
// using namespace std;

void ex01(void);

int main()
{
	// �̷��� �ϸ� main �Լ� �ȿ����� std �̸������� ��밡��
	// using namespace std;
	std::cout << "Hello, world" << std::endl;
	ex01();

	return 0;
}

void ex01(void)
{
	double area = 0.0, side = 0.0;
	std::cout << "���� 1" << std::endl;
	std::cout << "���� ������ �����Ʈ ������ �Է�: ";
	std::cin >> area;
	side = sqrt(area);
	std::cout << "�簢�� ������ �� ���� " << side << "��Ʈ�� ����մϴ�." << std::endl;
} 