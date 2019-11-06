#pragma once

#include <algorithm>

long long modinv(long long target, long long mod) {
    long long b = mod, u = 1LL, v = 0LL;
    while (b) {
        long long t = target / b;
        target -= t * b;
        std::swap(target, b);
        u -= t * v;
        std::swap(u, v);
    }
    u %= mod;

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

