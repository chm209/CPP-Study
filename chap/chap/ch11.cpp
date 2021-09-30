#include <iostream>

class StringBad
{
private:
	char* str; // 문자열을 지시하는 포인터
	int len; // 문자열의 길이
	static int num_strings; // 객체의 수
	// static 멤버변수를 만들면 클래스 객체가 몇개가 만들어지든 num_strings는 하나만 만들어진다. 그 하나를 객체들이 서로 공유한다.
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
// static 멤버 변수는 클래스 선언 안에서 초기화할 수 없다.
// static 멤버 변수는 class 밖에서 독립적으로 초기화한다.
// static 클래스 멤버가 객체의 일부분으로 저장되는 것이 아니라 별도로 저장되기 때문

StringBad::StringBad(const char* s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
	std::cout << num_strings << ": " << str << "\" 객체 생성\n";
}

StringBad::StringBad()
{
	len = 4;
	str = new char[4];
	std::strcpy(str, "C++");
	num_strings++;
	std::cout << num_strings << ": " << str << "\" 디폴트 객체 생성\n";
}

StringBad::~StringBad()
{
	std::cout << "\"" << str << "\" 객체 파괴, ";
	--num_strings;
	std::cout << "남은 객체 수: " << num_strings << "\n";
	delete[] str;
}
// delete[] str;이 있는 이유는 파괴자를 호출해도 객체의 멤버인 포인터가 지시하는 메모리는 자동으로 해제하지 않기 때문에 호출한다.

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
	// ◆ 클래스와 동적 메모리 대입
	// → new와 delete를 클래스와 함께 사용하는 방법, 동적 메모리를 사용할 때 일어날 수 있는 몇가지 미묘한 문제들을 처리하는 방법을 알아본다.
	// → 간단해 보이지만 생성자 설계, 파괴자 설계, 연산자 오버로딩에 영향을 미친다.

	// 동적 메모리와 클래스
	// → C++의 메모리 대입 전략은 사용할 메모리의 크기를 컴파일할 때 결정하지 않고 프로그램을 실행할 때 상황에 따라 융통성 있게 결정하는 것이다.
	
