class Solution {
    public int largestSumAfterKNegations(int[] nums, int k) {
        int n=nums.length;
        Arrays.sort(nums);
        for(int i=0;i<n&&k>0&&nums[i]<0;i++,k--){
            nums[i]=-nums[i];
        }
        int min=nums[0];
        int sum=0;
        for(int  num:nums){
            sum+=num;
            min=Math.min(min,num);
        }
        return k%2==0 ? sum:sum-2*min;
    }
}