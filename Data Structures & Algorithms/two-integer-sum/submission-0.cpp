#include <tuple>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int acum = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i + 1; j++) {
                if (i != j && nums[i] + nums[j] == target) {
                    return {j,i};
                }
            }
        }
        return {-1,-1}; // se puede quitar si se asume que existe en el forfor
    }
};
