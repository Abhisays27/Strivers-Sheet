class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();

        int s=0;
        int e=n-1;
        int mid;

        while(s<e){
          mid = s+(e-s)/2;

            if(nums[mid+1]>nums[mid]){
                s=mid+1;
            }
            else{
                e=mid;
            }
        }
        return s;
        
    }
};