#pragma once

#include <vector>
#include <cmath>
#include <set>

template <typename T>
class SieveOfEratosthenes {
public:
    constexpr explicit SieveOfEratosthenes();
    constexpr explicit SieveOfEratosthenes(T targetValue);
    ~SieveOfEratosthenes();
    explicit SieveOfEratosthenes(SieveOfEratosthenes& other);
    explicit SieveOfEratosthenes(const SieveOfEratosthenes& other);
    explicit SieveOfEratosthenes(const SieveOfEratosthenes&& rhs);
    SieveOfEratosthenes& operator =(const SieveOfEratosthenes& other);
    SieveOfEratosthenes& operator =(const SieveOfEratosthenes&& rhs);
    std::vector<std::pair<T, T>> decompose();
private:
    T _v;

};

template<typename T>
inline constexpr SieveOfEratosthenes<T>::SieveOfEratosthenes()
{
}

template<typename T>
inline constexpr SieveOfEratosthenes<T>::SieveOfEratosthenes(T targetValue)
    :_v(targetValue)
{
}

template<typename T>
inline SieveOfEratosthenes<T>::~SieveOfEratosthenes()
{
}

template<typename T>
inline SieveOfEratosthenes<T>::SieveOfEratosthenes(const SieveOfEratosthenes& other)
{
}

template<typename T>
inline SieveOfEratosthenes<T>::SieveOfEratosthenes(const SieveOfEratosthenes&& rhs)
{
}


template<typename T>
inline std::vector<std::pair<T, T>> SieveOfEratosthenes<T>::decompose()
{
    std::vector<std::pair<T, T>> factorizedPrimesAndNum;
    T n = _v;
    for (T i = 2; i * i <= _v; i++)
    {
        if (n % i != 0) {
            continue;
        }
        int num = 0;
        while (n % i == 0) {
            ++num;
            n /= i;
        }
        factorizedPrimesAndNum.emplace_back(std::make_pair(i, num));
    }
    // add n (it n != 1)
    if (n != 1) {
        factorizedPrimesAndNum.emplace_back(std::make_pair(n, 1));
    }
    return factorizedPrimesAndNum;
}