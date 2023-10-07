/*
  Intuition
The intuition behind this code is to find the minimum length of a subarray in the given array nums such that the sum of the subarray elements is greater than or equal to the given target value. This is essentially a sliding window approach where we maintain two pointers i and j to track the subarray, and we move the window to find the minimum subarray length that meets the condition.

Approach
Initialize variables ans (to store the minimum subarray length), sum (to keep track of the current sum of the subarray), i (the left pointer of the window), and j (the right pointer of the window).

Iterate through the array using the pointers i and j.

Increment sum by adding the element at index j to it.
While sum is greater than or equal to the target, we calculate the length of the current subarray (which is j - i + 1) and update ans with the minimum of its current value and the newly calculated length.
Then, we decrement sum by subtracting the element at index i and increment i to move the left pointer of the window.
Continue this process until we reach the end of the array. We also increment j to expand the window.

Finally, return ans as the minimum subarray length that meets the condition. If no such subarray is found, return 0.

Complexity
Time complexity:O(N)
Space complexity:O(1)
Code
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        int sum = 0;
        int i=0, j=0;
        while(i<n && j<n){
            sum+=nums[j];
            cout << sum << " " ;
            while(sum>=target){
                if(sum>=target)ans = min(ans, j-i+1);
                sum-=nums[i];
                i++;
            }                
            if(sum<target)j++;
        }
        if(ans<INT_MAX)return ans;
        return 0;
    }
};
