#ifndef CD_H_
#define CD_H_

/*
class CD // CD 디스크	
{
private:
	char performers[50];
	char label[20];
	int selections;
	double playtime;
public:
	CD(const char* s1, const char* s2, int n, double x);
	virtual ~CD() {};
	virtual void Report() const;
	CD& operator=(const CD& d);
};

class CLASSIC : public CD
{
private:
	char topten[100];
public:
	CLASSIC(const char* s3 = "no title", const char* s1 = "no name", const char* s2 = "no label", int n = 0, double x = 0.0);
	CLASSIC(const CLASSIC& classic, const char* s3);
	~CLASSIC() {};
	virtual void Report() const;
	CLASSIC& operator=(const CLASSIC& d);
};
*/
class CD // CD 디스크	
{
private:
	char* performers;
	char* label;
	int selections;
	double playtime;
public:
	CD(const char* s1, const char* s2, int n, double x);
	virtual ~CD() { delete[] performers; delete[] label; };
	virtual void Report() const;
	CD& operator=(const CD& d);
};

class CLASSIC : public CD
{
private:
	char* topten;
public:
	CLASSIC(const char* s3 = "no title", const char* s1 = "no name", const char* s2 = "no label", int n = 0, double x = 0.0);
	CLASSIC(const CLASSIC& classic, const char* s3);
	~CLASSIC() { delete[] topten; };
	virtual void Report() const;
	CLASSIC& operator=(const CLASSIC& d);
};

#endif // CD_H_
