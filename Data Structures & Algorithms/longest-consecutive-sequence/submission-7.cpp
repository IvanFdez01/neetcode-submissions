#include <unordered_set>
#include <map>
#include <optional>
#include <utility>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    int best = 0;
    for (int n : s) {
        if (s.count(n - 1)) continue;   // n no es inicio de cadena, lo salto
        int len = 1, cur = n;
        while (s.count(cur + 1)) { cur++; len++; }
        best = max(best, len);
    }
    return best;
}
};
