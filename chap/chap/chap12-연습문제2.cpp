#include <iostream>
#include "cd.h"
void Bravo(const CD& disk);

void Bravo(const CD& disk)
{
	disk.Report();
}

CD::CD(const char* s1, const char* s2, int n, double x)
{
	performers = new char[strlen(s1) + 1];
	label = new char[strlen(s2) + 1];
	strcpy(performers, s1);
	strcpy(label, s2);
	selections = n;
	playtime = x;
}

void CD::Report() const
{
	std::cout << "\n연주자: " << performers
		<< "\n레이블: " << label
		<< "\n수록 곡목 수: " << selections
		<< "\n재생 시간: " << playtime << std::endl;
}

CD& CD::operator=(const CD& d)
{
	if (this == &d)
	{
		return *this;
	}
	delete[] performers;
	delete[] label;
	performers = new char[strlen(d.performers) + 1];
	label = new char[strlen(d.label) + 1];
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

CLASSIC::CLASSIC(const char* s3, const char* s1, const char* s2, int n, double x) : CD(s1, s2, n, x)
{
	topten = new char[strlen(s3) + 1];
	strcpy(topten, s3);
}

CLASSIC::CLASSIC(const CLASSIC& classic, const char* s3) : CD(classic)
{
	topten = new char[strlen(s3) + 1];
	strcpy(topten, s3);
}

void CLASSIC::Report() const
{
	std::cout << "\n대표곡: " << topten << std::endl;
	CD::Report();
}

CLASSIC& CLASSIC::operator=(const CLASSIC& d)
{
	if (this == &d)
	{
		return *this;
	}
	CD::operator=(d);
	delete[] topten;
	topten = new char[strlen(d.topten) + 1];
	strcpy(topten, d.topten);
	return *this;
}


int main(void)
{
	CD c1("Beatles", "Capitol", 14, 35.5);
	CLASSIC c2 = CLASSIC("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);
	CD* pcd = &c1;

	std::cout << "\n객체를 직접 사용한다." << std::endl;
	c1.Report(); // CD 메서드를 사용
	c2.Report(); // CLASSIC 메서드를 사용

	std::cout << "\n객체를 지시하는 CD * 포인터를 사용한다." << std::endl;
	pcd->Report(); // CD 객체에 CD 메서드를 사용
	pcd = &c2;
	pcd->Report(); // CLASSIC 객체에 CLASSIC 메서드 사용

	std::cout << "\nCD 참조 매개변수를 사용하여 함수를 호출한다." << std::endl;
	Bravo(c1);
	Bravo(c2);

	std::cout << "\n대입을 테스트 한다." << std::endl;
	CLASSIC copy;
	copy = c2;
	copy.Report();

	return 0;
}