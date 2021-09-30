#include <iostream>

class StringBad
{
private:
	char* str; // ���ڿ��� �����ϴ� ������
	int len; // ���ڿ��� ����
	static int num_strings; // ��ü�� ��
	// static ��������� ����� Ŭ���� ��ü�� ��� ��������� num_strings�� �ϳ��� ���������. �� �ϳ��� ��ü���� ���� �����Ѵ�.
public:
	StringBad(const char* s);
	StringBad();
	~StringBad();
	friend std::ostream& operator<<(std::ostream& os, const StringBad& st);
};

class String
{
private:
	char* str;
	int len;
	static int num_strings;
	static const int CINLIM = 80;
public:
	String(const char* s);
	String();
	String(const String& st);
	~String();
	int length() const { return len; }
	String& operator=(const String& st);
	String& operator=(const char* s);
	char & operator[] (int i);
	const char& operator[] (int i) const;
	friend bool operator<(const String& st1, const String& st2);
	friend bool operator>(const String& st1, const String& st2);
	friend bool operator==(const String& st1, const String& st2);
	friend std::ostream & operator<<(std::ostream & os, const String & st);
	friend std::istream& operator>>(std::istream& is, String& st);
	static int HomMany();
};

int StringBad::num_strings = 0;
// static ��� ������ Ŭ���� ���� �ȿ��� �ʱ�ȭ�� �� ����.
// static ��� ������ class �ۿ��� ���������� �ʱ�ȭ�Ѵ�.
// static Ŭ���� ����� ��ü�� �Ϻκ����� ����Ǵ� ���� �ƴ϶� ������ ����Ǳ� ����

StringBad::StringBad(const char* s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
	std::cout << num_strings << ": " << str << "\" ��ü ����\n";
}

StringBad::StringBad()
{
	len = 4;
	str = new char[4];
	std::strcpy(str, "C++");
	num_strings++;
	std::cout << num_strings << ": " << str << "\" ����Ʈ ��ü ����\n";
}

StringBad::~StringBad()
{
	std::cout << "\"" << str << "\" ��ü �ı�, ";
	--num_strings;
	std::cout << "���� ��ü ��: " << num_strings << "\n";
	delete[] str;
}
// delete[] str;�� �ִ� ������ �ı��ڸ� ȣ���ص� ��ü�� ����� �����Ͱ� �����ϴ� �޸𸮴� �ڵ����� �������� �ʱ� ������ ȣ���Ѵ�.

std::ostream& operator<<(std::ostream& os, const StringBad& st)
{
	os << st.str;
	return os;
}

int String::num_strings = 0;

int String::HomMany()
{
	return num_strings;
}

String::String(const char* s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
}

String::String()
{
	len = 4;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
}

String::String(const String& st)
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
}

String::~String()
{
	--num_strings;
	delete[] str;
}

String& String::operator=(const String& st)
{
	if (this == &st)
		return *this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}

String& String::operator=(const char* s)
{
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}

char& String::operator[](int i)
{
	return str[i];
}

const char& String::operator[](int i) const
{
	return str[i];
}

