#include <iostream>
using std::cout;
using std::endl;

// 템플릿 원형
template <typename T> void counts();
template <typename T> void report(T &);

// 템플릿 클래스
template<typename TT>
class HasFriendT
{
private:
    TT item;
    static int ct;
public:
    HasFriendT(const TT & i) : item(i) { ct++; }
    ~HasFriendT() { ct--; }
    friend void counts<TT>();
    friend void report<>(HasFriendT<TT> &);
};

template <typename T>
int HasFriendT<T>::ct = 0;

// 템플릿 프렌드 함수들의 정의
template <typename T>
void counts()
{
    cout << "템플릿 크기: " << sizeof(HasFriendT<T>) << "; ";
    cout << "템플릿 counts(): " << HasFriendT<T>::ct << endl;
}

template<typename T>
void report(T & hf)
{
    cout << hf.item << endl;
}

void tmp2tmp(void)
{
    counts<int>();
    HasFriendT<int> hif1(10);
    HasFriendT<int> hif2(20);
    HasFriendT<double> hfdb(10.5);
    report(hif1);
    report(hif2);
    report(hfdb);
    cout << "counts<int>() 출력:\n";
    counts<int>();
    cout << "counts<double>() 출력:\n";
    counts<double>();
}