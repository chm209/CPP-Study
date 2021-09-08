#include <iostream>
#include <cmath>
// std 포함시키지 말것
// 하지 말라면 하지말것
// using namespace std;

void ex01(void);

int main()
{
	// 이렇게 하면 main 함수 안에서만 std 이름공간을 사용가능
	// using namespace std;
	std::cout << "Hello, world" << std::endl;
	ex01();

	return 0;
}

void ex01(void)
{
	double area = 0.0, side = 0.0;
	std::cout << "예제 1" << std::endl;
	std::cout << "마루 면적을 평방피트 단위로 입력: ";
	std::cin >> area;
	side = sqrt(area);
	std::cout << "사각형 마루라면 한 변이 " << side << "피트에 상당합니다." << std::endl;
} 