#include <iostream>
void ex01(void);
void ex02(void);
void ex03(void);
void ex04(void);

// 함수 템플릿 원형
template <class  Any>
void ex04Template(Any& a, Any& b);

template <typename T>
void ex04swap(T &a, T &b);

template <typename T>
void ex04swap(T* a, T* b, int n);

template <typename T>
void ex04swap2(T& a, T& b);

struct  job
{
	char name[40];
	int floor;
};

// 명시적 특수화
template <> void ex04swap2<job>(job& j1, job& j2);
// 명시적 구체화
template void ex04swap2<double>(double &, double &);

int main(void)
{
	// 함수의 활용
	// C에는 없고 C++에 추가된 기능들
	// ex01();
	// ex02();
	// ex03();
	ex04();
	return 0;
}

void ex01(void)
{
	// C++ 인라인 (inline) 함수
	// 프로그램의 실행 속도를 높이기 위해 보강된 기능
	// 컴파일된 함수 코드가 프로그램의 다른 코드 안에 직접 삽입되어 있다.
	// 인라인 코드를 이용하면 함수를 그 자리에서 처리하므로 인라인 함수는 일반 함수보다 약간 빠르게 수행된다.
	// 메모리 사용 측면에서는 인라인 함수는 일반 함수보다 불리하다.
	// 인라인 함수 사용여부는 신중하게 결정해야 한다.
	// 함수 코드 자체를 수행하는 데 걸리는 시간이, 함수 호출의 과정을 처리하ㅡㄴ 데 걸리는 시간에 비해 매우 길다면 전체적으로 절약되는 시간은 거의 없다.
	// 함수 코드를 수행하는 데 걸리는 시간이 매우 짧을 경우에만 인라인 함수를 사용하는 것이 일반 함수를 사용하는 것보다 시간이 절약된다.
	// 
	// 사용방법
	// 1. 함수 선언 앞에 inline 이라는 키워드를 붙인다. 
	// 2. 함수 정의 앞에 inline 이라는 키워드를 붙인다.
	// 둘중에 하나는 해야함
	// 지금까지 C의 매크로를 사용해왔다면 inline 함수로 변환하는 것을 고려해야 한다.

	// 참조 변수
	// 주된 용도는 함수의 형식 매개변수에 사용하는 것이다.
	// 참조를 매개변수로 사용하면, 그 함수는 복사본 대신 원본 데이터를 가지고 작업한다.
	// 덩치 큰 구조체를 처리해야 하는 함수에서 포인터 대신에 참조를 사용할 수 있다.
	// 클래스를 설계할때 필수적으로 사용한다.
	// & 기호는 C,C++에서 주소를 나타내는 연산자의 기능이 있지만
	// 참조 변수를 생성하기 위해 사용하기도 한다.

	int rats;
	int& rodents = rats; // rodents를 rats의 대용 이름으로 만든다. (참조)
	int* prats = &rats; // prats는 포인터이다.
	// 여기에서 & 연산자는 주소 연산자가 아니라. 데이터형 식별자의 일부로 사용된 것이다.
	// char*가 문자를 지시하는 포인터를 의미하는 것처럼, int&는 int에 대한 참조를 의마한다.
	// 이 둘은 모두 같은 값과 같은 메모리 위치를 참조한다.
	// 포인터와 참조는 비슷하지만 차이점이 있다.
	int num;
	// int& cham; → 불가능
	// cham = num; → 불가능
	// 참조를 선언할 때 참조 변수를 함께 초기화 해야 한다.
	// 참조는 const 포인터와 상당히 비슷하다.
	int& cham = num; // → 본질적으로 같은 것임
	int* const chamcham = &num; // → 본질적으로 같은 것임
	rodents = num; //  → 참조는 도중에 변경할 수 없다.
	// 저렇게 하면 rats, rodents의 값이 num 값으로 바뀌지  rodents가 num 주소를 가리키지는 않는다.
	int ppt1 = 101;
	int* qwe1 = &ppt1;
	int& asd1 = *qwe1;
	int bbb1 = 50;
	qwe1 = &bbb1;
	// 이렇게 하면 qwe1 은 ppt1을 가리키고 asd1은 qwe1을 가리키니깐 결국 asd1도 ppt1을 가리킨다.
	// qwe1가 bbb1을 가리키도록 해도 asd1은 ppt1을 가리킨다.

	// 함수 매개변수로서의 참조
	// 기존처럼 호출할때 int t를 넘겨서 int q로 받으면 q에 t값을 복사한다는 의미인데
	// int t를 넘겨서 int& q로 받으면 q가 t를 참조해서 값과 주소 모두 t를 가리킨다.
	// 함수에 전달하는 정보를 그 함수가 변경하지 않고 사용만 하도록 하려면 상수 참조를 사용해야 한다.
	// 예를 들면 함수 원형과 함수 머리에 다음과 같이 const를 사용해야 한다.
	// ex01(const int &ra)
	// 이렇게 하면 ra를 변경하려고 시도하는 코드에서 에러가 난다.
	// 간단한 함수를 작성할 때에는, 쓸데없이 참조로 전달하지 말고 값으로 전달해야 한다.
	// 참조 매개변수는 구조체나 클래스와 같이 덩치 큰 데이터를 다룰 때에나 유익하다.

	// 임시 변수, 참조 매개변수, const
	// C++는 실제 매개변수와 참조 매개변수가 일치하지 않을 때 임시 변수를 생성할 수 있다. (매개변수가 const 참조일 경우에만 허용)
	// 임시변수가 생성되는 상황 (참조 매개변수가 const일 경우)
	// 1. 실제 매개변수가 올바른 데이터형이지만 lvaule가 아닐 때
	// 2. 실제 매개변수가 잘못된 데이터형이지만 올바른 데이터형으로 반환할 수 있을 때
	// ### lvalue란 
	// ▶ lvalue 매개변수는 참조가 가능한 데이터 객체이다.
	// ▶ 변수, 배열의 원소, 구조체의 멤버, 참조 또는 역참조 포인터는 lvalue이다.
	// ▶ 일반 상수(주소에 의해서 표시되는 인용 구문과는 별개)와 여러 개의 항으로 이루어진 표현식은 lavlue가 아니다.
	// ▶ C 에서는 대입문 왼편에 있는게 lvalue 였지만 const는 아님
	// ! 참조 형식 매개변수를 const로 선언하는 것이 좋다.
	
	// rvalue 참조
	double&& twotwo = 2.0 + 18.5;
	// double& twoone = 2.0 + 18.5; → 허용하지 않음
	// 라이브러리를 만들때 특정 기능을 더욱 효율적으로 구현할 수 있도록 돕는 가능

	// 구조체에 대한 참조
	// 구조체 매개변수를 선언할 때 참조 연산자를 앞에 붙이면 된다.
	// void test(this_is & ts)
	
	// 참조 리턴을 하는 이유
	// 일반적인 리턴을 하면 값을 임시 공간에 저장을 하고 대상에 복사를 하지만
	// 참조 리턴을 하면 직접적으로 복사를 하기 때문에 보다 효율적이다.
	// 참조 리턴을 할때는 함수가 종료될때 수명이 함께 끝나는 메모리 위치에 대한 참조를 리턴하지 않도록 조심해야 한다.
	
	// 참조를 리턴할때 const를 사용하는 이유
	//	모호한 코드는 에러를 일으킬 확률을 높이기 때문에 설계할 때 모호한 코드를 추가하지않도록 하는 것이 좋다.
	// 리턴형을 const 참조로 만드는 것은 프로그래머가 모호한 에러를 만들지 않는 좋은 방법이다.
	// 경우에 따라서는 const를 쓰지 않는 것이 옳을 때도 있다.

	// 클래스 객체와 참조
	// 일반적으로 C++는 클래스 객체를 함수에 전달할 때 참조를 사용한다.

	// 참조 매개변수는 언제 사용하는가?
	// 호출 함수에 있는 데이터 객체의 변경을 허용하기 위해서
	// 전체 데이터 객체 대신에 참조를 전달하여 프로그램의 속도를 높이기 위해서
}

