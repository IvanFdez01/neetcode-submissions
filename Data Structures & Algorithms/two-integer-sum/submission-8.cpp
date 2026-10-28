#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> s;
        for (int i = 0; i < nums.size(); i++) {
            int j_val = target - nums[i];
            if (s.count(j_val))
                return { s[j_val], i};
            s[nums[i]] = i;
        }
        return {}; // se puede quitar si se asume que existe en el forfor
    }
};
