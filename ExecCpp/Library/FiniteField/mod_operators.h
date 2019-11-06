#pragma once

#include <algorithm>
#include <map>

long long modinv(long long target, long long mod) {
    long long b = mod, u = 1LL, v = 0LL;
    // extended euclid
    while (b) {
        long long t = target / b;
        target -= t * b;
        std::swap(target, b);
        u -= t * v;
        std::swap(u, v);
    }
    u %= mod;
    // uが負数の場合、u + modが逆数
    return u < 0 ? u + mod : u;
}


long long modpow(long long radix, long long mantissa, long long mod) {
    long long res = 1LL;
    while (mantissa > 0) {
        // 一番下のbitが1の場合
        if (mantissa & 1) {
            res = res * radix % mod;
            radix = radix * radix % mod;
            // 1bit右シフト(mantissa /= 2)
            mantissa >>= 1;
        }
    }
    return res;
}

// calculate a^x = b mod mのx
long long modlog(long long a, long long b, long long m) {
    a %= m;
    b %= m;

    long long l = -1, r = m;
    while (r - l > 1) {
        long long mid = (r + l) / 2LL;
        if (mid * mid >= m) {
            r = mid;
        }
        else {
            l = mid;
        }
    }

    long long sqrtOfm = r;

    std::map<long long, long long> apow;
    long long residual = 1;
    for (long long r = 0; r < sqrtOfm; r++)
    {
        if (!apow.count(residual)) {
            apow[residual] = r;
        }
        residual = residual * a % m;
    }



    long long A = modpow(modinv(a, m), sqrtOfm, m);
    residual = b;

    for (long long q = 0; q < sqrtOfm; q++)
    {
        if (apow.count(residual)) {
            long long res = q * sqrtOfm + apow[residual];
            if (res > 0) {
                return res;
            }
        }
    }

    // no solution
    return -1;

}
