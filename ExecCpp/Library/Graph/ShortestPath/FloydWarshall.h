#pragma once

#include <vector>

template <typename T>
void applyFloydWarshall(std::vector<std::vector<T>>& d) {
    for (int i = 0; i < d.size(); i++)
    {
        for (int j = 0; j < d.size(); j++)
        {
            for (int k = 0; k < d.size(); k++)
            {
                d[j][k] = std::min(d[j][k], d[j][i] + d[i][k]);
            }
        }
    }
}
