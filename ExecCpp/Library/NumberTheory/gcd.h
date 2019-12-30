#pragma once

template<typename T>
T gcd(T a, T b) {
    T c = 1;
    while (c != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

template<typename T>
T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

