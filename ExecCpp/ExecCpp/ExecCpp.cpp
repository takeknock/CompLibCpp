
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <numeric>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <memory>

using namespace std;

long long MOD = 1e9 + 7;

unique_ptr<set<unsigned long long>> makeDivisors(unsigned long long n) {
    set<unsigned long long> res;
    for (unsigned long long i = 1; i < sqrt(n) + 1; i++)
    {
        if (n % i == 0) {
            res.insert(i);
            if (i != n / i) {
                res.insert(n / i);
            }
        }
    }
    return make_unique<set<unsigned long long>>(res);
}

unsigned long long gcd(unsigned long long a, unsigned long long b) {
    unsigned long long c = 1;
    while (c != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}


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
inline SieveOfEratosthenes<T>::SieveOfEratosthenes(const SieveOfEratosthenes & other)
{
}

template<typename T>
inline SieveOfEratosthenes<T>::SieveOfEratosthenes(const SieveOfEratosthenes && rhs)
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


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    unsigned long long a, b;
    cin >> a >> b;

    unsigned long long gcdValue = gcd(a, b);
    SieveOfEratosthenes<unsigned long long> factorizer(gcdValue);
    auto res = std::move(factorizer.decompose());

    cout << res.size() + 1 << endl;

    return 0;
}