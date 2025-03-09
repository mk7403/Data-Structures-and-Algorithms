// 🔴🔴LEETCODE 983 -> Minimum Cost For Tickets🔴🔴
/*
You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an
integer array days. Each day is an integer from 1 to 365.
Train tickets are sold in three different ways:
a 1-day pass is sold for costs[0] dollars,
a 7-day pass is sold for costs[1] dollars, and
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.
For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
Return the minimum number of dollars you need to travel every day in the given list of days.

Example 1:
Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
In total, you spent $11 and covered all the days of your travel.

Example 2:
Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
Output: 17
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1, 2, ..., 30.
On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
In total, you spent $17 and covered all the days of your travel.

Constraints:
1 <= days.length <= 365
1 <= days[i] <= 365
days is in strictly increasing order.
costs.length == 3
1 <= costs[i] <= 1000
*/
// ___________________________________________________________________________________________________________________
/*
// 🔴🔴RECURSION🔴🔴
#include <iostream>
#include <vector>
using namespace std;

int mincostTickets_helper(vector<int> &days, vector<int> &costs, int i)
{ // i will traverse days array
    // Base condition
    if (i >= days.size())
        return 0;

    // Solution for 1 case
    // 1 Day Pass Taken
    int cost1 = costs[0] + mincostTickets_helper(days, costs, i + 1);

    // 7 Days Pass Taken
    int passEndDay = days[i] + 7 - 1; // 7-1 because we have to include the day we have taken the pass on
    int j = i;                        // taking j=i, so we can't call function for i+1, because when we take a 7 days pass, we need to specify the end day of the pass.

    while (j < days.size() && days[j] <= passEndDay) // which days will be covered in the pass and on which day the validity of the pass expires
    {
        j++;
    }
    int cost7 = costs[1] + mincostTickets_helper(days, costs, j); // j is post-inc operator, so when 7 days are covered, it will point to the 8th day and then terminate the loop

    // 30 Days Pass Taken
    passEndDay = days[i] + 30 - 1;
    j = i;

    while (j < days.size() && days[j] <= passEndDay)
    {
        j++;
    }
    int cost30 = costs[2] + mincostTickets_helper(days, costs, j);

    return min(cost1, min(cost7, cost30));
}

int mincostTickets(vector<int> &days, vector<int> &costs)
{
    return mincostTickets_helper(days, costs, 0);
}

int main()
{
    int n, m;
    cout << "Enter size of days array: " << endl;
    cin >> n;
    vector<int>days(n);
    cout << "Enter the days: " << endl;
    for(int i=0; i<n; i++)
    {
        cin >> days[i];
    }
    cout << "Enter size of costs array: " << endl;
    cin >> m;
    vector<int>costs(m);
    cout << "Enter the costs: " << endl;
    for(int i=0; i<m; i++)
    {
        cin >> costs[i];
    }
    cout << "Minimum cost required: " << mincostTickets(days, costs) << endl; 
    return 0;
}
// TC -> O(3^n) -> For every case, we make 3 calls (cost of 1 day, 7 days, 30 days passes)
// SC -> O(n) -> Depth of the recursive tree (stack) is n for n sized days array
*/

// ___________________________________________________________________________________________________________________

