#include <iostream>
#include <climits> // ���������� �Ѱ谪�� ��Ÿ���� ���� ��ȣ ����� ����Ѵ�.

// ������ ó��

int main()
{
	// C++�� C# ó�� �ڵ� �ʱ�ȭ ��� ����
	// �ΰ� �ٸ�
	int poodle = 0;
	int Poodle;
	// �����Ϸ��� ���ҽ��� ����ϱ�� ����
	int __fire;
	// �����Ϸ��� ���ҽ��� ���� �ĺ��ڷ� ����ϱ�� ����
	int _red;
	short ss1;
	long qwerty;
	long long asd;
	// C++11�� C++98���� �迭�� ����ü�� �ʱ�ȭ�� �� ���Ǿ��� ����� ���� ���� ������ �������� ����� �� �ִ�.
	int a = { 21 };
	int b = { };
	unsigned int aaa = 0x42; // 16�� ������ ���
	int bbb = 042; // 8�� ������ ���
	char ch;
	wchar_t cjk; // �⺻ ���� ��Ʈ�� Ȯ�� ���� ��Ʈ�� ���ÿ� ����, cin, cout�� ó�� �Ұ�
	// C++11 ���� wcin, wout ����
	char16_t c16;
	char32_t c32;
	bool isready = true;
	const int aaaaa = 0;
	// C++11�� �ʱ�ȭ �ϴ� ���� ���� �������� �߷��� �� �ִ�.
	auto ccc = 100;
	auto ddd = 1.1;

	std::cout << "short = " << sizeof ss1 << std::endl;
	std::cout << "int = " << sizeof _red << std::endl;
	std::cout << "long = " << sizeof qwerty << std::endl;
	std::cout << "long long = " << sizeof asd << std::endl;
	std::cout << (long)poodle << std::endl;
	std::cout << long(poodle) << std::endl;
	std::cout << static_cast<long>(poodle) << std::endl;

	return 0;
}