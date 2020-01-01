#pragma once

#include <vector>

template<typename T>
class union_find_forest {
public:
    //typedef enable_if<is_scalar<T>, T>::type value_type;
    explicit union_find_forest(T n);
    bool merge(T a, T b);
    bool isSame(T a, T b);

private:
    void init(T n);
    T root(T x);
    std::vector<T> par;
    std::vector<T> rank;
};

template<typename T>
union_find_forest<T>::union_find_forest(T n)
    :par(std::vector<T>(n)), rank(std::vector<T>(n))
{
    init(n);
}

template<typename T>
bool union_find_forest<T>::merge(T a, T b)
{
    a = root(a);
    b = root(b);

    if (a == b)
        return false;

    if (rank[a] < rank[b])
        swap(a, b);
    par[b] = a;
    if (rank[a] == rank[b])
        rank[a]++;
    return true;
}

template<typename T>
bool union_find_forest<T>::isSame(T a, T b)
{
    return root(a) == root(b);
}

template<typename T>
void union_find_forest<T>::init(T n)
{
    for (T i = 0; i < n; i++) {
        par[i] = i;
        rank[i] = 0;
    }
}

template<typename T>
T union_find_forest<T>::root(T x)
{
    if (par[x] == x)
        return x;
    T r = root(par[x]);
    par[x] = r; // shrink
    return par[x];
}