	/* 복습과 static 클래스 멤버
	* 1. 짧은 코드를 통한 new와 delete의 복습
	* 2. static 클래스 멤버라는 새로운 기억 공간
	* § 예제로 사용) StringBad와 String 클래스 객체들은 문자열을 지시하는 하나의 포인터와 그 문자열의 길이를 나타내는 하나의 값을 가질 것이다.
	* 
	* ● 특별 멤버 함수
	* ※ StringBad 클래스가 일으키는 문제점들은 자동으로 정의된 특별 멤버 함수 때문에 일어나는 것이다.
	* ※ 즉, 특별 멤버 함수의 행동이 StringBad 클래스 설계에 어울리지 않기 때문에 그러한 문제가 발생하는 것이다.
	* ※ C++는 아래와 같은 멤버 함수를 자동으로 제공한다.
	* 1. 생성자를 전혀 정의하지 않았을 경우 디폴트 생성자
	* 2. 디폴트 파괴자를 정의하지 않았을 경우 디폴트 파괴자
	* 3. 복사 생성자를 정의하지 않았을 경우 복사 생성자
	* 4. 대입 연산자를 정의하지 않았을 경우 대입 연산자
	* 5. 주소 연산자를 정의하지 않았을 경우 주소 연산자
	* 
	* C++11이 제공하는 추가적인 멤버 함수 (추후 C++ 표준 공부에서 설명)
	* 1. move 생성자
	* 2. move 대입 연산자
	* 
	* ↓ 디폴트 생성자
	* 1. 사용자가 어떠한 생성자도 제공하지 않으면, C++가 디폴트 생성자를 제공한다.
	* 2. 매개변수도 사용하지 않고 아무 일도 하지 않는 생성자를 제공한다.
	* 3. 디폴트 생성자는 객체를 보통의 자동 변수처럼 만든다.
	* 4. 명시적으로 초기화하지 않는 객체를 만들고 싶거나, 객체들의 배열을 만들고 싶다면, 디폴트 생성자를 명시적으로 정의해야 한다.
	* 5. 디폴트 생성자는 매개변수를 사용하지 않는 생성자이다.
	* 6. 매개변수를 사용하는 생성자들도, 모든 매개변수들에 디폴트 값을 제공한다면, 디폴트 생성자가 될 수 있다.
	*	그러나 ex2, ex3번을 동시에 사용할 수 없다. ex3이 모호한 생성자로 만들어지기 때문이다.
	* 
	* ex)
	* 1. Test::Test() {} // 암시적 디폴트 생성자
	* 2. Test::Test() { ．．． } // 명시적 디폴트 생성자
	* 3. Test::Test(int n = 0) { test_var = n; } // 6번 예시
	* 
	* 6번의 이유
	* {
	*		Test t1(10); // Test::Test(int n = 0)에 명확하게 부합
	*		Test t2; // 두 생성자에 모두 부합될 수 있다.
	* }
	* 
	* ↓ 복사 생성자
	* 1. 어떤 객체를 새로 생성되는 객체에 복사하는 데 사용된다.
	* 2. 복사 생성자는 일반적인 대입에 사용되는 것이 아니라 값 전달에 의한 함수 매개변수 전달을 포함한 초기화 작업에 사용된다.
	* 3. 클래스의 복사 생성자는 일반적으로 ex1과 같은 원형을 가진다.
	* 4. 새로운 객체가 생성되어 같은 종류의 기존의 객체로 초기화될 때 마다 호출된다.
	* 4-1. 가장 명백한 상황은 새로운 객체를 기존의 객체로 명시적으로 초기화할 때이다. (ex3 ~ ex6 확인)
	* 4-2. 덜 명백하지만, 프로그램이 객체의 복사본을 생성할 때마다 컴파일러는 복사 생성자를 사용한다.
	*	특히, 함수가 객체를 값으로 전달하거나, 함수가 객체를 리턴할 때 복사 생성자가 사용된다.
	* 5. 객체를 값으로 전달하면 복사 생성자가 호출되기 때문에 참조로 전달하는것이 더 좋다.
	* 6. 참조로 전달하면 생성자를 호출하는 시간과, 새로운 객체를 저장하는 메모리 공간이 절약된다.
	* 7. 디폴트 복사 생성자는 static 멤버를 제외한 멤버들을 멤버별로 복사한다. ( 멤버별 복사 또는 얕은 복사라고 부른다)
	* 
	* ex)
	* 1. Class_name (const Class_name &);
	* 2. StringBad(const StringBad &);
	* 3. StringBad ditto(motto); // StringBad(const StringBad &)을 호출한다.
	* 4. StringBad metoo = motto; // StringBad(const StringBad &)을 호출한다.
	* 5. StringBad also = StringBad(motto); // StringBad(const StringBad &)을 호출한다.
	* 6. StringBad* pStringBad = new StringBad(motto); // StringBad(const StringBad &)을 호출한다.
	* 
	* ● 기타 StringBad의 문제점: 대입 연산자
	* 1. C++도 클래스 객체 대입을 허용한다.
	* 2. 어떤 클래스에 대해 대입 연산자를 자동으로 오버로딩함으로써 그것을 허용한다.
	* 
	* ex)
	* 1. Class_name & Class_name::operator=(const Class_name &);
	* 2. StringBad & StringBad::operator=(const StringBad &);
	*/

	// 새롭게 개선된 string 클래스
	// → StringBad 클래스를 수정하여 String 클래스를 만든다. 
	// → 복사 생성자와 대입 연산자를 클래스에 추가하여, 클래스 객체들이 사용하는 메모리를 바르게 관리하도록 조치한다.
	// → 클래스에 몇가지 기능을 추가한다.

	/*
	* static 클래스 멤버 함수
	* 1. static 멤버 함수는 객체에 의해 호출될 필요가 없다.
	* 2. static 멤버 함수는 this 포인터도 갖지 않는다.
	* 3. static 멤버 함수가 public 부분에 선언되면, 그 함수는 클래스 이름과 사용 범위 결정 연산자를 사용하여 호출된다.
	* 4. static 멤버 함수는 어떤 특정 객체와도 결합하지 않기 때문에, 사용할 수 있는 데이터 멤버는 static 데이터 멤버밖에 없다.
	*/

