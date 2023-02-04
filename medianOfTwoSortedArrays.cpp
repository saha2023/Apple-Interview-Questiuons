// O(n+mlog(n+m))
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        for(auto it: nums1) nums.push_back(it);
        for(auto it: nums2) nums.push_back(it);
        
        sort(begin(nums), end(nums));
        
        int n = nums.size();
        double ans;
        if(n%2){
            int x = (n+1)/2;
            ans = (double)nums[x-1];
        }
        else{
            int x = n/2;
            ans = (double)((nums[x]+nums[x-1]))/2;
        }
        return ans;
    }
};


//2nd Approach O(log(n+m))
class Solution {
public:
    float findMedianSortedArrays(vector<int>nums1,vector<int>nums2) {
        int m = size(nums1), n = size(nums2);
        if(m>n)
            return findMedianSortedArrays(nums2,nums1);//ensuring that binary search happens on minimum size array
            
        int low=0,high=m,medianPos=((m+n)+1)/2;
        while(low<=high) {
            int cut1 = (low+high)>>1;
            int cut2 = medianPos - cut1;
            
            int l1 = (cut1 == 0)? INT_MIN:nums1[cut1-1];
            int l2 = (cut2 == 0)? INT_MIN:nums2[cut2-1];
            int r1 = (cut1 == m)? INT_MAX:nums1[cut1];
            int r2 = (cut2 == n)? INT_MAX:nums2[cut2];
            
            if(l1<=r2 && l2<=r1) {
                if((m+n)%2 != 0)
                    return max(l1,l2);
                else 
                    return (max(l1,l2)+min(r1,r2))/2.0;
            }
            else if(l1>r2) high = cut1-1;
            else low = cut1+1;
        }
        return 0.0;
    }
};