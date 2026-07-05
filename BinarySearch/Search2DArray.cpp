/*
Problem: 74. Search a 2D Matrix
Platform: LeetCode
Category: Binary Search, Matrix

Approach:
- Treat the matrix as a virtual sorted 1D array because:
  - Each row is sorted in non-decreasing order.
  - The first element of each row is greater than the last element of the previous row.
- Perform Binary Search on the virtual array indices from 0 to (m × n - 1).
- Convert the middle index into matrix coordinates:
  - row = mid / number_of_columns
  - col = mid % number_of_columns
- Compare the element at (row, col) with the target and adjust the search range accordingly.
- Return true if the target is found; otherwise, return false.

Time Complexity: O(log(m × n))
Space Complexity: O(1)
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left=0;
        int m=matrix.size();
        int n=matrix[0].size();
        int right=(m*n)-1;
        while(left<=right){
            int mid=(left+right)/2;
            int row=mid/n;
            int col=mid%n;
            if(matrix[row][col]>target){
                right=mid-1;
            }
            else if(matrix[row][col]<target){
                left=mid+1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};