void ex02(void)
{
	// 디폴드 매개변수
	// 함수 호출에서 실제 매개변수를 생략했을 경우에 실제 매개변수 대신 사용되는 값이다.
	// 디폴트 매개변수는 함수 사용에 매우 큰 융통성을 부여한다.
	// 매개변수 리스트를 사용할 때에는 디폴트 매개변수를 오른쪽에서 왼쪽의 순서로 첨가해야 한다,
	// 즉, 어떤 매개변수를 디폴트 매개변수로 만들려면, 그 매개변수 보다 오른쪽에 있는 모든 매개변수를 디폴트 매개변수로 만들어야 한다.
	/*
	EX)
	char* left(const char* str, int n = 1); // 함수 선언부 int n=1을 디폴트 매개변수로 설정
	void test(int i = 1, x = 2, y = 3);
	↓ 디폴트 매개변수를 사용안 하는 호출
	char* ps = left(sample, 4);
	test(4,5,6);
	↓ 디폴트 매개변수를 사용하는 호출
	char* ps = left(sample);
	test(4,5);
	test(4);
	↓ 잘못된 호출
	test(4, ,6); // 생략 불가
	*/
}

void ex03(void)
{
	// 함수 오버로딩
	// 서로 다른 여러 개의 함수가 하나의 이름을 공유하는 것이다.
	// 함수 시그내처 → 함수의 매개변수 리스트
	// 컴파일러가 매개변수의 개수, 데이터형을 파악한다.
	// (int t) 와 (int & t)는 구분 못함 시그내처가 같음
	// const와 const가 아닌것은 구분한다. 다만, 시그내처가 같은 경우 const가 아닌 매개변수를 사용하는 호출에만 반응한다.
	// 함수 오버로딩이 가능하게 하는 것은 함수의 데이터형이 아니라 시그내처다.
	// int test(int, double);
	// double test(int, double); → 리턴형이 달라도 둘의 시그내처는 동일하기 때문에 사용할 수 없다
	// int test(char, double); → 사용가능

	// 함수 오버로딩은 과용하면 안 된다.
	// 서로 다른 데이터형을 대상으로 하지만 기본적으로는 같은 작업을 수행하는 함수들에만 사용하는 것이 바람직하다.
	// 또한, 디폴트 매개변수를 사용하여 같은 목적을 수행할 수 있는지 확인하는 것이 좋다.
}

