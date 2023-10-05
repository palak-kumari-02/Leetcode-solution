/*
 * Spiral Matrix Traversal
 *
 * Given a 2D matrix 'arr', this algorithm traverses and extracts its elements
 * in a spiral order and returns them as a 1D vector.
 *
 * Algorithm:
 * 1. Initialize variables to keep track of the top, bottom, left, and right boundaries.
 * 2. While the result vector's size is less than the total number of elements:
 *    a. Traverse from left to right along the top boundary, adding elements to the result vector.
 *    b. Increment the top boundary.
 *    c. Traverse from top to bottom along the right boundary, adding elements to the result vector.
 *    d. Decrement the right boundary.
 *    e. Traverse from right to left along the bottom boundary, adding elements to the result vector.
 *    f. Decrement the bottom boundary.
 *    g. Traverse from bottom to top along the left boundary, adding elements to the result vector.
 *    h. Increment the left boundary.
 * 3. Return the result vector containing elements in spiral order.
 *
 * Time Complexity: O(N), where N is the total number of elements in the matrix.
 */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        int sr = 0, sc = 0;
        int er = n - 1;
        int ec = m - 1;
        vector<int> ans;
        int len = n * m;

        while (ans.size() < len) {
            // Traverse from left to right along the top boundary.
            for (int j = sc; ans.size() < len && j <= ec; j++)
                ans.push_back(arr[sr][j]);
            if (sr < er) sr++;

            // Traverse from top to bottom along the right boundary.
            for (int i = sr; ans.size() < len && i <= er; i++)
                ans.push_back(arr[i][ec]);
            if (ec > sc) ec--;

            // Traverse from right to left along the bottom boundary.
            for (int j = ec; ans.size() < len && j >= sc; j--)
                ans.push_back(arr[er][j]);
            if (sr < er) er--;

            // Traverse from bottom to top along the left boundary.
            for (int i = er; ans.size() < len && i >= sr; i--)
                ans.push_back(arr[i][sc]);
            if (ec > sc) sc++;
        }

        return ans;
    }
};
