/*
Problem: Container with most water
Problem Number-11
Platform: LeetCode

Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int right=height.size()-1;
        int left=0,first=0,area=0;
        int maxarea=-1;
        while(left<right){
            int second=right-left;
            if(height[left]<height[right]){
                first=height[left];
                left++;
            }
            else{
                first=height[right];
                right--;
            }
            area=first*second;
            if(area>maxarea){
                maxarea=area;
            }  
        }
        return maxarea;
    }
};