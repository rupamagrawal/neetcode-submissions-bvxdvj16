class Solution {
    public List<List<Integer>> combinationSum(int[] nums, int target) {
        List<Integer>ls = new ArrayList<>();
        List<List<Integer>>ans = new ArrayList<>();

        fun(target, 0, ls, ans, nums);
        return ans;

    }

    void fun(int target, int ind, List<Integer>ls, List<List<Integer>> ans, int[] nums){
        if(target==0){
            ans.add(new ArrayList<>(ls));
            return;
        }

        if(ind>=nums.length )return;

        //pick
        if(nums[ind]<=target){
        ls.add(nums[ind]);
        fun(target-nums[ind], ind, ls, ans, nums);
        ls.remove(ls.size() -1);
        }

        fun(target, ind+1, ls, ans, nums);
    }
}
