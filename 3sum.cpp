#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/* question link -> */
//  we need to store the unique triplets only that sum up to 0

/*
// The brutforce one.
// Time complexity -> O(n^3 * O(log (unique triplet) ) ) -> log() part is for inseting in the set
//  Space complexity -> O( 2 * number of unique triplet ) ; here 2 is because we use set and vector both.
vector<vector<int>> triplet (vector<int> arr, int n)
{
    //  we create the set data structure to store the uniqueness.
    set < vector<int> > st;
    for(int i = 0; i<n; i++)
    {
        for(int j = i + 1; j<n; j++)
        {
            for(int k = j + 1; k<n; k++)
            {
                if(arr[i] + arr[j] + arr[k] == 0)
                {
                    vector<int> temp = {arr[i],arr[j],arr[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
        }
    }

// finally after coming out of the loop , we have unique list of triplet stored in the set.
    vector<vector<int>> ans (st.begin(),st.end());

    return ans;
}

*/


void printVector(vector<vector<int>> arr)
{
    cout<<"printing the 2D vector"<<endl;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void print1Dvector(vector<int> arr)
{
    cout<<"printing the 1D vector"<<endl;
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}
/*
// Better approach -> having time complexity O(n^2 * log ( number of unique triplets))
// space complexity -> 2 * (number of unique elements or triplets) + O(n)

vector<vector<int>> triplet(vector<int> arr, int n)
{
    // first create the set to store the unique triplet.
    set < vector<int> > st;

    for(int i = 0; i<n; i++)
    {   
        // declaring the hashset.
        set<int>hashset;
        for(int j = i+1; j<n; j++)
        {
            int third = -(arr[i] + arr[j]);
            if( hashset.find(third) != hashset.end() )
            {
                vector<int> temp = {arr[i] , arr[j], third};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }

            hashset.insert(arr[j]);
        }
    }

    vector<vector<int>> ans (st.begin(),st.end());

    return ans;
}

*/



// The optimal approach -> using two pointer approach
// Time complexity -> O(n ^ 2) + O(n * log(n)) ( n log(n))-> for sorting
// space complexity -> O(number of unique triplets) (for the vector of vector ans)


vector<vector<int>> triplet(vector<int> arr, int n)
{
    // for using the two pointer approach you need to sort the vector
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;

    for(int i = 0; i<n; i++)
    {
        // agar current element previous ke equal hai, then simply incremnt the i
        if( i > 0 && arr[i] != arr[i-1])
            continue; // don't do anything continue the loop and iteration

        int j = i + 1;
        int k = n -1;

        while( j < k )
        {
            int sum = arr[i] + arr[j] + arr[k];

// if the sum < 0 means, we need to increase the sum to make it equal to 0, so increment j.
            if(sum < 0)
                j++;
            else if (sum > 0)
                k--; // if sum becomes greater then 0
            else
            {
                // when the sum == 0
                vector<int> temp = {arr[i] , arr[j] , arr[k]};
                ans.push_back(temp);

                j++;
                k--;

//  All the below things are done to avoid the duplicate triplets.
// agar previous wala j element equal hai, current j element ke, then simply incremnt the j till they are not equal
                while(j < k && arr[j] == arr[j-1]) j++;

                // same case with k also.
                while (j < k && arr[k] == arr[k+1])
                {
                    k--;
                }
                
            }
        }
    }

    return ans;
}


int main()
{
    vector<int> arr = {-1, -1, 2, 0, 1};

    vector<vector<int>> triples = triplet(arr, 5);
    printVector(triples);
    return 0;
}