#include <unordered_set>
#include <map>
#include <optional>
#include <utility>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> done;
        map<int,bool> m;
        for (const int n : nums) {
            if (done.count(n))
                continue;

            if (m.count(n-1)) {
                // cout << "Actualizando la clave " << n-1 << "\n";
                m[n-1] = true;
            } else if (!m.count(n)) {
                // cout << "Anadiendo la clave " << n << "\n";
                m[n] = false;
            }
            done.insert(n); 
        }
        for (const auto& p : m) {
            cout << p.first << " : " << p.second << "\n";
        }

        optional<pair<int,bool>> prev = {};
        int acum = 0;
        int max_chain = -1;
        for (const auto& cur : m) {
            // save & reset acum o bien seguir acumulando 
            if (prev.has_value() && (cur.first - prev->first) > (prev->second ? 2 : 1)) { 
                cout << "Actualizando por " << prev->first << " : " << cur.first << "\n";
                if (acum > max_chain)
                    max_chain = acum;
                acum = 0;
            }
            // logica de acumular: +=1 o +=2 
            if (cur.second)
                acum += 2;
            else
                acum += 1;

            prev = cur;
        }
        return max(max_chain, acum);
    }
};
