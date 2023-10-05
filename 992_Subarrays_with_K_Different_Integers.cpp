/*
# Subarrays with K Distinct Integers

This code provides a C++ solution to the problem of finding the number of subarrays in an input vector `nums` that contain exactly `k` distinct integers. The problem is solved using a sliding window technique with the help of a `map` data structure.

## Code Explanation

### Class Definition
cpp
*/
class Solution {
public:
    // Function to find the number of subarrays with exactly k distinct integers
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        return solve(nums, k, n) - solve(nums, k - 1, n);
    }

    // Function to calculate the number of subarrays with at most k distinct integers
    int solve(vector<int>& nums, int k, int n) {
        map<int, int> m;  // Map to store the frequency of each integer in the current subarray
        int i = 0;        // Left pointer of the subarray
        int j = 0;        // Right pointer of the subarray
        int ans = 0;      // Variable to store the answer

        while (j < n) {
            m[nums[j]]++; // Add the current element to the map and increase its count

            // If the number of distinct integers in the current subarray exceeds k
            while (m.size() > k) {
                m[nums[i]]--; // Decrease the count of the leftmost element
                if (m[nums[i]] == 0)
                    m.erase(nums[i]); // If its count becomes 0, remove it from the map
                i++; // Move the left pointer to the right to make the subarray valid again
            }

            // Calculate the number of subarrays that can be formed with the current subarray
            ans += j - i + 1;

            j++; // Move the right pointer to the right to consider the next element
        }

        return ans;
    }
};

/*
### Explanation

1. The code defines a class named `Solution` that contains two public methods: `subarraysWithKDistinct` and `solve`.

2. The `subarraysWithKDistinct` method takes the input vector `nums` and an integer `k` as its arguments and calculates the number of subarrays with exactly `k` distinct integers in `nums`.

3. The `solve` method takes the input vector `nums`, an integer `k`, and the size of the vector `n` as its arguments. It calculates the number of subarrays with at most `k` distinct integers in `nums`.

4. Inside the `solve` method, a `map<int, int>` named `m` is used to keep track of the frequency of each integer in the current subarray.

5. Two pointers `i` and `j` are used to represent the left and right boundaries of the current subarray.

6. The `while` loop with the `j` pointer is responsible for expanding the subarray while maintaining at most `k` distinct integers in it. When `m.size()` exceeds `k`, the `while` loop with the `i` pointer contracts the subarray from the left side until it satisfies the condition again.

7. The variable `ans` is updated by adding the number of subarrays that can be formed with the current subarray, which is calculated as `j - i + 1`.

8. The `j` pointer is then moved to the right, and the process continues until the entire array `nums` is traversed.

9. Finally, the `ans` variable is returned as the result of the `solve` method, and the difference between `solve(nums, k, n)` and `solve(nums, k - 1, n)` is returned as the result of the `subarraysWithKDistinct` method, which gives the number of subarrays with exactly `k` distinct integers.
*/
