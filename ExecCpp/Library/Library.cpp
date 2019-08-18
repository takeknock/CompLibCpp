// Library.cpp : DLL 用にエクスポートされる関数を定義します。
//

#include "pch.h"
#include "framework.h"
#include "Library.h"


namespace math {
    LIBRARY_API int nLibrary = 0;

    // これは、エクスポートされた関数の例です。
    LIBRARY_API int fnLibrary(void)
    {
        return 0;
    }

    // これは、エクスポートされたクラスのコンストラクターです。
    CLibrary::CLibrary()
    {
        return;
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

    unsigned long long lcm(unsigned long long a, unsigned long long b) {
        unsigned long long c = gcd(a, b);
        return (double)a* (double)b / (double)c;

    }

    unsigned long long lcm(std::vector<unsigned long long>& c) {
        unsigned long long t = 1;
        for (auto e : c) {
            t = lcm(t, e);
        }
        return t;
    }
} // namespace math 
