#ifndef ARRAYTP_HPP_
#define ARRAYTP_HPP_
#include <iostream>
#include <cstdlib>
void twodee(void);
void tempmemb(void);
void frnd2tmp(void);

template <typename T, int n>
class ArrayTP
{
private:
    T ar[n];
public:
    ArrayTP() { }
    explicit ArrayTP(const T & v);
    virtual T & operator[](int i);
    virtual T operator[](int i) const;
};

template<typename T, int n>
ArrayTP<T,n>::ArrayTP(const T & v)
{
    for (int i = 0; i < n; i++)
    {
        ar[i] = v;
    }
}

template<typename T, int n>
T & ArrayTP<T,n>::operator[](int i)
{
    if(i < 0 || i >= n)
    {
        std::cerr << "배열의 경계를 벗어나는 에러: "
            << i << "--> 잘못된 인덱스입니다.\n";
        std::exit(EXIT_FAILURE);
    }
    return ar[i];
}

template<typename T, int n>
T ArrayTP<T, n>::operator[](int i) const
{
    if(i < 0 || i >= n)
    {
        std::cerr << "배열의 경계를 벗어나는 에러: "
            << i << "--> 잘못된 인덱스입니다.\n";
        std::exit(EXIT_FAILURE);
    }
    return ar[i];
}

#endif