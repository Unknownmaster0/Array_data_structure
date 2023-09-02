#include <iostream>
#include <vector>
using namespace std;

//  question -> https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1?page=1&sprint=ca8ae412173dbd8346c26a0295d098fd&sortBy=difficulty

// Function to find maximum of each subarray of size k.
vector<int> max_of_subarrays(int *arr, int n, int k)
{
    vector<int> ans;
    // start -> point at start of window
    // itr -> iterate throughout the window
    // maxi -> for finding the max element.
    // k -> size of the window
    int start = 0, itr = 0, maxi = -1;

    while (itr < n)
    {
        maxi = max(maxi, arr[itr]);
        if (itr - start + 1 < k)
            itr++;

        else // it means you achived the window size, then push back maxi
        {
            ans.push_back(maxi);

            if (arr[start] == maxi) // time to swich the next window
            {
                start++;
                itr = start;
                maxi = -1; // start maxi from starting.
            }
            else
            {
                // we are partially in the previous window, and the finding max from there
                start++;
                itr++;
            }
        }
    }
    return ans;
}

int main()
{

    return 0;
}