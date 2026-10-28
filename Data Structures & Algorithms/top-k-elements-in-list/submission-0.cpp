#include <unordered_map>
#include <vector>
#include <queue>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // hacer mapa de frecuencias en "m"
        unordered_map<int, int> m;
        for (const int& n : nums) {
            if (!m.count(n))
                m[n] = 1;
            else 
                m[n]++;
        }
        
        // volcar a priority queue por valor (no clave) 
        struct MyComparator {
            bool operator()(const pair<int,int>& a, const pair<int,int>& b) {
                if (a.second != b.second)
                    return a.second < b.second;
                return b.second < a.second;
            }
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, MyComparator> p;
        for (const auto& par : m) {
            p.push(par);
        }

        // extraer los k primeros valores a un vector resultado
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(p.top().first);
            p.pop();
        }
        return res;
    }
};
