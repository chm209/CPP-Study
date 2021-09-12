#include <iostream>
#include <fstream>
#include <cstdlib> // exit() 지원

void ex01(void);
void ex02(void);
void ex03(void);

int main()
{
	// ex01();
	// ex02();
	ex03();

	return 0;
}

void ex01(void)
{
	// 분기 구문과 논리 연산자
	// if, else, elseif 구문, 논리 표현식 (!, ||, &&), 삼항연산자, switch case, continue, break 전부 C와 동일함
	// cctype 라이브러리
	// isalpha(char 변수); 영문자인가
	// isspace(char); 화이트스페이스인가
	// isdigit(char); 숫자인가
	// ispunct(char); 구두점인가
}

void ex02(void)
{
	// 텍스트 파일 출력 절차
	// 1. fstream 헤더 파일을 포함한다.
	// 2. ofstream 객체를 생성
	// 3. ofstream 객체를 파일에 연결한다.
	// 4. ofstream 객체를 파일에 연결한다.
	// 5. ofstream 객체를 cout과 동일한 방식으로 사용한다.

	char name[20] = "LeeCM";
	int age = 23;
	double d = 123500;

	std::ofstream outFile; // 출력을 위한 객체 생성
	outFile.open("test.txt"); // 객체를 파일에 연결

	outFile << std::fixed; // ↓ 
	outFile.precision(2); // 소수점 자리수 고정
	outFile.setf(std::ios_base::showpoint); // 부동 소수점 출력에 소수점 문자의 무조건 포함을 활성화하거나 비활성화한다 (noshowpoint)
	outFile << name << std::endl;
	outFile << age << std::endl;
	outFile << d << std::endl;

	outFile.close();
}

void ex03(void)
{
	char name[20];
	int age = 0;
	double d = 0;

	std::string file = "test.txt";
	std::ifstream inFile; // 파일 입력을 위한 객체
	inFile.open(file); // inFile을 연결한다.

	if (!inFile.is_open()) // 파일을 여는데 실패하면
	{
		std::cout << "파일을 열 수  없음";
		exit(EXIT_FAILURE);
	}

	inFile >> name;
	if (inFile.good())
		inFile >> age;
	if (inFile.good())
		inFile >> d;
	
	if (inFile.eof())
	{
		std::cout << "파일 끝에 도달\n";
	}
	else if (inFile.fail())
	{
		std::cout << "데이터 불일치로 입력이 종료되었습니다.";
	}
	else
	{
		std::cout << "알 수 없는 이유로 입력이 종료되었습니다.\n";
	}
	std::cout << name << age << d;

	inFile.close();
}