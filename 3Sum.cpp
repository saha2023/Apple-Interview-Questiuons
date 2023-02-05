class Solution {
private:
    vector<vector<int>>twoSum(vector<int>& nums, int i, int j, int tar){
        int s = i, e = j;
        vector<vector<int>>ans;
        while(s<e){
            if(nums[s]+nums[e]==tar){
                ans.push_back({nums[s], nums[e]});
                while(s<e and nums[s] == nums[++s]);
                while(s<e and nums[e] == nums[--e]);
            }
            else if(nums[s]+nums[e]<tar) s++;
            else e--;
        }
        return ans;
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        vector<vector<int>>ans;
        for(int i=0;i<=n-3;){
            vector<vector<int>>sAns = twoSum(nums, i+1, n-1, -1*nums[i]);
            for(vector<int>v:sAns){
                v.push_back(nums[i]);
                ans.push_back(v);
            }
            while(i<=n-3 and nums[i] == nums[++i]);
        }
        return ans;
    }
};