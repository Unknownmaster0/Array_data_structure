/*
    Question -> https://leetcode.com/problems/rotate-image/
    rotate a 2D matrix 90 degree clockwise
    1 2 3       7 4 1
    4 5 6   =   8 5 2
    7 8 9       9 6 3

    Approach -> By changing the rows and coloum of elements we can achieve this.
                we are looking the pattern that 1st coloum has become the 1st row from the bottom to top.
                arr[0][0]  =  arr[0][2]
                arr[1][0]  =  arr[0][1]
                so we say that from here as arr[col][row] = arr[2-row][col]; // we will not iterating the col inspite we will iterate the row only.
                                            here just changing the index for the ans approach.
*/
#include <iostream>
#include <vector>
using namespace std;

// printing the rotated vector/matrix/array:
void printArray(vector<vector<int>> arr)
{
    for (int row = 0; row < arr.size(); row++)
    {
        for (int col = 0; col < arr[0].size(); col++)
        {
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return;
}

// rotating function/method ->
void rotate90(vector<vector<int>> arr)
{

    int total_row = arr.size();
    int total_col = arr[0].size();

    // vector<vector<int>> ans;

    for (int col = 0; col < total_col; col++)
    {
        // vector<int> temp;// 2d vector me store krne ke liye pahle 1d vector me store krwalo and then 1d vector ko push back kr do 2d vector me.

        for (int row = 0; row < total_row; row++)
        {
// aise 2d vector me push back nhi hota hai // ans[col][row]  =  arr[total_row - 1 - row][col]; 
            arr[col][row] = arr[total_row - 1 - row][col];// main logic is here, actually we are assigning values row wise thus need to constant the row term,so used col in place of row
            // right side is the first col value that we are assigning to 1st row which is in left.
            // temp.push_back(arr[total_row - 1 - row][col]);
        }
        // ans.push_back(temp);
    }

    // printArray(ans);
    printArray(arr);

    return;
}

int main()
{
    vector<vector<int>> arr;
    arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    rotate90(arr);

    return 0;
}