void ex04(void)
{
	// 함수 템플릿
	// → 함수의 일반화 서술이다.
	// → int형이나 double형과 같은 구체적인 데이터형을 포괄할 수 있는 일반형으로 함수를 정의한다.
	// → 어떤 데이터형을 템플릿에 매개변수로 전달하면, 컴파일러가 그 데이터형에 맞는 함수를 생성한다.
	// → 일반화 프로그래밍이라고 한다.
	// → 때로는 매개변수화 데이터형이라고 한다.
	// 사용이유
	// → 예를 들어 두개의 int 값을 교환하는 함수가 있는데 double 값을 바꿔야한다고 가정할때,
	// 이때까지는 기존 함수를 복사하여 double형으로 바꿔주었다. 상황이 발생할때 마다 이렇게 하면 시간도 낭비하고 실수를 할 수 있다.
	// → 함수 템플릿은 이 과정을 자동화하여 시간을 절약하고 코드의 신뢰성을 높여준다.
	// → 임의 데이터형으로 함수를 정의하는 것을 허락한다.
	// → 다양한 데이터형에 대한 동일한 알고리즘을 적용해야 하는 함수가 필요하다면, 템플릿을 사용해야 한다.

	// 템플릿의 오버로딩
	// → 모든 데이터형이 같은 알고리즘을 사용할 리가 없다.
	// 이러한 가능성을 처리하기 위해, 일반적인 오버로딩을 하듯이 템플릿 정의를 오버로딩 할 수 있다.
	// 일반적인 오버로딩과 마찬가지로, 템플릿을 오버로딩할 때에도 확실하게 구분되는 함수 시그내처를 사용해야 한다.
	int i = 10, j = 20;
	ex04swap(i, j); // 원본 템플릿에 대응
	int d1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int d2[10] = { 11,12,13,14,15,16,17,18,19,20 };
	ex04swap(d1, d2, 10); // 추가 템플릿에 대응

	// 템플릿 제한
	// → 만약 타입 T가 배열, 구조체의 형식으로 들어오게 된다면 사용자가 의도하는 바와
	// 다르거나 제대로 작동하지 않을 수 있다.
	// 예를들어 + 연산자가 구조체에는 적용되지 않더라도 구조체를 재편성 하도록 연산자를 재정의하는 것은 괜찮을 수 있다.
	// C++이 플러스 연산자를 오버로드하도록 허용하여 특별한 구조체나 클래스 형태로 사용되도록 하는 것이 그 예이다.
	// →  플러스 연산자 사용이 요구되는 템플릿은 오버로드된 프러스 연산자를 지닌 구조체를 다룰 수 있다.
	// → 특별한 형에 대하여 특화된 탬플릿 정의를 제공하는 것이다.

	// ### 명시적 특수화
	// → 특정 매개변수에 대해서는 별도처리를 하고 싶은 경우 명시적 특수화를 
	// 사용하며 오버로딩 또한 가능하다.
	// ↓ 명시적 특수화 아주 구형 버전
	// template <> void ex04swap2<job>(job&, job&); // C++ 표준이 정립되기 전 사용하던 방식

	job lee = {"lee", 4};
	job park = { "park", 4 };
	ex04swap2(i, j); // void ex04swap2(int &, int &)를 생성
	ex04swap2(lee, park); // void ex04swap2(job &, job &)를 생성

	// ### 구체화와 특수화
	// 템플릿의 구체화: 컴파일러가 특 정 데이터형에 맞는 함수 정의를 생성하기 위해 템플릿을 상요할 때, 그 결과를 템플릿의 구체화라고 한다.
	// 암시적 구체화: 특정 데이터형의 매개변수를 요구하는 함수를 사용한다는 사실을 컴파일러에게 알림으로써, 그에 맞는 함수 정의를
	// 만들 필요가 있다는 것을 컴파일러가 암시적으로 인식한다.
	// 명시적 구체화: 컴파일러가 특정 구체화를 생성하도록 사용자가 직접 지시할 수 있는것
	// 명시적 구체화를 선언하는 문법은 명시적 특수화에서 <> 뺀것과 같다.
	// 명시적 구체화를 하면 컴파일러는 이 함수를 호출하든 안 하든 구체화를 하며 구체화를 하는것이지 호출하는것은 아니다.
	// !! 하나의 프로그래밍 단위에서 동일한 데이터형에 대해 명시적 구제화와 명시적 특수화를 함께 사용하면 안 된다.
	
	// ### 컴파일러가 함수를 선택하는 과정
	// 예를들어 may('B')를 호출했다고 가정하면
	// 1. 컴파일러는 may()라는 이름의 함수, 함수 템플릿이 있는지 알아본다.
	// 2. 매개변수를 하나만 사용하여 호출할 수 있는 것들을 찾아본다.
	// 여기서 주의할것은 리턴형은 고려하지 않고 시그내처만 본다.
	// 그후 여러 후보중 살아남은 리스트중에 최선을 고른다.
	// 1. 매개변수가 정확하게 대응하는 것, 일반 함수가 템플릿보다 순위가 높다.
	// 2. 송급 변환(char와 short를 int형으로, float를 double형으로 자동으로 변환한다.)
	// 3. 표준 변환(int를 char로 long을 double로 변환한다.)
	// 4. 클래스 선언에서 정의되는 반환과 같은, 사용자 정의 변환
	// ### 부분순서화
	// 1. 오버로딩 분석 과정은 최선으로 대응하는 하나의 함수를 찾는다. 그런 것이 있으면 그 함수를 선택한다.
	// 2. 다르게 결합된 후보가 하나 이상이고, 그중 하나가 템플릿이 아닌 함수라면, 템플릿이 아닌 그 함수를 선택한다.
	// 3. 다르게 결합된 후보가 하나 이상이고, 그들 모두가 템플릿 함수이지만, 어떤 템플릿이 다른 템플릿들보다 더 특수화되어 있으면 그것을 선택한다.
	// 4. 똑같이 좋고 템플릿이 아닌 함수가 둘 이상이거나, 똑같이 좋고 특수화 수준도 같은 템플릿 함수가 둘 이상이면, 모호하기 때문에 에러가 발생한다.
	// 5. 대응하는 호출이 없을 때에도 에러가 발생한다.
	
	// ## 사용자의 선택
	// 적절한 함수 사용을 통해컴파일러에게 사용자가 원하는 것을 선택하도록 리드할 수 있다.
	// 템플릿 원형을 제거하고 템플릿 함수 정의를 파일 맨 위에 위치시키면, 일반 함수의 경우와 마찬가지로
	// 템플릿 함수 정의는 그 함수가 사용되기 전에 나타날 경우에는 자신의 원형처럼 행동한다.
	// ### 매개변수가 여러개인 함수
	// 어떤 함수가 다른 함수보다 더 좋은 선택을 얻으려면, 그 함수는 적어도 모든 매개변수가 잘 대응해야 하고, 다른 함수보다 적어도 어느 하나의
	// 매개변수가 더 잘 대응해야 한다.
	// 함수 원형과 템플릿의 모든 가능한 집합에 대해 하나의 최상의 결과를 얻을 수 있도록 규칙이 정해져 있다.
	
	// decltype 키워드 (C++11)
	int x;
	decltype(x) y; // x와 동일한 타입의 y를 만들어라
	decltype(x + y) xpy = x + y;; // xpy를 x+y와 동일한 타입으로 만들고 x+y 로 초기화
	// 한가지 이상을 선언할때
	typedef decltype(x + y) xytype;
	xytype xpy2 = x + y;
	xytype arr[10];
	xytype& rxy = arr[2];

	// 대체할 수 있는 함수구문(C++11의 Trailing Return Type)
}