bool operator<(const String& st1, const String& st2)
{
	return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator > (const String& st1, const String st2)
{
	return st2 < st1;
}

bool operator==(const String& st1, const String& st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}

std::ostream& operator<<(std::ostream& os, const String& st)
{
	os << st.str;
	return os;
}

std::istream& operator>>(std::istream& is, String& st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
	{
		st = temp;
	}
	while (is && is.get() != '\n')
	{
		continue;
	}
	return is;
}

int main(void)
{
	// �� Ŭ������ ���� �޸� ����
	// �� new�� delete�� Ŭ������ �Բ� ����ϴ� ���, ���� �޸𸮸� ����� �� �Ͼ �� �ִ� ��� �̹��� �������� ó���ϴ� ����� �˾ƺ���.
	// �� ������ �������� ������ ����, �ı��� ����, ������ �����ε��� ������ ��ģ��.

	// ���� �޸𸮿� Ŭ����
	// �� C++�� �޸� ���� ������ ����� �޸��� ũ�⸦ �������� �� �������� �ʰ� ���α׷��� ������ �� ��Ȳ�� ���� ���뼺 �ְ� �����ϴ� ���̴�.
	
	/* ������ static Ŭ���� ���
	* 1. ª�� �ڵ带 ���� new�� delete�� ����
	* 2. static Ŭ���� ������ ���ο� ��� ����
	* �� ������ ���) StringBad�� String Ŭ���� ��ü���� ���ڿ��� �����ϴ� �ϳ��� �����Ϳ� �� ���ڿ��� ���̸� ��Ÿ���� �ϳ��� ���� ���� ���̴�.
	* 
	* �� Ư�� ��� �Լ�
	* �� StringBad Ŭ������ ����Ű�� ���������� �ڵ����� ���ǵ� Ư�� ��� �Լ� ������ �Ͼ�� ���̴�.
	* �� ��, Ư�� ��� �Լ��� �ൿ�� StringBad Ŭ���� ���迡 ��︮�� �ʱ� ������ �׷��� ������ �߻��ϴ� ���̴�.
	* �� C++�� �Ʒ��� ���� ��� �Լ��� �ڵ����� �����Ѵ�.
	* 1. �����ڸ� ���� �������� �ʾ��� ��� ����Ʈ ������
	* 2. ����Ʈ �ı��ڸ� �������� �ʾ��� ��� ����Ʈ �ı���
	* 3. ���� �����ڸ� �������� �ʾ��� ��� ���� ������
	* 4. ���� �����ڸ� �������� �ʾ��� ��� ���� ������
	* 5. �ּ� �����ڸ� �������� �ʾ��� ��� �ּ� ������
	* 
	* C++11�� �����ϴ� �߰����� ��� �Լ� (���� C++ ǥ�� ���ο��� ����)
	* 1. move ������
	* 2. move ���� ������
	* 
	* �� ����Ʈ ������
	* 1. ����ڰ� ��� �����ڵ� �������� ������, C++�� ����Ʈ �����ڸ� �����Ѵ�.
	* 2. �Ű������� ������� �ʰ� �ƹ� �ϵ� ���� �ʴ� �����ڸ� �����Ѵ�.
	* 3. ����Ʈ �����ڴ� ��ü�� ������ �ڵ� ����ó�� �����.
	* 4. ��������� �ʱ�ȭ���� �ʴ� ��ü�� ����� �Ͱų�, ��ü���� �迭�� ����� �ʹٸ�, ����Ʈ �����ڸ� ��������� �����ؾ� �Ѵ�.
	* 5. ����Ʈ �����ڴ� �Ű������� ������� �ʴ� �������̴�.
	* 6. �Ű������� ����ϴ� �����ڵ鵵, ��� �Ű������鿡 ����Ʈ ���� �����Ѵٸ�, ����Ʈ �����ڰ� �� �� �ִ�.
	*	�׷��� ex2, ex3���� ���ÿ� ����� �� ����. ex3�� ��ȣ�� �����ڷ� ��������� �����̴�.
	* 
	* ex)
	* 1. Test::Test() {} // �Ͻ��� ����Ʈ ������
	* 2. Test::Test() { ������ } // ����� ����Ʈ ������
	* 3. Test::Test(int n = 0) { test_var = n; } // 6�� ����
	* 
	* 6���� ����
	* {
	*		Test t1(10); // Test::Test(int n = 0)�� ��Ȯ�ϰ� ����
	*		Test t2; // �� �����ڿ� ��� ���յ� �� �ִ�.
	* }
	* 
	* �� ���� ������
	* 1. � ��ü�� ���� �����Ǵ� ��ü�� �����ϴ� �� ���ȴ�.
	* 2. ���� �����ڴ� �Ϲ����� ���Կ� ���Ǵ� ���� �ƴ϶� �� ���޿� ���� �Լ� �Ű����� ������ ������ �ʱ�ȭ �۾��� ���ȴ�.
	* 3. Ŭ������ ���� �����ڴ� �Ϲ������� ex1�� ���� ������ ������.
	* 4. ���ο� ��ü�� �����Ǿ� ���� ������ ������ ��ü�� �ʱ�ȭ�� �� ���� ȣ��ȴ�.
	* 4-1. ���� ����� ��Ȳ�� ���ο� ��ü�� ������ ��ü�� ��������� �ʱ�ȭ�� ���̴�. (ex3 ~ ex6 Ȯ��)
	* 4-2. �� ���������, ���α׷��� ��ü�� ���纻�� ������ ������ �����Ϸ��� ���� �����ڸ� ����Ѵ�.
	*	Ư��, �Լ��� ��ü�� ������ �����ϰų�, �Լ��� ��ü�� ������ �� ���� �����ڰ� ���ȴ�.
	* 5. ��ü�� ������ �����ϸ� ���� �����ڰ� ȣ��Ǳ� ������ ������ �����ϴ°��� �� ����.
	* 6. ������ �����ϸ� �����ڸ� ȣ���ϴ� �ð���, ���ο� ��ü�� �����ϴ� �޸� ������ ����ȴ�.
	* 7. ����Ʈ ���� �����ڴ� static ����� ������ ������� ������� �����Ѵ�. ( ����� ���� �Ǵ� ���� ������ �θ���)
	* 
	* ex)
	* 1. Class_name (const Class_name &);
	* 2. StringBad(const StringBad &);
	* 3. StringBad ditto(motto); // StringBad(const StringBad &)�� ȣ���Ѵ�.
	* 4. StringBad metoo = motto; // StringBad(const StringBad &)�� ȣ���Ѵ�.
	* 5. StringBad also = StringBad(motto); // StringBad(const StringBad &)�� ȣ���Ѵ�.
	* 6. StringBad* pStringBad = new StringBad(motto); // StringBad(const StringBad &)�� ȣ���Ѵ�.
	* 
	* �� ��Ÿ StringBad�� ������: ���� ������
	* 1. C++�� Ŭ���� ��ü ������ ����Ѵ�.
	* 2. � Ŭ������ ���� ���� �����ڸ� �ڵ����� �����ε������ν� �װ��� ����Ѵ�.
	* 
	* ex)
	* 1. Class_name & Class_name::operator=(const Class_name &);
	* 2. StringBad & StringBad::operator=(const StringBad &);
	*/

	// ���Ӱ� ������ string Ŭ����
	// �� StringBad Ŭ������ �����Ͽ� String Ŭ������ �����. 
	// �� ���� �����ڿ� ���� �����ڸ� Ŭ������ �߰��Ͽ�, Ŭ���� ��ü���� ����ϴ� �޸𸮸� �ٸ��� �����ϵ��� ��ġ�Ѵ�.
	// �� Ŭ������ ��� ����� �߰��Ѵ�.

	/*
	* static Ŭ���� ��� �Լ�
	* 1. static ��� �Լ��� ��ü�� ���� ȣ��� �ʿ䰡 ����.
	* 2. static ��� �Լ��� this �����͵� ���� �ʴ´�.
	* 3. static ��� �Լ��� public �κп� ����Ǹ�, �� �Լ��� Ŭ���� �̸��� ��� ���� ���� �����ڸ� ����Ͽ� ȣ��ȴ�.
	* 4. static ��� �Լ��� � Ư�� ��ü�͵� �������� �ʱ� ������, ����� �� �ִ� ������ ����� static ������ ����ۿ� ����.
	*/

	// �����ڿ� new�� ����� �� ������ ����
	// 1. �����ڿ��� new�� ����Ͽ� ������ ����� �ʱ�ȭ�Ѵٸ�, �Ҹ��ڿ� �ݵ�� delete�� ����ؾ� �Ѵ�.
	// 2. new�� delete�� ����� ���� ������ �Ѵ�. new�� delete�� ¦�� �̷��, new[]�� delete[]�� ¦�� �̷��� �Ѵ�.
	// 3. �����ڰ� ���� ���� ��쿡��, ��� ���ȣ�� ����ϵ��� �ƴϸ� ��� �뱤ȣ ���� ����ϵ���, ��� �����ڰ� �� �Ҹ��ڿ� �������� �Ѵ�.
	//	 �׷��� �ϳ��� �����ڿ��� new�� ����Ͽ� �����͸� �ʱ�ȭ�ϰ�, �ٸ� �����ڿ��� �� �����ͷ� �ʱ�ȭ�ϴ� ���� ���ȴ�.
	// 4. ���� ���縦 ���� �ϳ��� ��ü�� �ٸ� ��ü�� �ʱ�ȭ�ϴ�, ���� �����ڸ� �����ؾ� �Ѵ�.
	// 5. ���� ���縦 ���� �ϳ��� ��ü�� �ٸ� ��ü�� �����ϴ�, ���� �����ڸ� �����ؾ� �Ѵ�.

	// ��ü ���Ͽ� ���� ����
	
	/*
	* �� const ��ü�� ���� ���� ����
	* 1. const ������ ����ϴ� �ֵ� ������ ȣ����, �׷��� ����� �� �ִ� ��Ȳ�� ������
	* 2. ��ü�� �����ϴ� ���� ���� �����ڸ� ȣ��������, ������ �����ϴ� ���� �׷��� �ʴ�.
	* 3. �����ϴ� ������ ȣ���ϴ� �Լ��� �������� �� �����ϴ� ��ü�� ���� �������� �Ѵ�.
	* 4. �ñ״�ó�� �ִ� ������ const��� �������� const���� �Ѵ�.
	* 
	* �� const�� �ƴ� ��ü�� ���� ���� ����
	* �� cout�� �Բ� ����ϱ� ���� ���Կ������� �����ε��� << �������� �����ε��� const�� �ƴ� ��ü�� �����ϴ� �� �Ϲ����� ���̴�.
	* �� ù ��°�� ȿ����, �� ��°�� �ʿ伺 �����̴�.
	* 
	* �� ��ü ����
	* �� ���ϵǴ� ��ü�� ��ȣ�� �Լ��� �������̶��, �Լ��� ����� �� �� �������� ��ü�� �ı��ڸ� ȣ���ϱ� ������, ������ �����ϸ� �� �ȴ�.
	* �� ȣ���ϴ� �Լ��� ��� ������ ��, �� ������ ������ �� �ִ� ��ü�� �� �̻� ���� ���� �ʴ�.
	* �� �̷��� ��쿡�� ������ �ƴ϶� ��ü�� �����ؾ� �Ѵ�.
	* 
	* �� const ��ü ����
	* �� ex2,3 �� ���� ������ �� �ۼ��ұ�? �� �����Ѱ�?
	* 1. �׷��� �ڵ� �ۼ��� ���� �մ��� ������ ����, �Ǽ��� �ۼ��������� �ִ�.
	* 2. ���ϰ��� Ÿ������ ���� ���� �����ڰ� �ӽ� ��ü�� �����ϱ� ������ �� �ڵ尡 �����ϴ�.
	* 3. �ӽ� ��ü�� ���ǰ� ���� ���ȴ�.
	* �� �̷��� ����� ������ ���� ������ �������� const ��ü�� �����Ѵ�.
	* 
	* ex)
	* 1. net = force1 + force2; // ���� �ǵ��� �����
	* 2. force1 + force2 = net // ���� ���α׷���
	* 3. cout << (force1 + force2 = net).magval() << endl; // ��ģ ���α׷���
	*/

	// ��ü�� �����ϴ� ������

	/*
	* �� new�� ���� ��ü �ʱ�ȭ
	* Class_name* pclass = new Class_name(value);
	* �� ������ Class_name(Type_name); ���� �����ڸ� ȣ���Ѵ�.
	* class_name(const Type_name &); ���� ��ȭ�� �� ���� �ִ�.
	* Class_name* ptr = new Class_name; ���� ������ �ʱ�ȭ�� ����Ʈ �����ڸ� ȣ���Ѵ�.
	* 
	* String* favorite = new String(sayings[choice];
	* ���⼭ favorite �����ʹ� new�� ���� ������ �̸� ���� ��ü�� �����ϴ� ������ ��θ� �����Ѵ�.
	* 
	* �� new�� delete ����
	* ���� é���� ������ new�� delete�� �� ���� ���ؿ��� ����Ѵ�.
	* 1. �� ��ü�� ������ ������ new�� ����Ͽ� �̸� ���ڿ��� �����ϱ� ���� �޸� ������ �����Ѵ�.
	* 2. ex1�� ���� new�� ����Ͽ� �ϳ��� ������ü�� �����Ѵ�.
	*	�̰��� ���ڿ��� �����ϱ� ���� ���� �ƴ϶� ��ü�� �����ϱ� ���� �޸� ������ �����Ѵ�.
	* 
	* ex)
	* 1. String* favorite = new String(sayings[choice]);
	* 
	* �� �Ҹ��ڴ� ������ ���� ��Ȳ���� ȣ��ȴ�.
	* 1. ��ü�� �ڵ� �����̰ų� external, static, static external, �Ǵ� �̸� ���� �ȿ� �ִ� static �����̸� �Ҹ��ڴ� ���α׷��� ����ɶ� ȣ��ȴ�.
	* 2. new�� ���� ������ ��ü���, �� ��ü�� �Ҹ��ڴ� �� ��ü�� ���� ��������� delete�� ����� �� ȣ��ȴ�.
	* 
	* �� �����Ϳ� ��ü�� ���� ��� - 846 ������ Ȯ��
	* �� ��ü�� �����ϴ� �����͸� ����� �� �� ���� ������ �˾� �ξ�� �Ѵ�.
	* 1. ��ü�� �����Ѵ� �����ʹ� �Ϲ����� ������ ǥ�� ������ ����Ͽ� �����Ѵ�. ex1
	* 2. ������ ��ü�� �����ϵ��� �����͸� �ʱ�ȭ�� �� �ִ�. ex2
	* 3. new�� ����Ͽ� �����͸� �ʱ�ȭ�� �� �ִ�. �̰��� �� ��ü�� �����Ѵ�. ex3
	* 4. new�� Ŭ������ �Բ� ����ϸ�, ���� �����Ǵ� ��ü�� �ʱ�ȭ�ϱ� ���� ������ Ŭ���� �����ڰ� ȣ��ȴ�. ex4 ~ ex6
	* 5. �����͸� ����Ͽ� Ŭ���� �޼��忡 �����Ϸ��� -> �����ڸ� ����Ѵ�. ex7
	* 6. ��ü�� ��� ���� ��ü�� �����ϴ� �����Ϳ� ���� ���� ������(*)�� �����Ѵ�. ex8
	* 
	* ex)
	* 1. String* test;
	* 2. String* first = &sayings[0];
	* 3. String* favorite = new string(sayings[choice]);
	* 4. String* gleep = new String; // ����Ʈ �����ڸ� ȣ���Ѵ�.
	* 5. String* glop = new String("la la la"); // String(const char*) �����ڸ� ȣ���Ѵ�.
	* 6. String* favorite = new String(sayings[choice]); // String(const String &) �����ڸ� ȣ���Ѵ�.
	* 7. if(sayings[i].length() < shortest->length())
	* 8. if(sayings[i] < *first) // ��ü ������ ���Ѵ�.
	*		  first = &sayings[i]; // ��ü �ּҸ� �����Ѵ�.
	*    
	* �� ��ġ ���� new �ٽ� ���캸��
	* �� 847 ������ �ڵ尡 ����
	* 1. ���� �ڵ�� ��ü���� ���� �޸𸮸� �����ϱ� ����, ��ġ ���� new�� �������� ��ġ�� �Բ� ����Ѵ�.
	* 2. ���� �ڵ��� ��ġ ���� new���� �� ���� �������� �ִ�.
	* 3. ù°, �� ��° ��ü�� ������ �� ��ġ ���� new�� ù ��° ��ü�� ���� �Ͱ� ������ ��ġ�� ���ο� ��ü�� �����.
	*	   ù ��° ��ü�� ���� �Ҹ��ڰ� ���� ȣ����� �ʾҴٴ� ���� �ǹ��Ѵ�. �� Ŭ���� ����� ���� ���� �޸� ������ ����Ѵٸ� �ſ� ū ������ �̾�����.
	* 4. ����, pc2�� pc4�� delete�� ����ϴ� ����, pc2�� pc4�� �����ϴ� �� ��ü�� ���� �Ҹ��ڸ� �ڵ����� ȣ���Ѵ�.
	*	   �׷��� buffer�� delete []�� ����ϴ� ���� ��ġ ���� new�� ���� ������ ��ü���� ���� �Ҹ��ڸ� ȣ������ �ʴ´�.
	* 5. �� ������ ���� ������� ������ ��ġ ���� new�� �����ϴ� ���ۿ��� �޸� ��ġ�� �����ϴ� ���� ����� å���̴�.
	* 6. ���� �ٸ� �� ��ġ�� ����Ϸ���, ��ġ�� �ߺ����� �ʵ��� �����ϸ鼭 �� ���� ������ ���� �ٸ� �� �ּҸ� �����ؾ� �Ѵ�.
	* pc1 = new (buffer) JustTesting;
	* pc2 = new (buffer + sizeof(JustTesting)) JustTesting("better", 6);
	* 7. ���� ���� ����ϸ� pc3�� pc1���� JustTesting ��ü�� ũ�⸸ŭ �������ִ�.
	* 8. �ι�° ������ ��ġ ���� new�� ����Ͽ� ��ü�� �����Ϸ���, �׵��� ���� �Ҹ��ڰ� ȣ��ǵ��� ��ó�� �ʿ䰡 �ִٴ� ���̴�.
	* 9. �̸� ���� �ذ���� ��ġ ���� new�� ���� �����Ǵ� ��ü���� ���� �Ҹ��ڸ� ��������� ȣ���ϴ� ���̴�.
	* pc3->~JustTesting();
	* pc1->~JustTesting();
	*/

	return 0;
}