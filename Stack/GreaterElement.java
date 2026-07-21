/*
    Problem No.   : 496
    Problem Name  : Next Greater Element I
    Platform      : LeetCode
    Category      : Stack, HashMap
    Approach      : Use a monotonic decreasing stack to find the next greater element for each number in nums2 and store the mappings in a HashMap.
    Time Complexity : O(n + m)
    Space Complexity: O(n)
*/
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        HashMap<Integer,Integer> map=new HashMap<>();
        int[] res=new int[nums1.length];
        Stack<Integer> st=new Stack<>();
        for(int n:nums2){
            while(!st.isEmpty() && st.peek()<n){
                map.put(st.pop(),n);
            }
            st.push(n);
        }
        while(!st.isEmpty()){
            map.put(st.pop(),-1);
        }
        for(int i=0;i<nums1.length;i++){
            res[i]=map.get(nums1[i]);
        }
        return res;

    }
}