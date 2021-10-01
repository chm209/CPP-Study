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

class Customer
{
private:
	long arrive; // 고객이 큐에 도착한 시간
	int processtime; // 고객이 거래를 처리하는 시간
public:
	Customer() { arrive = processtime = 0; }
	void set(long when);
	long when() const { return arrive; }
	int ptime() const { return processtime; }
};

typedef Customer Item;

class Queue
{
private:
	struct Node { Item item; struct Node* next; };
	enum {Q_SIZE = 10};
	Node* front;
	Node* rear;
	int items;
	const int qsize;
	Queue(const Queue & q) : qsize(0) { }
	Queue& operator=(const Queue& q) { return *this; }
public:
	Queue(int qs = Q_SIZE);
	~Queue();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool enqueue(const Item& item);
	bool dequeue(Item& item);
};

Queue::Queue(int qs) : qsize(qs)
{
	front = rear = NULL;
	items = 0;
}

Queue::~Queue()
{
	Node* temp;
	while(front != NULL)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}

bool Queue::isempty() const
{
	return items == 0;
}

bool Queue::isfull() const
{
	return items == qsize;
}

int Queue::queuecount() const
{
	return items;
}

bool Queue::enqueue(const Item& item)
{
	if (isfull())
	{
		return false;
	}
	Node* add = new Node; // 노드 생성
	add->item = item;
	add->next = NULL;
	items++;
	if (front == NULL)
	{
		front = add;
	}
	else
	{
		rear->next = add;
	}
	rear = add;
	return true;
}

bool Queue::dequeue(Item& item)
{
	if (front == NULL)
	{
		return false;
	}
	item = front->item;
	items--;
	Node* temp = front;
	front = front->next;
	delete temp;
	if (items == 0)
	{
		rear = NULL;
	}
	return true;
}

