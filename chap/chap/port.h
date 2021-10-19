#ifndef PORT_H_
#define PORT_H_
#include <iostream>

class PORT
{
private:
	char* brand;
	char style[20];
	int bottles;
public:
	PORT(const char* br = "none", const char* st = "none", int b = 0);
	PORT(const PORT& p);
	virtual ~PORT() { delete[] brand; };
	PORT& operator=(const PORT& p);
	PORT& operator+=(int b);
	PORT& operator-=(int b);
	int BottleCount() const { return bottles; };
	virtual void Show() const;
	friend std::ostream & operator<<(std::ostream & os, const PORT& p);
};

// 파생 클래스
class VintagePORT : public PORT
{
private:
	char* nickname;
	int year;
public:
	VintagePORT();
	VintagePORT(const char* br, int b, const char* nn, int y);
	VintagePORT(const VintagePORT& vp);
	~VintagePORT() { delete[] nickname; };
	VintagePORT& operator=(const VintagePORT& vp);
	void Show() const;
	friend std::ostream& operator<<(std::ostream& os, const VintagePORT& vp);
};

#endif // PORT_H_