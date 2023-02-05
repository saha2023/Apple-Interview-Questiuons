class Solution {
private:
    int n;
    void dfs(vector<int>&nums, vector<vector<int>>&ans, vector<int>&sAns){
        if(sAns.size()==n){
            ans.push_back(sAns);
            return;
        }
        for(int i=0;i<n;i++){
            if(nums[i] == -11) continue;
            int val = nums[i];
            sAns.push_back(nums[i]);
            nums[i] = -11;
            dfs(nums, ans, sAns);
            sAns.pop_back();
            nums[i] = val;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        n = nums.size();
        vector<int>sAns;
        dfs(nums, ans, sAns);
        return ans;
    }
};