/*
// 🔴🔴MEMOIZATION(Top-Down)🔴🔴

#include <iostream>
#include <vector>
using namespace std;

int solveUsingMem(vector<int> &days, vector<int> &costs, int i, vector<int> &dp)
{
    // Base condition
    if (i >= days.size())
        return 0;

    // Step2: Check if the answer is already present inside the dp array
    if (dp[i] != -1)
    {
        return dp[i];
    }

    // Solution for 1 case
    // 1 Day Pass Taken
    int cost1 = costs[0] + solveUsingMem(days, costs, i + 1, dp);

    // 7 Days Pass Taken
    int passEndDay = days[i] + 7 - 1; // 7-1 because we have to include the day we have taken the pass on
    int j = i;                        // taking j=i, so we can't call function for i+1, because when we take a 7 days pass, we need to specify the end day of the pass.

    while (j < days.size() && days[j] <= passEndDay) // which days will be covered in the pass and on which day the validity of the pass expires
    {
        j++;
    }
    int cost7 = costs[1] + solveUsingMem(days, costs, j, dp); // j is post-inc operator, so when 7 days are covered, it will point to the 8th day and then terminate the loop

    // 30 Days Pass Taken
    passEndDay = days[i] + 30 - 1;
    j = i;

    while (j < days.size() && days[j] <= passEndDay)
    {
        j++;
    }
    int cost30 = costs[2] + solveUsingMem(days, costs, j, dp);

    // Step3: Store the answer in dp array and return
    dp[i] = min(cost1, min(cost7, cost30));
    return dp[i];
}

int mincostTickets(vector<int> &days, vector<int> &costs)
{
    // Step1: Create the dp array: 1d dp as i is varying till days size
    vector<int> dp(days.size(), -1);
    return solveUsingMem(days, costs, 0, dp);
}

int main()
{
    int n, m;
    cout << "Enter size of days array: " << endl;
    cin >> n;
    vector<int>days(n);
    cout << "Enter the days: " << endl;
    for(int i=0; i<n; i++)
    {
        cin >> days[i];
    }
    cout << "Enter size of costs array: " << endl;
    cin >> m;
    vector<int>costs(m);
    cout << "Enter the costs: " << endl;
    for(int i=0; i<m; i++)
    {
        cin >> costs[i];
    }
    cout << "Minimum cost required: " << mincostTickets(days, costs) << endl; 
    return 0;
}
// TC -> O(n^2)
// SC -> O(n)

*/
// ___________________________________________________________________________________________________________________

// 🔴🔴TABULATION(Bottom-Up)🔴🔴

#include <iostream>
#include <vector>
using namespace std;

int solveUsingTab(vector<int> &days, vector<int> &costs, int i)
{
    // Step1: Create the dp array: 1d dp as i is varying till days size
    vector<int> dp(days.size() + 1, 0);

    // Step2: Check the base condition -> already 0
    // Base condition
    // if(i >= days.size()) return 0;

    // Step3: Main iteration logic
    for (int i = days.size() - 1; i >= 0; i--)
    {
        // Solution for 1 case
        // 1 Day Pass Taken
        int cost1 = costs[0] + dp[i + 1];

        // 7 Days Pass Taken
        int passEndDay = days[i] + 7 - 1; // 7-1 because we have to include the day we have taken the pass on
        int j = i;                        // taking j=i, so we can't call function for i+1, because when we take a 7 days pass, we need to specify the end day of the pass.

        while (j < days.size() && days[j] <= passEndDay) // which days will be covered in the pass and on which day the validity of the pass expires
        {
            j++;
        }
        int cost7 = costs[1] + dp[j]; // j is post-inc operator, so when 7 days are covered, it will point to the 8th day and then terminate the loop

        // 30 Days Pass Taken
        passEndDay = days[i] + 30 - 1;
        j = i;

        while (j < days.size() && days[j] <= passEndDay)
        {
            j++;
        }

        int cost30 = costs[2] + dp[j];

        dp[i] = min(cost1, min(cost7, cost30));
    }
    return dp[0];
}

int mincostTickets(vector<int> &days, vector<int> &costs)
{
    return solveUsingTab(days, costs, 0);
}

int main()
{
    int n, m;
    cout << "Enter size of days array: " << endl;
    cin >> n;
    vector<int>days(n);
    cout << "Enter the days: " << endl;
    for(int i=0; i<n; i++)
    {
        cin >> days[i];
    }
    cout << "Enter size of costs array: " << endl;
    cin >> m;
    vector<int>costs(m);
    cout << "Enter the costs: " << endl;
    for(int i=0; i<m; i++)
    {
        cin >> costs[i];
    }
    cout << "Minimum cost required: " << mincostTickets(days, costs) << endl; 
    return 0;
}
// TC -> O(n^2)
// SC -> O(n)
