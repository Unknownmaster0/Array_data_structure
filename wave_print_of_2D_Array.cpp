/*
    Question-> for given 2D array having (n * m) rows and coloumns. print the elements in wave order
    wave print = print the first coloumn top to bottom and second colomn bottom to top and third as top to bottom and furthur goes on 
    return the final ans in one-D vector.
*/
#include<iostream>
#include<vector>
using namespace std;

vector<int> waveprint(vector<vector<int>>arr,int nRows,int mCols){
    vector<int>ans;

    if (nRows == 1){
        for(int col = 0; col< mCols; col++){
            ans.push_back(arr[nRows-1][col]);
        }
        return ans;
    }
    
    for(int col = 0; col < mCols; col++){
        if(col % 2 == 0){
            for(int row = 0; row < nRows; row++)
                ans.push_back(arr[row][col]);
        }
        else{
            for(int row = nRows-1; row >= 0; row--)
                ans.push_back(arr[row][col]);
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>>arr;
    arr = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};// rows = 2,col= 2;
    int rows = 3; 
    int cols = 4;
    
    vector<int> ans = waveprint(arr,rows,cols);
    for(int i = 0; i < (rows * cols); i++) // as ans is 1-D array and its length will become after taking all the elements of the arr is rows * cols
        cout<<ans[i]<<"  ";

    cout<<endl;
    return 0;
}