class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = (int) nums.size();
        vector<int> left(n + 1);
        vector<int> right(n + 1);
        left[0] = 1;
        right[n] = 1;
        
        for (int i = 1; i <= n; ++i) {
            left[i] = nums[i - 1] * left[i - 1];
        }
        
        for (int i = n - 1; i >= 0; --i) {
            right[i] = nums[i] * right[i + 1];
        }
        
        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            result[i] = left[i] * right[i + 1];
        }
        
        return result;
    }
};
