#pragma once

unsigned long long gcd(unsigned long long a, unsigned long long b) {
    unsigned long long c = 1;
    while (c != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

