#pragma once

#include <vector>

using namespace std;

template<typename T>
vector<bool> sieve_of_eratosthenes(T range) {
    vector<bool> isPrime(range, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (ll i = 2; i < sqrt(range); ++i)
    {
        for (ll j = 2; i * j < range; ++j)
        {
            ll target = i * j;
            isPrime[target] = false;
        }
    }
    return std::move(isPrime);
}

template<typename T>
vector<T> get_all_primes(T range) {
    vector<bool> isPrime = sieve_of_eratosthenes(range);
    vector<T> primes;
    for (ll i = 0; i < range; ++i)
    {
        if (isPrime[i]) {
            primes.emplace_back(i);
        }
    }
    return std::move(primes);
}
