// 以下の ifdef ブロックは、DLL からのエクスポートを容易にするマクロを作成するための
// 一般的な方法です。この DLL 内のすべてのファイルは、コマンド ラインで定義された LIBRARY_EXPORTS
// シンボルを使用してコンパイルされます。このシンボルは、この DLL を使用するプロジェクトでは定義できません。
// ソースファイルがこのファイルを含んでいる他のプロジェクトは、
// LIBRARY_API 関数を DLL からインポートされたと見なすのに対し、この DLL は、このマクロで定義された
// シンボルをエクスポートされたと見なします。
#ifdef LIBRARY_EXPORTS
#define LIBRARY_API __declspec(dllexport)
#else
#define LIBRARY_API __declspec(dllimport)
#endif

#include <vector>

namespace math {
    // このクラスは dll からエクスポートされました
    class LIBRARY_API CLibrary {
    public:
        CLibrary(void);
        // TODO: メソッドをここに追加します。
    };

    extern LIBRARY_API int nLibrary;

    LIBRARY_API int fnLibrary(void);
    LIBRARY_API unsigned long long gcd(unsigned long long a, unsigned long long b);
    LIBRARY_API unsigned long long lcm(unsigned long long a, unsigned long long b);
    LIBRARY_API unsigned long long lcm(std::vector<unsigned long long>& c);

}
