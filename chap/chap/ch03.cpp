#include <iostream>
#include <string>
// ex02 Ȯ��
#include <cstring>
void ex01(void);
void ex02(void);
void ex03(void);
void ex04(void);
void ex05(void);
void ex06(void);
void ex07(void);

// ���� ��������
int main()
{
	std::cout << "�迭�� ���ڿ�" << std::endl;
	// ex01();
	std::cout << "string Ŭ����" << std::endl;
	ex02();
	std::cout << "����ü" << std::endl;
	ex03();
	std::cout << "����ü, ����ü" << std::endl;
	ex04();
	std::cout << "�����Ϳ� �޸� ����" << std::endl;
	ex05();
	std::cout << "������, �迭, ������ ����" << std::endl;
	ex06();
	std::cout << "�������� ����, �迭�� ���" << std::endl;
	ex07();
	return 0;
}

void ex01(void)
{
	// �߰�ȣ �������� ��� �迭�� 0���� �ʱ�ȭ �� �� �ִ�.
	int list1[4] = { };
	const int size = 5;
	// ����Ʈ �ʱ�ȭ�ÿ� ��ҹ����� �� �� �ִ�.
	char list2[4] = { 'q', '1', 2, '\n' };

	char list3[5] = { 'a','b',' ','d','e' }; // ���ڿ� �ƴ�
	// ��� ���ڿ��� ������ ���ڴ� �ݵ�� �� ���ڿ��� �Ѵ�.
	// �� ���ڴ� \0���� ���� �ƽ�Ű �ڵ�� 0�̴�.
	char list6[5] = { 'a','b','e','\0' }; // ���ڿ� ����
	char list4[11] = "Mr. cheeps"; // ���� ������ \0�� ä���ش�.
	char list5[] = "Bubbles"; // �����Ϸ��� �˾Ƽ� ó���Ѵ�.

	// ��� �̷��� ������ �� �� ����
	std::cout << "ABCDE" " FGHI" << std::endl;
	char name[size] = "C++a";
	name[3] = '\0';
	std::cout << name << std::endl;

	char name2[size];
	//getline() �Լ��� Enter Ű�� ���� ���ٷε�� ���� ���ڸ� �߷��� ������ �����Ͽ� �� �� ��ü�� �д´�.
	std::cin.getline(name2, size);

	int size = 0;
	char list[20] = {'��'};
	char list2[20] = {'��'};
	// get() �Լ��� ���� ������ �ִ�.
	// 1. getline() ó�� �����Ѵ�. �Ű������� ���� ������� �ؼ��ϸ�, ���� ������ �д´�.
	// �׷��� ���� ���ڸ� �о ������ �ʰ� �Է� ť�� �״�� ���ܵд�.

	std::cin.get(list, size);
	// std::cin.get(list, size); ���� �߻� !
	// �̷��� ���ϰ� ������ �Ʒ� ó�� �ؾ���
	std::cin.get(list, size);
	std::cin.get();
	std::cin.get(list, size);

	// 2. �� ���� Ŭ���� ��� �Լ��� �����Ͽ� ����Ѵ�.
	std::cin.get(list, size).get(); // ��� �Լ����� �����Ѵ�.
	// cin.get(list, size)�� cin ��ü�� �����Ѵ�. ���ϵ� cin ��ü�� �ڿ� ���յ� get() �Լ��� ȣ���ϴ� ��ü�� ���ȴ�.
	std::cin.getline(list, size).getline(list2, size);
	// �� ���� �Է��� �����ؼ� �о� list, list2 �迭�� ���� �����Ѵ�.

	/* C++ ������ �Ű����� ����Ʈ�� �ٸ��� �ϸ� ���� �̸��� ���� �Լ��� ���� ������ ����� �� �ִ�.
	* cin.get(list, size) �� ����ϸ�, �����Ϸ��� ���ڿ��� �о� �迭�� �����϶�� ������ �˾Ƶ��
	* cin.get() �� ����ϸ� �����Ϸ��� ���� �ϳ��� ������� ������ �˾Ƶ�´�.
	* ��ó�� �Ű����� ����Ʈ�� �ٸ��� �Ͽ� ���� �̸��� �Լ��� ������ ����� ���� �Լ��� �����ε��̶� �Ѵ�.
	*
	* getline() ��ſ� get()�� ����ϴ� ����
	* 1. ���� c++ ���� getline() �� ���� �����̴�.
	* 2. get() �� ����ڸ� �ټ� �����ϰ� ����� �����̴�.
	* gteline()�� ����ϱⰡ �� �� ���ϰ�, get()�� ���� üŷ�� �� �� ����.
	*
	* get()�� (getline()�� ����) �� ���� ������ failbit��� ���� �����ȴ�.
	* ��ӵǴ� �Է��� ���� �Է��� �����Ϸ��� cin.clear()�� ����ؾ� �Ѵ�.
	*
	* ���������� �߻��� �� �ִ� �� �ϳ��� ������ �Է� ���ڿ��� ���Ե� �������� �� �� �� �ִٴ� ���̴�.
	* �Է� ���� ������ ���� �� ���� ��� getline() �� get() �� ������ ���ڵ��� �Է� ť�� �״�� ���ܵд�.
	* getline()�� failbit�� �����ϰ� �� �̻��� �Է��� ���� �ʴ´�.
	*/

	int year;
	char name[50];
	/*
	std::cin >> year;
	std::cin.getline(name, 50); // ������ ���� ġ�鼭 \n ���๮�ڰ� ���� ��ŵ����, C���� fgets�� getchar ���� ��ŵ ���ϴ°Ŷ� �Ȱ��� fflush �Ἥ �ذ��ϵ��� �ٸ� ��� ����
	*/

	std::cin >> year;
	std::cin.get();
	// �Ǵ� cin >> year�� cin ��ü�� �����Ѵٴ� ����� �̿��Ͽ�
	// (std::cin >> year).get(); ���� �����ؼ� ���� �ִ�.
	std::cin.getline(name, 50);
}

void ex02(void)
{
	// string Ŭ����
	// ���ڿ��� �ϳ��� ������������ ��Ÿ���� �� �� �׷����� ǥ���� �����Ѵ�.
	// string ��� ������ ���Խ��Ѿ� �Ѵ�.

	std::string list_data = { "Hello, world" };
	std::string list_data2 = "Hello, mmm";
	char test[30] = {0};
	char test2[30] = { 0 };

	list_data = list_data2; // ���� ����
	std::string list_data3 = list_data + list_data2; // ���� ����
	list_data += list_data2; // �߰� ����

	// string �� C ��Ÿ�� ��
	list_data = list_data2;
	// strcpy(test, test2); �ȵ��ư�
	list_data += "������������";
	// strcat(test, " asdasdad");
	int len = list_data.size();
	int len2 = strlen(test);

	std::cin.getline(test, 30); // C ��Ÿ��
	getline(std::cin, list_data); // string ��Ÿ��

	// �ٸ� ���µ�
	wchar_t title[] = L"Chief A";
	char16_t aaaaaa[] = u"Fadssad a";
	char32_t car[] = U"Ford F150";
}

void ex03(void)
{

}

void ex04(void)
{

}

void ex05(void)
{

}

void ex06(void)
{

}

void ex07(void)
{

}