	// 생성자에 new를 사용할 때 주의할 사항
	// 1. 생성자에서 new를 사용하여 포인터 멤버를 초기화한다면, 소멸자에 반드시 delete를 사용해야 한다.
	// 2. new와 delete의 사용은 서로 어울려야 한다. new는 delete와 짝을 이루고, new[]는 delete[]와 짝을 이루어야 한다.
	// 3. 생성자가 여러 개일 경우에는, 모두 대괄호를 사용하든지 아니면 모두 대광호 없이 사용하든지, 모든 생성자가 그 소멸자와 어율려야 한다.
	//	 그러나 하나의 생성자에서 new를 사용하여 포인터를 초기화하고, 다른 생성자에서 널 포인터로 초기화하는 것은 허용된다.
	// 4. 깊은 복사를 통해 하나의 객체를 다른 객체로 초기화하는, 복사 생성자를 정의해야 한다.
	// 5. 깊은 복사를 통해 하나의 객체를 다른 객체에 대입하는, 대입 연산자를 정의해야 한다.

	// 객체 리턴에 대한 관찰
	
	/*
	* ● const 객체에 대한 참조 리턴
	* 1. const 참조를 사용하는 주된 이유는 호율성, 그러나 사용할 수 있는 상황은 제한적
	* 2. 객체를 리턴하는 것은 복사 생성자를 호출하지만, 참조를 리턴하는 것은 그렇지 않다.
	* 3. 리턴하는 참조는 호출하는 함수가 실행중일 때 존재하는 객체에 대한 참조여야 한다.
	* 4. 시그니처에 있는 참조가 const라면 리턴형도 const여야 한다.
	* 
	* ● const가 아닌 객체에 대한 참조 리턴
	* ※ cout과 함께 사용하기 위한 대입연산자의 오버로딩과 << 연산자의 오버로딩이 const가 아닌 객체를 리턴하는 두 일반적인 예이다.
	* ※ 첫 번째는 효율성, 두 번째는 필요성 때문이다.
	* 
	* ● 객체 리턴
	* ※ 리턴되는 객체가 피호출 함수에 지역적이라면, 함수가 종료될 때 그 지역적인 객체가 파괴자를 호출하기 때문에, 참조로 리턴하면 안 된다.
	* ※ 호출하는 함수로 제어가 복귀할 때, 그 참조가 참조할 수 있는 객체가 더 이상 남아 있지 않다.
	* ※ 이러한 경우에는 참조가 아니라 객체를 리턴해야 한다.
	* 
	* ● const 객체 리턴
	* ※ ex2,3 번 같은 구문을 왜 작성할까? 왜 가능한가?
	* 1. 그러한 코드 작성에 대한 합당한 이유는 없다, 실수로 작성했을수도 있다.
	* 2. 리턴값을 타나내기 위해 복사 생성자가 임시 객체를 생성하기 때문에 이 코드가 가능하다.
	* 3. 임시 객체는 사용되고 나서 폐기된다.
	* ※ 이러한 오용과 남용을 막고 싶으면 리턴형을 const 객체로 선언한다.
	* 
	* ex)
	* 1. net = force1 + force2; // 원래 의도한 사용방법
	* 2. force1 + force2 = net // 난독 프로그래밍
	* 3. cout << (force1 + force2 = net).magval() << endl; // 미친 프로그래밍
	*/

	// 객체를 지시하는 포인터

