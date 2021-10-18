#include <iostream>
#include "cd.h"
void Bravo(const CD& disk);

void Bravo(const CD& disk)
{
	disk.Report();
}

CD::CD(const char* s1, const char* s2, int n, double x)
{
	strcpy(performers, s1);
	strcpy(label, s2);
	selections = n;
	playtime = x;
}

void CD::Report() const
{
	std::cout << "\n������: " << performers
		<< "\n���̺�: " << label
		<< "\n���� ��� ��: " << selections
		<< "\n��� �ð�: " << playtime << std::endl;
}

CD& CD::operator=(const CD & d)
{
	if (this == &d)
	{
		return *this;
	}
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

CLASSIC::CLASSIC(const char* s3, const char* s1, const char* s2, int n, double x) : CD(s1, s2, n, x)
{
	strcpy(topten, s3);
}

CLASSIC::CLASSIC(const CLASSIC& classic, const char* s3) : CD(classic)
{
	strcpy(topten, s3);
}

void CLASSIC::Report() const
{
	std::cout << "\n��ǥ��: " << topten << std::endl;
	CD::Report();
}

CLASSIC& CLASSIC::operator=(const CLASSIC& d)
{
	if (this == &d)
	{
		return *this;
	}
	CD::operator=(d);
	strcpy(topten, d.topten);
	return *this;
}


int main(void)
{
	CD c1("Beatles", "Capitol", 14, 35.5);
	CLASSIC c2 = CLASSIC("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);
	CD* pcd = &c1;

	std::cout << "\n��ü�� ���� ����Ѵ�." << std::endl;
	c1.Report(); // CD �޼��带 ���
	c2.Report(); // CLASSIC �޼��带 ���

	std::cout << "\n��ü�� �����ϴ� CD * �����͸� ����Ѵ�." << std::endl;
	pcd->Report(); // CD ��ü�� CD �޼��带 ���
	pcd = &c2;
	pcd->Report(); // CLASSIC ��ü�� CLASSIC �޼��� ���

	std::cout << "\nCD ���� �Ű������� ����Ͽ� �Լ��� ȣ���Ѵ�." << std::endl;
	Bravo(c1);
	Bravo(c2);

	std::cout << "\n������ �׽�Ʈ �Ѵ�." << std::endl;
	CLASSIC copy;
	copy = c2;
	copy.Report();

	return 0;
}