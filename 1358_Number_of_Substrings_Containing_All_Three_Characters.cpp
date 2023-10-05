/*
  Intuition
The goal is clear, that is atleast string must contain all the 3 characters in within i & j then any number of a's , b's and c's are acceptable for the solutiion

Approach
The objective is to count the number of substrings that contain all three distinct characters 'a', 'b', and 'c'. The code uses a sliding window approach to achieve this.

Here's an approach that explains how the code works:

Initialize variables:

n is the length of the input string s.
i and j are pointers that define the current substring.
ans is the answer that will be returned, representing the number of valid substrings.
v is a vector of size 3, used to keep track of the count of characters 'a', 'b', and 'c' within the current substring.
Use a while loop with j to traverse the string from the left to the right. Inside the loop:

Update the count of the character s[j] - 'a' in the v vector.
Check if the current substring contains all three characters 'a', 'b', and 'c'. This is done by calling the check function, which returns true if all counts in the v vector are greater than zero.
If all three characters are found in the current substring, increment ans by n - j. This is because all substrings starting from i to j that contain 'a', 'b', and 'c' are valid, and there are n - j such substrings.
Move the left pointer i to the right while the substring still contains all three characters. Decrease the count of the character s[i] - 'a' in the v vector.
Continue this process until the right pointer j reaches the end of the string.

Finally, return the ans, which represents the total count of valid substrings containing 'a', 'b', and 'c'.

This approach efficiently counts the number of valid substrings by maintaining a sliding window and keeping track of character counts within that window. It has a time complexity of O(n) because both i and j traverse the string only once.

Complexity
Time complexity:O(N)
Space complexity:O(1)
since the vectors size is 3 fix that is 3 only
*******************Code***********************
*/
class Solution {
public:
    bool check(vector<int> v){
        for(int i=0; i<v.size(); i++)if(v[i]==0)return false;
        return true;
    }
    int numberOfSubstrings(string s) {
        int n = s.size();
        int i=0;
        int j=0;
        int ans=0;
        vector<int> v(3,0);
        while(i<n && j<n){
            int ch = s[j]-'a';
            v[ch]++;
            while(check(v)){
                ans+=n-j;
                v[s[i]-'a']--;
                i++;
            }
            j++;
        }
        return ans;
    }
};
