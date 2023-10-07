/*
Intuition
The Boyer-Moore Majority Vote algorithm can be adapted to find two potential majority elements since the problem asks for elements that appear more than ⌊n/3⌋ times. We initialize two counters and two candidate elements. We iterate through the array and maintain these candidates, reducing the count whenever we find different elements. Finally, we verify whether these candidates appear more than ⌊n/3⌋ times in the array.

Approach
Initialize cnt1, cnt2, el1, and el2. These will be used to keep track of the two potential majority elements and their counts.

Iterate through the array nums:

If cnt1 is 0 and the current element is different from el2, set el1 to the current element and increment cnt1.
Else if cnt2 is 0 and the current element is different from el1, set el2 to the current element and increment cnt2.
Otherwise, if the current element matches el1 or el2, increment the corresponding count.
If none of the above conditions is met, decrement both cnt1 and cnt2.
Reset cnt1 and cnt2 to count the occurrences of el1 and el2 in the array.

Check if the counts of el1 and el2 are greater than ⌊n/3⌋. If they are, add them to the ans vector.

Sort the ans vector in ascending order.

Return the ans vector containing the majority elements.

Note: 
Maximum two element only can be found in the array which apperas n/3 times.

Complexity
Time complexity:O(N)
Space complexity:O(1)
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int cnt1 = 0; 
        int cnt2 = 0;
        int el1=INT_MAX, el2=INT_MAX;
        for(int i = 0; i< n; i++){
            if(cnt1==0 && nums[i]!=el2){
                cnt1++;
                el1 = nums[i];
            }
            else if(cnt2==0 && nums[i]!=el1){
                cnt2++;
                el2 = nums[i];
            }
            else if(nums[i]==el1)cnt1++;
            else if(nums[i]==el2)cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0;
        cnt2=0;
        for(int i = 0; i< n; i++){
            if(el1==nums[i])cnt1++;
            if(el2==nums[i])cnt2++;
        }
        if(cnt1>n/3)ans.push_back(el1);
        if(cnt2>n/3)ans.push_back(el2);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
