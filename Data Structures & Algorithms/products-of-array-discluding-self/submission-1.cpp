class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int numZeros = 0;
        vector<bool> zeros(nums.size());
        int acum = 1;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zeros[i] = true;
                numZeros++;
            } else {
                acum *= nums[i];
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (zeros[i]) {
                res.push_back(numZeros == 1 ? acum : 0);
            }
            else {
                if (numZeros >= 1)
                    res.push_back(0);
                else
                    res.push_back(acum/nums[i]);
            }
        }
        return res;
    }
};
