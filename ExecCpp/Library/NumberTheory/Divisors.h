#pragma once

#include <set>
#include <memory>

std::unique_ptr<std::set<unsigned long long>> makeDivisors(unsigned long long n) {
    std::set<unsigned long long> res;
    for (unsigned long long i = 1; i < sqrt(n) + 1; i++)
    {
        if (n % i == 0) {
            res.insert(i);
            if (i != n / i) {
                res.insert(n / i);
            }
        }
    }
    return std::make_unique<std::set<unsigned long long>>(res);
}

long long selectLargestDivisor(long long n) {
    for (unsigned long long i = sqrt(n) + 1; i >= 1; i--)
    {
        if (n % i == 0) {
            return i;
        }
    }
    return -1LL;
}
