//Aproach 1 -> T-O(n) S-O(2n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = size(nums);
        vector<int> pref(n), suff(n);

        pref[0] = 1;
        for(int i=1;i<n;i++){
            pref[i] = (pref[i-1]*nums[i-1]);
        }

        suff[n-1] = 1;
        for(int i = n-2;i>=0;i--){
            suff[i] = (nums[i+1] * suff[i+1]);
        }

        for(int i=0;i<n;i++){
            pref[i] *= suff[i];
        }

        return pref;
    }
};

//slightly more optimised aproach
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = size(nums);
        vector<int> pref(n);

        pref[0] = 1;
        for(int i=1;i<n;i++){
            pref[i] = (pref[i-1]*nums[i-1]);
        }

        int suff = 1;
        for(int i=n-1;i>=0;i--){
            pref[i] *= suff;
            suff *= nums[i];
        }

        return pref;
    }
};