#include <iostream>
void ex01(void);

namespace chm
{
	int t;
}
int t;
void main()
{
	using namespace chm;
	int t;
	std::cin >> t;
	std::cin >> ::t;
	std::cin >> chm::t;

	std::cout << t << std::endl;
	std::cout << ::t << std::endl;
	std::cout << chm::t << std::endl;
	ex01();
}

void ex01(void)
{
	// ◈ 메모리 모델과 이름 공간
	// ※ C++에서는 메모리에 데이터를 여러 가지 방법으로 저장할 수 있다.
	// ※ 데이터를 메모리에 얼마나 오래 존속시킬 것인지 (기억 존속 시간), 데이터에 대한 접근을 프로그램의 어느 부분에만 허용할 것인지 (사용 범위, 링크) 등을 사용자가 선택할 수 있다.
	// ※ new 키워드를 사용하여 메모리를 동적으로 대입할 수 있다. 그리고 위치 지정 new는 그 기술의 한 변형을 제공한다.
	// ※ C++의 이름 공간 기능은 데이터 접근을 사용자가 추가로 제어할 수 있도록 해 준다.
	// ※ 일반적으로 덩치 큰 프로그램들은 데이터를 공유하는 여러 개의 소스 코드 파일들로 구성되고, 파일을 분할해서 컴파일 할 수 있다.

	// ◈ 분할 컴파일
	// ※ C & C++은 프로그램을 구성하는 함수들을 별개의 파일에 넣는 것을 권장한다.
	// ※ 파일들을 개별적으로 분할하여 컴파일한 후에, 그것들을 하나의 최종 실행 프로그램으로 링크할 수 있다.
	// ↓ 원본 프로그램을 이와 같이 분할할 수 있다.
	// 1. 구조체 선언과, 그 구조체를 사용하는 함수들의 원형이 들어 있는 헤더파일
	// 2. 그 구조체에 관련된 함수들의 코드가 들어 있는 소스 코드 파일
	// 3. 그 구조체에 관련된 함수들을 호출하는 코드가 들어 있는 소스 코드 파일
	// ↓ 헤더 파일 규칙
	// 1. 함수 정의나 변수 선언은 절대 금물
	// 2. 함수 원형
	// 3. #define이나 const를 사용하여 정의하는 기호 상수
	// 4. 구조체 선언
	// 5. 클래스 선언
	// 6. 템플릿 선언
	// 7. 인라인 함수
	// ▶ 563페이지 헤더 파일 관리 팁 있음

	// ◈ 기억 존속 시간, 사용범위, 링크 
	// ↓ C++는 네 가지 유형으로 데이터를 저장한다. 이 네 가지 유형은 메모리에 데이터를 존속시키는 시간에서 차이가 난다.
	// 1. 자동 기억 존속 시간: 함수 매개변수를 포함하여, 함수 정의 안에 선언된 변수, 로컬 변수를 말하는듯
	// 2. 정적 기억 존속 시간: 전역 변수, static 키워드를 사용한 변수
	// 3. 쓰레드 존속 시간: 연산 작업을 thread 단위로 쪼개서 처리할 수  있다.
	// 4. 동적 기억 존속 시간: new 연산자를 사용하여 대입된 메모리, delete로 해제하거나 프로그램을 종료할때까지 존속한다.
	// ↓ 사용범위와 링크
	// ※ 사용범위는 어떤 이름이 하나의 파일 (번역 단위) 안에서 얼마나 널리 알려지는가를 나타낸다. (EX) 지역변수, 전역변수, 외부변수 )
	// ※ 링크는 서로 다른 번역 단위들이 이름을 공유하는 것을 말한다.
	// 1. 외부 링크를 가진 이름은 여러 파일들이 공유할 수 있다.
	// 2. 내부 링크를 가진 이름은 한 파일 안에 있는 함수들만 공유할 수 있다.
	// 3. 자동 변수는 공유되지 않기 때문에 자동 변수의 이름은 링크르 갖지 않는다.
	// ↓ 자동 변수
	// ※ 함수 매개변수와, 함수 안에서 선언된 변수는 기본적으로 자동 기억 존속 시간을 가진다.
	// ※ 이들은 또한 지역 사용 범위를 가지며, 링크는 없다.
	// ↓ 레지스터 변수
	// 1. 원래 C에서는 register 키워드를 제공해서 컴파일러가 CPU 레지스터를 사용해서 자동 변수를 저장할 것을 제안했다.
	// 2. 변수에 더욱 빨리 접근하는 것을 허용하기 위함이었다.
	// 3. C++11 이전에는 레지스터 키워드가 자주 사용되는 변수라는 의미, 컴파일러가 해당 변수에 특별한 조치를 취한다는 의미로 일반화하여 목적을 추구했다.
	// 4. C++11 에서는 이러한것들이 사라졌지만 레지스터 키워드를 어떤 한 변수가 자동적임을 명시하도록 남겨두었다.
	// 5. auto 키워드가 동일 기능을 지원하지만, 레지스터 키워드를 보존하는 이유는 기존의 코드가 인식이 불가능해지는 것을 방지하기 위함이다. (레거시 라고 생각하면 될듯)
	// ↓ 정적 변수
	// ※ C와 마찬가지로 C++는 세가지 유형의 링크(외부, 내부, 링크 없음)를 가지는 정적 변수를 제공한다.
	// ※ 세 가지 유형 모두 프로그램이 실행되는 전체 시간 동안 존속한다. 자동 변수보다 수명이 길다.
	// 기억 공간        | 기억 존속 시간 | 사용 범위 | 링크 | 선언 방법
	// 자동                | 자동                | 블록        | 없음 | 블록안에
	// 레지스터         | 자동                 | 블록        | 없음 | 블록안에 register 사용
	// 링크 없는 정적 | 정적                | 블록        | 없음 | 블록 안에 static 사용
	// 외부 링크 정적 | 정적                | 파일        | 외부 | 함수의 바깥에
	// 내부 링크 정적 | 정적                | 파일        | 내부 | 함수의 바깥에 static 사용
	// ↓ 정적 존속 시간, 외부 링크
	// ※ 외부 연계성을 지닌 변수는 종종 단순히 외부 변수로 부른다.
	// ※ 외부 변수는 정적 저장 기간과 파일 범위를 지닌다, 외부 변수는 외부에서 정의되기 때문에 다른 외부 함수와 연계된다.
	// ↓↓ 단일 정의 원칙
	// 1. 외부 변수가 그 변수를 사용하는 모든 각각의 파일에서 선언되어야 한다.
	// 2. C++에서는 하나의 변수에 대하여 오직 하나의 정의를 부여하는 "단일 정의 원칙"을 명시하고 있다.
	// ※ 이러한 요구 사항을 충족하기 위해 C++은 두종류의 변수 선언을 한다.
	// 1. 선언을 정의하는 것 또는 단순하게 정의로, 대입되는 변수에 대하여 저장소를 제공한다.
	// 2. 참조 선언 혹은 단순히 선언하는 것인데, 이 경우엔 기존의 변수를 의미하므로 저장소를 생성하지 않는다.
	// ※ 참조 선언은 extern이라는 키워드를 사용하고 초기화를 제공하지 않는다.
	// ※ 만약 여러 파일에서 외부 변수가 사용될 경우, 오직 한 개의 파일이 그 변수에 대한 정의를 지닐 수 있다. (유일 정의 원칙)
	// ※ 그 변수를 사용하는 다른 모든 파일들은 그 변수를 extern이라는 키워드를 사용해서 선언해 줄 필요가 있다.
	// ※ C++는 사용 범위 결정 연산자 ( :: ) 를 제공함으로써, C 보다 한 단계 더 발전하였다.
	// ↓ 정적 존속 기간, 내부 링크
	// ※ 파일 사용 범위가 있는 변수에 static 제한자를 적용하면 내부 링크르 부여하게 된다.
	// 1. File1.cpp에서 errors 변수를 외부 선언하고 File2.cpp에서 errors 변수를 선언하면 errors 변수를 2번 정의한걸로 간주해서 오류가 발생한다.
	// 2. File1.cpp에서 errors 변수를 외부 선언하고 File2.cpp에서 errors 변수를 static 선언을 했다면, 내부 변수로 식별하기 위함으로 간주해서 문제가 없다.
	// 3. C++ 표준은 내부 링크를 부여하기 위해 static 키워드를 사용하는 방법이 조만간 사라질 것임을 예고했다.
	// 4. 파일 사용 범위의 변수를 정적 변수로 만들면, 다른 파일에 들어 있는 파일 사용 범위의 변수들과 이름이 충돌하는 것을 걱정할 필요가 없다.
	// ↓ 정적 기억 존속 시간, 링크 없음
	// ※ 블록 안에서 static을 사용하면, static이 지역 변수를 정적 기억 존속 시간을 갖게 만든다.
	// ※ 이것은, 그런 변수들이 블록 안에서만 알려지지만 그 블록이 활동하지 않는 동안에도 계속 존재한다는 것을 의미한다.
	// ↓ 제한자
	// ※ 기억 공간 제한자와 cv 제한자라고 부르는 몇 가지 C++ 키워드가 기억 공간에 대해서 추가 정보를 제공한다.
	// ↓↓ 기억 공간 제한자
	// 1. auto (C++11에서는 제한자에서 빠짐)
	// 2. register
	// 3. static
	// 4. extern
	// 5. thread_local(C++11에서 추가됨) / 변수의 존속 시간이 변수를 포함하는 쓰레드의 존속 시간이다.
	// 6.mutable / 특정 구조체 (또는 클래스)가 const로 선언되어 있다 하더라도 그 구조체의 특정 멤버를 변경할 수 있음을 나타내는 데 사용할 수 있다.
	// ※ 하나의 선언에는 위 목록에 있는 제한자를 하나만 사용할 수 있다.
	// ※ thread_local만 static 또는 extern과 함께 사용할 수 있다.
	// ↓↓ CV-제한자
	// 1. const
	// 2. volatile / 프로그램 코드가 변경하지 않더라도 특정 메모리 위치에 있는 값이 변경될 수 있다는 것을 나타낸다.
	// ※ C++에서는 const 제한자가 디폴트 기억 공간을 약간 바꾼다.
	// ※ 전역 변수는 외부 링크를 갖도록 디폴트로 내정되어 있지만, const 전역 변수는 내부 링크를 갖도록 디폴트로 내정된다.
	// ※ C++는 전역 const 정의를 마치 static 제한자가 사용된 것처럼 취급한다.
	// const int fingers = 10; == static const int fingers;와 같음
	// ※ const가 외부 링크를 가진다면 extern이 필요하다.
	// extern const int fingers; // 초기화는 할 수 없다.
	// ↓ 함수와 링크
	// ※ 함수 안에서 다른 함수를 정의할 수 없다. 따라서 모든 함수는 정적 기억 존속 시간을 가진다.
	// ↓ new 연산자를 이용한 초기화
	// int *pi = new int (6); 6으로 초기화
	// double *pd = new double(99.99);
	// struct where {double x, int d;};
	// where * one = new where {2.0, 10};
	// int * ar = new int[4] {1,2,3,4}; 
	// ↓ 위치 지정 new 연산자
	// ※ new 연산자는 사용할 위치를 사용자가 지정할 수 있는 위치 지정 new라는 한 가지 변형이 있다.
	// ※ 문법은 보통의 new와 동일하다.
	// #include <new>
	// struct chaff { int d, int k };
	// char t1;
	// chaff *p1;
	// p1 = new chaff; // 구조체를 힙에 놓는다.
	// p1 = new int[20] // int 배열을 힙에 놓는다.
	// p1 = new (t1) chaff; // 구조체를 t1에 놓는다.
	// p1 = new (t1) int [20]; // int 배열을 t1에 놓는다.
	// 600 페이지 확인

	// ◈  이름 공간
	// ※ C++ 표준은 이름 사용 범위를 더 잘 제어할 수 있도록 이름 공간이라는 기능을 제공한다.
	// 1. 선언 영역: 선언을 할 수 있는 영역
	// 2. 잠재 사용 범위: 쉽게 생각하면 지역 변수는 해당 블락이 끝나는곳까지가 사용 범위
	// ↓ 새로운 이름 공간 기능
	// ※ 새로운 종류의 선언 영역을 정의함으로써 이름이 명명된 이름 공간을 만들 수 있다.
	// namespace chm209
	// {
	//		int t;
	//		double d;
	//		struct well { … }
	// }
	// 1. 이름 공간은 전역 위치에 또는 다른 이름 공간 안에도 놓일 수 있다.
	// 2. 블록 안에는 놓일 수 없다.
	// 3. 하나의 이름 공간에 선언된 이름은, (그것이 상수를 참조하지 않는다면) 기본적으로 외부 링크를 가진다.
	// 4. 어떤 하나의 이름 공간에 속한 이름은 다른 이름 공간에 속한 이름과 충돌하지 않는다.
	// ※ 이름 공간에 속해 있는 이름에 접근할 수 있는 방법
	// chm209::well mole; // well 형의 구조체를 생성한다.
	// chm209::t = 13;
	// ↓ using 선언과 using 지시자
	// ※ 이름 공간에 속해 있는 이름을 간편하게 사용할 수 있는 using 선언과 using 지시자라는 두가지 방법을 제공한다.
	// ※ using 선언은 하나의 특별한 식별자를 사용할 수 있게 만들고 using 지시자는 그 이름 공간 전체에 접근할 수 있게 만든다.
	// int main()
	// {
	//		using chm209::t; // t를 지역 이름 공간에 넣는다.
	//		double t; // 에러! 이미 지역 t가 존재한다.
	//		cin >> t; 값을 chm209::t에 저장한다.
	// }
	// ※ using 선언을 외부 위치에 놓으면, 그 이름이 전역 이름 공간에 추가된다.
	// ↓↓ using 지시자 : using namespace
	// ※ 사용 범위 결정 연산자를 사용하지 않고도 그 이름 공간에 속한 모든 이름을 사용할 수 있게 된다.
	// ※ using namespace chm209; // chm209에 속한 모든 이름을 사용할 수 있게 만든다.
	// ※ 헷갈리면 using namespace std를 생각할것
	// int t; // 전역 변수
	// int main()
	// {
	//		using namespace chm209;
	//		int t; // cjm209::t를 가린다.
	//		t
	//		::t
	//		chm::t 
	// }
	// ※ 세 가지 전부 다른 변수
	// ※ using chm209::t를 하고 int t를 선언하면 이미 chm209::t가 지역 변수로 들어왔기 때문에 에러 발생
	// ※ 위에 main쪽 보면 이해감
	// ↓ 이름 공간에 대한 보충
	// ※ 중첩 가능
	// namespace animal
	// {
	//		namespace dog
	//		{
	//			int age;
	//		}
	// }
	// ※ 참조할때는 animal::dog::age로 참조 할 수 있다.
	//	※ using namespace animal::dog / using 지시자로 내부의 이름을 사용할 수 있다.
	// ↓ 이름을 명명하지 않은 이름 공간
	// namespace
	// {
	//		int d;
	// }
	// ※ 이름을 명명하지 않은 공간에 있는 이름들은 전역 변수와 비슷하다.
	// ※ 이름 공간의 이름이 따로 정의되어 있지 않기 때문에 일회성이며, 다른 파일에서 사용할 수 없다. (이 때문에, 내부 링크를 가지는 정적 변수 대신 무명 이름 공간을 활용할 수도 있다.)
	// 
	// 이름 공간 사용 가이드라인
	// 1. 외부 전역 변수 대신, 이름 공간에 정의된 변수를 사용하라.
	// 2. 정적 전역 변수 대신, 무명 이름 공간에 정의된 변수를 사용하라.
	// 3. 개발중인 라이브러리 함수 또는 라이브러리 클래스를 하나의 이름 공간 내에 정의하라.
	// 4. using 지시자는 구버전 코드에 이름 공간을 적용하여 변환시키는 임시 수단으로써만 사용하라. (iostream.h 와 같은 구버전의 헤더 파일에는 이름 공간을 사용하지 않는다.)
	// 5. using 지시자를 헤더 파일내에 정의하지 마라. (어떤 이름을 사용하게 되는지를 알 수 없게 되며, 헤더 파일들이 포함되는 순서에 따라 수행되는 작업에 영향을 미칠 수 있게 된다.)
	// 6. using 지시자 혹은 using 선언은 모든 #include Preprocessor 지시문 뒤에 위치시켜라.
	// 7. using 지시자 대신, using 선언이나 :: 연산자를 이용하여 Conflicts 발생 확률을 줄여라.
	// 8. using 선언을 전역 범위 대신 선택적으로 지역 범위에 사용하라.
	//
}