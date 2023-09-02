/*
    Question -> return whether the target is present in the matrix or not.
                given matrix of m*n such that integers row are sorted in left to right.
*/
/*
Approach -> we use binary search approach to find the target in the matrix.
1 ,3 ,5 ,7
10,11,16,20 = in 1D form = 1 3 5 7 10 11 16 20 23 30 34 60
23,30,34,60 

target = 3
*/

#include<iostream>
#include<vector>
using namespace std;

// bool searchMatrix(vector<vector<int>>& matrix, int target) {

//     int total_row = matrix.size();
//     int total_col = matrix[0].size();

//     // initialising the start and end index 
//     int start = 0;
//     int end = total_col*total_row-1; // total_row = 3,total_col = 4, then end = 11

//     while(start <= end){
//         int mid = start + (end - start)/2;
//         int element = matrix[mid / total_col][mid % total_col];

//         if(element == target)
//             return 1;
//         else if(element < target)
//             start = mid + 1;
//         else    
//             end = mid - 1;
//     }

//     return 0;

// }



// Approach 2 : 
bool searchMatrix(vector<vector<int>>& matrix, int target) {

    int total_row = matrix.size();
    int total_col = matrix[0].size();

    // first finding exact row of the target
    int row = -10;// any arbiturary value that doesn't lie in the matrix index range.
    int i = 0;
    while(i < total_row - 1){
        if(matrix[i][0] < target && matrix[i+1][0] > target){
            row = i;
            break;
        }
        else if(matrix[i][0] == target)
            return 1;

        i++;
    }

    if(row == -10)
        row = i;

// now finding the exact coloumn of the target if it exist in the array.
    int start = 0; 
    int end = total_col - 1;
    while(start <= end){
        int mid = (start + end) / 2;
        if(matrix[row][mid] == target){
            return 1;
        }
        else if(matrix[row][mid] < target ){
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    return 0;
}



int main()
{
    vector<vector<int>>matrix {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int ans = searchMatrix(matrix,16);
    // cout<<"1-> P & 0-> A"<<endl;
    cout<<ans<<endl;
    return 0;
}