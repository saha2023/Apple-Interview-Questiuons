class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0;
        int maxSum = -1e9;
        for(int it: nums){
            currSum += it;
            maxSum = max(maxSum, currSum);
            if(currSum<0) currSum = 0;
        }
        return maxSum;
    }
};