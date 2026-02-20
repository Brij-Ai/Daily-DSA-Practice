#include <vector>
using namespace std;

// Solution 1: Time complexity O(n) and space complexity O(1);
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        // vector<int>preSum(nums.size());
        int res = 0, left[2] = {}, right[2] = {};
        for(int i=0; i<nums.size();i++){
            right[i%2] += nums[i];
        }
        for(int i=0; i<nums.size(); i++){
            right[i % 2] -= nums[i];
            res += left[0] + right[1] == left[1] + right[0];
            left[i % 2] += nums[i];
        }
        return res;
    }
};