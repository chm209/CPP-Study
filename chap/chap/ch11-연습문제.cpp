#include <iostream>
#include <String>
#include <cctype>

void pb1(void);
void pb2(void);

class Cow
{
private:
	char name[20];
	char* hobby;
	double weight;
public:
	Cow();
	Cow(const char* nm, const char* ho, double wt);
	Cow(const Cow& c);
	~Cow();
	Cow& operator=(const Cow& c);
	void showCow() const;
};

Cow::Cow()
{
	strcpy(name, "empty");
	hobby = new char[1];
	hobby[0] = '\0';
	weight = 0.0;
}

Cow::Cow(const char* nm, const char* ho, double wt)
{
	strcpy(name, nm);
	name[19] = '\0';
	hobby = new char[strlen(ho) + 1];
	strcpy(hobby, ho);
	weight = wt;
}

Cow::Cow(const Cow& c)
{
	strcpy(name, c.name);
	hobby = new char[strlen(c.hobby) + 1];
	strcpy(hobby, c.hobby);
	weight = c.weight;
}

Cow::~Cow()
{

}

Cow & Cow::operator=(const Cow& c)
{
	if (this == &c)
		return *this;
	strcpy(name, c.name);
	strcpy(hobby, c.hobby);
	weight = c.weight;
	return *this;
}

void Cow::showCow() const
{
	std::cout << "소 이름: " << this->name << std::endl
		<< "소 취미: " << this->hobby << std::endl
		<< "중량: " << this->weight << std::endl
		<< "-----------------------------------" << std::endl;
}

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
	char& operator[] (int i);
	const char& operator[] (int i) const;
	friend bool operator<(const String& st1, const String& st2);
	friend bool operator>(const String& st1, const String& st2);
	friend bool operator==(const String& st1, const String& st2);
	friend String& operator+(String& st1, String& st2);
	friend void stringlow(String& st);
	friend void stringup(String& st);
	friend std::ostream& operator<<(std::ostream& os, const String& st);
	friend std::istream& operator>>(std::istream& is, String& st);
	static int HomMany();
	void show() const;
};

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
	delete[] this->str;
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

String& operator+(String& st1, String& st2)
{
	st1.str = new char(strlen(st2.str + 1));
	char* temp = new char[strlen(st1.str) + strlen(st2.str + 1)];
	strcat(temp, st1.str);
	strcat(temp, " ");
	strcat(temp, st2.str);
	st1.str = temp;
	st1.str[strlen(st1.str) - 1] = '\0';
	return st1;
}

void stringlow(String & st)
{
	for (int i = 0; i < strlen(st.str); i++)
	{
		st.str[i] = tolower(st.str[i]);
	}
}

void stringup(String& st)
{
	for (int i = 0; i < strlen(st.str); i++)
	{
		st.str[i] = toupper(st.str[i]);
	}
}

void String::show() const
{
	std::cout << this->str << std::endl;
}

int main(void)
{
	pb1();
	pb2();
}

void pb1(void)
{
	char s[20] = "empty";
	Cow c1;
	Cow c2("park", "sleep", 15.6);
	Cow c3("lim", "run", 19.9);
	Cow c4(c3);
	Cow c5 = c2;

	c1.showCow();
	c2.showCow();
	c3.showCow();
	c4.showCow();
	c5.showCow();
}

void pb2(void)
{
	String st1("lee");
	String st2("park");

	st1 = st1 + st2;
	st1.show();
}