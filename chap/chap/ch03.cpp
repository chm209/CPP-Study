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
	char list[20] = { '��' };
	char list2[20] = { '��' };
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
	char test[30] = { 0 };
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
	// ����ü�� ����ڰ� ������ �� �ִ� ���������̴�.
	// C++ ������ ����ü�� �Ű�����, ���ϰ����� ���� �� ������ ���� ������ (=)��
	// ����Ͽ� �� ����ü�� ��� ������ ���� ����ü�� �ش� ����� ���� ���Եȴ�.
	struct ex04struct
	{
		char name[20];
		double price;
		std::string wow[30]; // �����Ϸ����� �ٸ����� ���� �����Ϸ��� ����ü ����� string�� �����Ѵ�.
	} NOTHIS =
	{
		"Lee",
		2.1,
		"Kim"
	}; // �̷��� ����ü ����� ���ÿ� ����ü ���� �ʱ�ȭ�� �����ϳ�
	// ���ø��� ���ǿ� ����ü ������ ������ �и��� ���� ���� ���α׷��� �� �����ϱ� ���� �����.

	// C���� ����ü ������ ������ �� Ű���� struct�� �䱸�Ѵ�.
	// C++ ������ Ű���� struct�� ������ �� �ִ�.

	struct ex04struct test1; // C ��Ÿ��
	ex04struct test2; // C++ ��Ÿ��
	test2.price = 1.234;

	//	C++11�� ����ü �ʱ�ȭ
	ex04struct test3{ "LEEKIM", 12.345, "Hello" }; // C++ ������ =�� ������ �� ����
	// {}�� �������� �ϸ� ������ ������� 0���� �ʱ�ȭ �Ѵ�.
	test2 = test3; // ����

	// ���Ұ� ����ü�� �迭
	ex04struct test4[2] =
	{
		{"PARK", 3.14, "KIM"},
		{"PARK", 3.14, "KIM"}
	};

	// ����ü���� ��Ʈ �ʵ�
	// ������ ���α׷��ֿ��� �ַ� ���ȴ�.
	struct torgle_register
	{
		unsigned int SN : 4; // SN �� (4��Ʈ)
		unsigned int : 4; // ������� ����(4��Ʈ)
		bool goodIn : 1; // ��ȿ�� �Է� (1��Ʈ)
		bool goodTorgle : 1; // ��ۿ� ���� (1��Ʈ)
	};


}

void ex04(void)
{
	// ����ü�� ���� �ٸ� ���������� �� ���� �� ������ ������ �� �ִ� ������ �����̴�.
	// ����ü�� ũ��� ��� �������� Ÿ���� ���� ū ������������ �������
	// ������� 8����Ʈ¥�� ����ü�� ��������� int���� 4����Ʈ�� 8����Ʈ �ȿ� �����̾
	// int �� ���ٰ� double ������ ���� int���� ���Ұ�
	union one4all
	{
		int int_val;
		double double_val;
	};

	one4all pail;
	pail.int_val = 15; // int ���� ����
	std::cout << pail.int_val << std::endl;
	pail.double_val = 1.37; // double ���� ����, int �� �ҽ�
	std::cout << pail.double_val << std::endl;

	// ����ü
	// C++�� enum ����� const�� ����Ͽ� ��ȣ ����� ����°Ϳ� ���� �� �ٸ� ������ �����Ѵ�.
	enum spectrum { red, blue, yellow }; // ����ü
	spectrum band; // band�� spectrum���� ����

	band = red; // red�� �����ڶ� ����
	// band = 3000; 3000�� �����ڰ� �ƴ϶� �Ұ���
	// band = red + blue; �׷��������� Ʋ����.
	enum spectrum2 { red, blue = 2, yellow }; // ���� ��������� ������ �� �ִ�, �Ϻθ� �����Ҽ��� �ִ�.
	// ���ԵǴ� ������ ����.
	// red�� 0�̰� �ʱ�ȭ���� ���� �����ڵ��� �ٷ� ���� �����ں��� 1��ŭ ũ��. ����� 3
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