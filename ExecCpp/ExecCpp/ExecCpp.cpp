
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Edge {
    unsigned long long counter = 0;
};


int main()
{
    int n;
    std::cin >> n;
    double denom = 0;

    for (size_t i = 0; i < n; i++)
    {
        double a;
        cin >> a;
        denom += 1.0 / a;
    }

    cout << 1.0 / denom << endl;




}


