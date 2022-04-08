#include <algorithm>
#include <vector>
#include <unordered_set>
#include "../utils/utils.h"
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        auto dist = [&](int x, int y) -> int {
            return abs(points[x][0] - points[y][0]) + abs(points[x][1] - points[y][1]);
        };
        int n = points.size();
        DisjointSetUnion dsu(n);
        vector<Edge> edges;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                edges.emplace_back(dist(i, j), i, j);
            }
        }
        sort(edges.begin(), edges.end(), [](Edge a, Edge b) -> int { return a.len < b.len; });
        int ret = 0, num = 1;
        for (auto& e : edges) {
            if (dsu.construct(e.x, e.y)) {
                ret += e.len;
                num++;
                if (num == n) {
                    break;
                }
            }
        }
        return ret;
    }
};