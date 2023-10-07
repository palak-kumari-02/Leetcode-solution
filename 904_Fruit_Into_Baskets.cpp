/*
Intuition
The code is designed to find the maximum number of fruits you can pick with two types of fruits while following specific rules. It maintains two fruit types, e1 and e2, along with their counts cnt1 and cnt2. The intuition behind the approach is to continuously update e1, e2, and their counts as you iterate through the input array. Whenever a third type of fruit is encountered, the code removes fruits from the start of the subarray to maintain only two types. The answer is updated to store the maximum length of the subarray with two types of fruits.

Approach
Initialize variables to store e1, e2, cnt1, cnt2, i, j, and ans.

Iterate through the array using two pointers, i and j, to define the subarray.

Update e1, e2, and their counts based on the current fruit type.

If a third type of fruit is encountered, remove fruits from the start of the subarray to maintain only two types.

Continuously update ans with the maximum length of the subarray containing two types of fruits.

Return the final answer.

Complexity
Time complexity:O(N)
Space complexity:O(1)
Code
*/
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int e1 = INT_MAX, e2 = INT_MAX;
        int cnt1 = 0, cnt2 = 0;
        int i = 0, j = 0;
        int ans = 0;
        while(j<n){
            if(cnt1==0 && e2!=fruits[j]){
                // If cnt1 is 0 and the current fruit type is not e2, assign e1 to the current fruit.
                e1 = fruits[j];
                cnt1++;
            }
            else if(cnt2==0 && e1!=fruits[j]){
                // If cnt2 is 0 and the current fruit type is not e1, assign e2 to the current fruit.
                e2 = fruits[j];
                cnt2++;
            }
            else if(e1==fruits[j]) cnt1++; // If the current fruit type matches e1, increment cnt1.
            else if(e2==fruits[j]) cnt2++; // If the current fruit type matches e2, increment cnt2.
            else{
            // A new fruit type is encountered; remove fruits to maintain only two types.
                while(cnt1>0 && cnt2>0){
                    if(e1==fruits[i]) cnt1--;
                    else if(e2==fruits[i]) cnt2--;
                    i++;
                }
                // Reassign e1 and e2 based on the current fruit type.
                if(cnt1==0 && e2!=fruits[j]){
                    e1 = fruits[j];
                    cnt1++;
                }
                if(cnt2==0 && e1!=fruits[j]){
                    e2 = fruits[j];
                    cnt2++;
                }
            }                 
            j++;   
            // Update the maximum length of the subarray with two types of fruits.
            ans = max(ans, j-i);        
        }
        return ans;
    }
};
