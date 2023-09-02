/*
Question -> given matrix of M*N such that 
            1. integers in each row sorted left to right
            2. integers in each col sorted top to bottom

            return whether the target is present in the array or not.
*/
/*
Algorithm to solve this problem -> use the concept similar to binary search but not proper binary search because the element is not sorted when converted in 1D form.

*/

#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int total_row = matrix.size();
    int total_col = matrix[0].size();

// this current_row and current_col is the current index of the matrix. They just first stand to this position.
    int current_row = 0;
    int current_col = total_col-1;

    // now applying the conditions -> 
    // the below conditions is like this because - we going to decrease the col length as we started the col from total_col -1
    // but we have to increse the current_row because we started form the 0.
    while(current_row < total_row && current_col >= 0){
        int element = matrix[current_row][current_col];
        
        if(element == target)
            return 1;
        else if(element < target)
            current_row++;
        else
            current_col--;
    }

    return 0;

}

int main()
{
    vector<vector<int>>matrix {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,32},{10,13,14,17,24},{18,21,23,26,30}};

    int ans = searchMatrix(matrix,9);
    cout<<"(1 -> present and 0 -> absent) = "<<endl<<ans<<endl;

    return 0;
}