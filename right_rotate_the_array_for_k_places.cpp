/*
    Question -> https://leetcode.com/problems/rotate-array/
                this is to rotate the right of the array.with place K.

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    // *************  Nice Approach **************
// // this is nice approach but have TLE in some test cases.
//     while(k){
// // storing the first n-1 element in the temp vector.
//         vector<int>temp;
//         int i = 0;
//         for(; i<n-1; i++){
//             temp.push_back(nums[i]);
//         }
// // now the last element must be stored in the 0th index.
//         nums[0] = nums[i];


// // again storing the stored value in the temp to the nums vector.
//         for(int j = 1; j<n; j++){
//             nums[j] = temp[j-1];
//         }
//         k--;
//     }

// *************  optimal approach  *************
    k=k%n;// this is to make the k lesser then the n.
    // reverse(1,5) it means ke reverse krna hai 1 to 4 tk only. excluding 5;
    reverse(nums.begin(),nums.begin()+(n-k));
    reverse(nums.begin()+(n-k),nums.end());
    reverse(nums.begin(),nums.end());

}

int main()
{   vector<int>nums;
    // nums = {1,2,3,4,5,6,7};
    nums = {1,2,3};
    int k ;
    cout<<"the place from the right where you want rotate ?"<<endl;
    cin>>k;
    rotate(nums,k);
    for(int i = 0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    return 0;
}