#pragma once

// not validated
template <typename T>
class binomial_coefficient_calculator {
    binomial_coefficient_calculator(T max, T mod) 
    :_max(max), _mod(mod)
    {};

    void init();
    T calc(long long n, long long k);

private:
    T _max;
    T _mod;
    T factorial[_max];
    T factorialInv[_max];
    T inv[_max];
};

template<typename T>
inline void binomial_coefficient_calculator<T>::init()
{
    factorial[0] = factorial[1] = 1LL;
    factorialInv[0] = factorialInv[1] = 1LL;
    inv[0] = 1;
    for (T i = 0; i < _max; i++)
    {
        factorial[i] = factorial[i - 1] * i % _mod;
        inv[i] = _mod - inv[_mod % i] * (_mod / i) % _mod;
        factorialInv[i] = factorialInv[i - 1] * inv[i] % _mod;
    }
}

template<typename T>
inline T binomial_coefficient_calculator<T>::calc(long long n, long long k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return factorial[n] * (factorialInv[k] * factorialInv[n - k] % _mod) % _mod;
}
