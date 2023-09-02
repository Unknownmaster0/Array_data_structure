/*
Question -> https://leetcode.com/problems/spiral-matrix/

            Given an m x n matrix, return all elements of the matrix in spiral order.

            Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
            1 2 3       
            4 5 6   =   1,2,3,6,9,8,7,4,5
            7 8 9
            Output: [1,2,3,6,9,8,7,4,5]
            visualise this in my copy
*/
#include<iostream>
#include<vector>
using namespace std;

void printans(vector<int>ans){
    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return ;
}

void spiralPrint(vector<vector<int>>arr){
    vector<int>ans;
    // finding the rows and cols in the arr
    int total_rows = arr.size();// this will give the number of rows of the vector
    int total_cols = arr[0].size();// this will check ke arr[0] ka size kitna hai wo cols ke equal hoga

// // if total_row == 1 
//     if(total_rows == 1){
//         for(int col = 0; col<total_cols; col++){
//             ans.push_back(arr[total_rows-1][col]);
//         }
//         return ans;
//     }

    // we need to know or find some index for the loop to iterate
    int startRow = 0;
    int startCol = 0;
    int endRow = total_rows -1;
    int endCol = total_cols - 1;

    // total elements in the arr -> 
    int total = total_rows * total_cols ;
    int count = 0; // for comparing to the total elements

    while(count < total){
        // step 1-> printing the first row
        for(int col = startCol; col <= endCol; col++){
            ans.push_back(arr[startRow][col]);
            count++;
        }
        startRow++; // incrementing the start rows

        // step 2-> printing the end col
        for(int row = startRow;  row <= endRow; row++){
            ans.push_back(arr[row][endCol]);
            count++;
        }
        endCol--;

        // step 3-> printing the end rows
        for(int col = endCol; col >= startCol; col--){
            ans.push_back(arr[endRow][col]);
            count++;
        }
        endRow--;

        // step 4-> printing the starting cols
        for(int row = endRow; row >= startRow; row--){
            ans.push_back(arr[row][startCol]);
            count++;
        }
        startCol++;

    }
    

// till here we have push all the elements in the ans vector
    printans(ans);

    return;
}

int main()
{
    vector<vector<int>>arr;
    arr = {{1,2,3},{4,5,6},{7,8,9}};
    cout<<"Number of rows-> "<<arr.size()<<endl;
    cout<<"Number of cols-> "<<arr[0].size()<<endl;
    spiralPrint(arr);
    
    return 0;
}