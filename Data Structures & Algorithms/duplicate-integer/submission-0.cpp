#include <unordered_set>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int n : nums) {
            if (s.count(n))
                return true;
            s.insert(n);
        }
        return false;
    }
};