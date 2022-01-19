#ifndef PERSON_HPP_
#define PERSON_HPP_
#include <iostream>
#include <string>
#include<time.h>
#include<stdlib.h>

class Person
{
private:
    std::string fname;
    std::string lname;
protected:
    virtual void Get();
    virtual void Data() const;
public:  
    Person() : fname("none"), lname("none") { }
    virtual ~Person() = 0;
    virtual void Show() const = 0;
    virtual void Set() = 0;
};

class Gunslinger : virtual public Person
{
private:
    double gun_time;
    int notch;
protected:
    virtual void Get();
    virtual void Data() const;
public:
    Gunslinger() : Person(), gun_time(0), notch(0) { }
    double Draw() const { return this->gun_time; }
    void Show() const;
    void Set();
};

class PokerPlayer : virtual public Person
{
protected:
    virtual void Data() const;
public:
    PokerPlayer() : Person() { }
    int Draw() const { return (rand() % 52) + 1; }
    void Show() const;
    void Set();
};

class BadDude : public Gunslinger, public PokerPlayer
{
protected:
    virtual void Get();
    virtual void Data() const;
public:
    BadDude() { }
    void Set();
    void Show() const;
    double Gdraw() const { return Gunslinger::Draw(); }
    int Cdraw() const { return PokerPlayer::Draw(); }
};

// Person
Person::~Person()
{
    
}

void Person::Get()
{
    std::cout << "성 입력: ";
    std::cin >> this->fname;
    std::cout << std::endl;
    std::cout << "이름 입력: ";
    std::cin >> this->lname;
    std::cout << std::endl;
}

void Person::Data() const
{
    std::cout << "이름: " << this->fname;
    std::cout << " " << this->lname << std::endl;
}

// Gunslinger
void Gunslinger::Set()
{
    std::cout << "총잡이의 이름을 입력하세요." << std::endl;
    Person::Get();
    Get();
}

void Gunslinger::Get()
{
    std::cout << "\n총을 뽑는데 걸리는 시간 입력: ";
    std::cin >> this->gun_time;
    std::cout << "\n권총에 새겨진 금의 갯수 입력: ";
    std::cin >> this->notch;
}

void Gunslinger::Show() const
{
    std::cout << "직종: 총잡이" << std::endl;
    Person::Data();
    Data();
}

void Gunslinger::Data() const
{
    std::cout << "총을 뽑는데 걸리는 시간: " << Draw() << std::endl;
    std::cout << "권총에 새겨진 금의 갯수: " << notch << std::endl;
}

// PokerPlayer
void PokerPlayer::Set()
{
    std::cout << "카드쟁이의 이름을 입력하세요." << std::endl;
    Person::Get();
}

void PokerPlayer::Show() const
{
    std::cout << "직종: 카드쟁이" << std::endl;
    Person::Data();
    Data();
}

void PokerPlayer::Data() const
{
    std::cout << "다음에 뽑을 카드: " << Draw() << std::endl;
}

// BadDude
void BadDude::Set()
{
    std::cout << "총잡이겸 카드쟁이의 이름을 입력하세요." << std::endl;
    Person::Get();
    Get();
}

void BadDude::Get()
{
    Gunslinger::Get();
}

void BadDude::Show() const
{
    std::cout << "직종: 총잡이겸 카드쟁이" << std::endl;
    Person::Data();
    Data();
}

void BadDude::Data() const
{
    Gunslinger::Data();
    PokerPlayer::Data();
}

#endif