void Customer::set(long when)
{
	processtime = std::rand() % 3 + 1;
	arrive = when;
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

	// 테크닉의 복습

	/*
	* ● << 연산자 오버로딩
	* ostream & operator<<(ostream & os, const c_name & obj)
	* {
	*		os << ...;
	*		return os;
	* }
	* 
	* ● 변환 함수들
	* 어떤 값을 클래스형으로 변환할때
	* c_name(type_name value);
	* 클래스형을 다른 데이터형으로 변환할때
	* operator type_name();
	* 이 함수에는 선언된 리턴형이 없지만, 원하는 데이터형의 값을 리턴해야 한다.
	* 변환 함수는 조심해서 사용해야 한다. 암시적 변환이 이루어지지 않게 하려면 생성자를 선언할 때 키워드 expicit을 사용해야 한다.
	* 
	* ● 생성자가 new를 사용하는 클래스
	* ※ 854 페이지 참고
	*/

	// 큐 시뮬레이션
	// 예제 코드를 설명해서 옮기기 힘드니 책을 봐야함
	// 855 페이지 ~
	
	/*
	* ※ 큐는 항목들을 순서대로 보관하는 추상화 데이터형(ADT)이다.
	* ※ 새로운 항목은 큐의 꼬리 부분에 추가된다.
	* ※ 항목의 삭제는 큐의 머리 부분에서만 가능하다.
	* ※ 큐는 스택과 많이 비슷하다.
	* ※ 스택이 큐와 다른 점은 추가와 삭제가 동일한 한쪽 끝에서만 이루어진다는 것이다.
	* ※ 그래서 스택은 LIFO, 큐는 FIFO 구조라고 한다.
	* 
	* ● Queue 클래스
	* 1. 큐는 항목들을 도착한 순서대로 보관한다.
	* 2. 큐는 보관할 수 있는 항목 수에 한계가 있다.
	* 3. 비어 있는 큐를 생성할 수 있어야 한다.
	* 4. 큐가 비어 있는지 검사할 수 있어야 한다.
	* 5. 큐가 가득 차 있는지 검사할 수 있어야 한다.
	* 6. 큐의 꼬리 부분에 항목을 추가할 수 있어야 한다.
	* 7. 큐의 머리 부분에서 항목을 삭제할 수 있어야 한다.
	* 8. 큐의 항목 수를 알 수 있어야 한다.
	* 9. public 인터페이스와 private 세부 구현을 개발할 필요가 있다.
	* 
	* □ 단순 링크드 리스트
	* 1. 각 노드가 그 다음 노드를 지시하는 하나의 링크(또는 포인터)만 가지고 있는 형태
	* 2. 첫 번째 노드의 주소만 알면, 그 리스트에 연결된 각 노드들이 지시하는 포인터들을 계속 추적해 갈 수 있다.
	* 3. 일반적으로 리스트의 마지막 노드에 있는 포인터는 연결된 노드가 더 이상 없다는 뜻으로 NULL로 설정된다.
	* 
	* □ 내포된 구조체와 클래스
	* ※ 구조체, 클래스, 열거체가 어떤 클래스 안에서 선언되면, 그 클래스에 내포된다고 말하며 그 선언은 그 클래스의 사용 범위를 가진다.
	* ※ 선언이 클래스의 private 부분에 있으면 선언된 그 데이터형은 그 클래스 안에서만 사용할 수 있다.
	* ※ public 부분에 있으면 선언된 그 데이터형은 사용 범위 결정 연산자를 사용하여 그 클래스 바깥에서도 사용할 수 있다.
	*   
	* □ 멤버 초기자 리스트 (member initializer list)
	* ※ const 데이터 멤버를 초기화하려면, 프로그램 제어가 생성자 몸체에 도달하기 전인, 객체가 생성될 때 초기화해야 한다.
	* ※ 멤버 초기자 리스트는 앞에 콜론이 붙어 있고, 초기자들은 콤마로 분리해 놓은 리스트이다.
	* ※ 멤버 초기자 리스트는 매개변수 리스트의 닫는 소괄호 뒤에 함수 몸체의 여는 중괄호 앞에 놓인다.
	* Queue::Queue (int qs) : qsize(qs) // qsize를 qs로 초기화한다.
	* {
	*		front = rear = NULL;
	*		items = 0;
	* }
	* ※ 이 테크닉은 상수들을 초기화시키는 것에만 제한되지 않는다. 아래처럼 작성 가능하다.
	* Queue::Queue (int qs) : qsize(qs), front(NULL), rear(NULL), items(0) {}
	* ※ 참조로 선언된 클래스 멤버들에 대해서도 이 문법을 사용해야 한다.
	* 1. 이 형식은 생성자에만 사용할 수 있다.
	* 2. C++11 이전에는 static이 아닌 const 데이터 멤버를 초기화하려면 이 형식을 사용해야 한다.
	* 3. 참조 데이터 멤버를 초기화하려면 이 형식을 사용해야 한다.
	* 
	* □ 큐의 꼬리에 추가하는 메서드
	* ※ 865 페이지 그림 보면 이해감
	* 1. 큐 객체가 가득 차 있지 않은지 판단
	* 2. 새 노드를 생성, 새로운 노드를 생성할 수 없는 경우는 나중에 배운다.
	* 3. 값을 노드에 복사하고 next 포인터를 NULL로 설정
	* 4.와 5. items 카운트를 갱신하고 노드를 큐의 꼬리에 붙이고 rear 포인터를 다시 설정
	* 
	* □ 큐의 머리에서 항목을 삭제하는 메서드
	* ※ 867 페이지 그림 보면 이해감
	* 1. 큐 객체가 비어 있지 않은지 판단.
	* 2. 머리 노드에 있는 항목을 참조 변수에 복사
	* 3.과 5. 노드를 큐의 머리에 붙이고 front 포인터를 다시 설정
	* 4. front 노드의 주소를 임시 저장
	* 6. 저장된 주소의 노드를 삭제
	* 
	* ※ 시뮬레이션 코드는 875페이지 부터 있음
	*/

	return 0;
}