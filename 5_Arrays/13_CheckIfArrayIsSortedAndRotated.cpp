// 🔴🔴LEETCODE 1752 -> Check If Array Is Sorted and Rotated🔴🔴
/*
Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of
positions (including zero). Otherwise, return false.
There may be duplicates in the original array.
Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length],
where % is the modulo operation.

Example 1:
Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 3 positions to begin on the the element of value 3: [3,4,5,1,2].

Example 2:
Input: nums = [2,1,3,4]
Output: false
Explanation: There is no sorted array once rotated that can make nums.

Example 3:
Input: nums = [1,2,3]
Output: true
Explanation: [1,2,3] is the original sorted array.
You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.
 
Constraints:
1 <= nums.length <= 100
1 <= nums[i] <= 100
*/

#include<iostream>
#include<vector>
using namespace std;

bool check(vector<int> &nums)
{
    int count = 0;
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        if (nums[i - 1] > nums[i])
        {
            count++;
        }
    }
    if (nums[n - 1] > nums[0])
    {
        count++;
    }
    return count <= 1;
}

int main()
{
    int n;
    cout << "Enter the size of the nums array:" << endl;
    cin >> n;
    vector<int>nums(n);
    cout << "Enter the elements in the nums array:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }
    if(check(nums))
    {
        cout << "Array is Sorted and Rotated!" << endl;
    }
    else
    {
        cout << "Array is not Sorted and Rotated!" << endl;
    }
    return 0;
}

// TC -> O(n)
// SC -> O(1)