/* x와 y로부터 어떠한 타입의 결과를 얻을지 사전에 알지 못한다.
* 사전에 미리 알지 못한 시점에서 이 코드에 있는 x와 y 매개체를 선언하지 못했기 때문에,
* 그 둘은 범위 내에 존재한다.
* decltype 설명자는 매개변수가 선언된 이후에 와야 하는데, 이를 위해 C++11은 함수를 선언하고 정의하는 새로운 구문을 허용한다.
template<class T1, class T2>
?type? gt (T1 x, T2 y)
{
	return x + y;
}

auto gt(T1 x, T2 y) -> double; // 원형은 이렇게 대체할 수 있다. 
auto gt(int x, float y) --> double // 정의는 이렇게 사용한다.
{ }
*/
// decltype과 함께 사용할 경우
template<class T1, class T2>
auto gt(T1 x, T2 y) -> decltype(x+y)
{
	return x + y;
}

template <class Any> // 템플릿 설정
void ex04Template(Any& a, Any& b)
{
	Any temp;
	temp = a;
	a = b;
	b = temp;
}

template <typename T> // 원본 템플릿
void ex04swap(T& a, T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <typename T> // 추가 템플릿
void ex04swap(T a[], T b[], int n)
{
	Any temp;
	for (int i = 0; i < n; i++)
	{
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}

// C++98 버전까지는 이렇게 만들었음
// 이렇게 개발한 코드가 많이 있다.
template <class AnyType>
void ex04Template2(AnyType& a, AnyType& b)
{
	Any temp;
	temp = a;
	a = b;
	b = temp;
}