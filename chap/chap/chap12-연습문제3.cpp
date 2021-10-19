#include "port.h"

// PORT 클래스

PORT::PORT(const char* br, const char* st, int b)
{
	brand = new char[strlen(br) + 1];
	strcpy(brand, br);
	strcpy(style, st);
	bottles = b;
}

PORT::PORT(const PORT& p)
{
	brand = new char[strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	strncpy(style, p.style, 19);
	style[19] = '\0';
	bottles = p.bottles;
}

PORT& PORT::operator=(const PORT& p)
{
	if (this == &p)
	{
		return *this;
	}
	delete[] brand;
	brand = new char[strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	strncpy(style, p.style, 19);
	style[19] = '\0';
	bottles = p.bottles;

	return *this;
}

PORT& PORT::operator+=(int b)
{
	bottles += b;
	return *this;
}

PORT& PORT::operator-=(int b)
{
	bottles -= b;
	return *this;
}

void PORT::Show() const
{
	std::cout << "\n브랜드: " << brand
		<< "\n스타일: " << style
		<< "\n수량: " << bottles << std::endl;
}

std::ostream& operator<<(std::ostream& os, const PORT& p)
{
	os << p.brand << ", "
		<< p.style << ", "
		<< p.bottles;
	return os;
}

// 파생 클래스
VintagePORT::VintagePORT()
{
	nickname = new char[1];
	nickname[0] = '\0';
	year = 0;
}

VintagePORT::VintagePORT(const char* br, int b, const char* nn, int y) : PORT(br, "vintage", b)
{
	nickname = new char[strlen(nn) + 1];
	strcpy(nickname, nn);
	year = y;
}

VintagePORT::VintagePORT(const VintagePORT& vp) : PORT(vp)
{
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
	year = vp.year;
}

VintagePORT& VintagePORT::operator=(const VintagePORT& vp)
{
	if (this == &vp)
	{
		return *this;
	}
	PORT::operator=(vp);
	delete[] nickname;
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
	year = vp.year;
	return *this;
}

void VintagePORT::Show() const
{
	PORT::Show();
	std::cout << "별명: " << nickname
		<< "제조일자: " << year << std::endl;
}

std::ostream& operator<<(std::ostream& os, const VintagePORT& vp)
{
	os << (const PORT&)vp << ", " << vp.nickname << ", " << vp.year << std::endl;
	return os;
}

void main()
{

}