	/*
	* ● new에 의한 객체 초기화
	* Class_name* pclass = new Class_name(value);
	* 이 구문은 Class_name(Type_name); 같은 생성자를 호출한다.
	* class_name(const Type_name &); 같은 변화를 줄 수도 있다.
	* Class_name* ptr = new Class_name; 같은 형식의 초기화는 디폴트 생성자를 호출한다.
	* 
	* String* favorite = new String(sayings[choice];
	* 여기서 favorite 포인터는 new에 의해 생성된 이름 없는 객체에 접근하는 유일한 통로를 제공한다.
	* 
	* ● new와 delete 복습
	* 현재 챕터의 예제는 new와 delete를 두 가지 수준에서 사용한다.
	* 1. 각 객체가 생성될 때마다 new를 사용하여 이름 문자열을 저장하기 위한 메모리 공간을 대입한다.
	* 2. ex1과 같이 new를 사용하여 하나의 완전객체를 대입한다.
	*	이것은 문자열을 저장하기 위한 것이 아니라 객체를 저장하기 위한 메모리 공간을 대입한다.
	* 
	* ex)
	* 1. String* favorite = new String(sayings[choice]);
	* 
	* ↓ 소멸자는 다음과 같은 상황에서 호출된다.
	* 1. 객체가 자동 변수이거나 external, static, static external, 또는 이름 공간 안에 있는 static 변수이면 소멸자는 프로그램이 종료될때 호출된다.
	* 2. new에 의해 생성된 객체라면, 그 객체의 소멸자는 그 객체에 대해 명시적으로 delete를 사용할 때 호출된다.
	* 
	* ● 포인터와 객체에 대한 요약 - 846 페이지 확인
	* ※ 객체를 지시하는 포인터를 사용할 때 몇 가지 사항을 알아 두어야 한다.
	* 1. 객체를 지시한느 포인터는 일반적인 포인터 표기 형식을 사용하여 선언한다. ex1
	* 2. 기존의 객체를 지시하도록 포인터를 초기화할 수 있다. ex2
	* 3. new를 사용하여 포인터를 초기화할 수 있다. 이것은 새 객체를 생성한다. ex3
	* 4. new를 클래스와 함께 사용하면, 새로 생성되는 객체를 초기화하기 위해 적절한 클래스 생성자가 호출된다. ex4 ~ ex6
	* 5. 포인터를 사용하여 클래스 메서드에 접근하려면 -> 연산자를 사용한다. ex7
	* 6. 객체를 얻기 위해 객체를 지시하는 포인터에 내용 참조 연산자(*)를 적용한다. ex8
	* 
	* ex)
	* 1. String* test;
	* 2. String* first = &sayings[0];
	* 3. String* favorite = new string(sayings[choice]);
	* 4. String* gleep = new String; // 디폴트 생성자를 호출한다.
	* 5. String* glop = new String("la la la"); // String(const char*) 생성자를 호출한다.
	* 6. String* favorite = new String(sayings[choice]); // String(const String &) 생성자를 호출한다.
	* 7. if(sayings[i].length() < shortest->length())
	* 8. if(sayings[i] < *first) // 객체 값들을 비교한다.
	*		  first = &sayings[i]; // 객체 주소를 대입한다.
	*    
	* ● 위치 지정 new 다시 살펴보기
	* ※ 847 페이지 코드가 예제
	* 1. 예제 코드는 객체들을 위한 메모리를 대입하기 위해, 위치 지정 new를 정상적인 위치와 함께 사용한다.
	* 2. 예제 코드의 위치 지정 new에는 두 가지 문제점이 있다.
	* 3. 첫째, 두 번째 객체를 생성할 때 위치 지정 new는 첫 번째 객체에 사용된 것과 동일한 위치를 새로운 객체로 덮어쓴다.
	*	   첫 번째 객체를 위한 소멸자가 결코 호출되지 않았다는 것을 의미한다. 그 클래스 멤버를 위해 동적 메모리 대입을 사용한다면 매우 큰 문제로 이어진다.
	* 4. 둘재, pc2와 pc4에 delete를 사용하는 것은, pc2와 pc4가 지시하는 두 객체를 위한 소멸자를 자동으로 호출한다.
	*	   그러나 buffer에 delete []를 사용하는 것은 위치 지정 new에 의해 생성된 객체들을 위한 소멸자를 호출하지 않는다.
	* 5. 이 예제를 통해 배워야할 교훈은 위치 지정 new가 관할하는 버퍼에서 메모리 위치를 관리하는 것은 사용자 책임이다.
	* 6. 서로 다른 두 위치를 사용하려면, 위치가 중복되지 않도록 주의하면서 그 버퍼 내에서 서로 다른 두 주소를 제공해야 한다.
	* pc1 = new (buffer) JustTesting;
	* pc2 = new (buffer + sizeof(JustTesting)) JustTesting("better", 6);
	* 7. 위와 같이 사용하면 pc3는 pc1에서 JustTesting 객체의 크기만큼 떨어져있다.
	* 8. 두번째 교훈은 위치 지정 new를 사용하여 객체를 저장하려면, 그들을 위한 소멸자가 호출되도록 조처할 필요가 있다는 것이다.
	* 9. 이를 위한 해결법은 위치 지정 new에 의해 생성되는 객체들을 위한 소멸자를 명시적으로 호출하는 것이다.
	* pc3->~JustTesting();
	* pc1->~JustTesting();
	*/

	return 0;
}