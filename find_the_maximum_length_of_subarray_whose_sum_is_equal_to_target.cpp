/*
Question = striver sheet question 
            An array of size N need to print the maximum length of the subarray whose sum is equl to k;
            Not the correct code in process solution
            
*/
#include<iostream>
#include<vector>
using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k) {
    int max_size = 0;
    int size = 0;
    long long sum = 0;
    for (int i = 0; i < a.size(); i++) {
      sum += a[i];
      size++;
      if (sum == k){
          max_size = max(max_size,size);
          sum = 0;
          size = 0;
      }
      else if(sum > k){
          if(a[i] == k){
            size = 1;
            max_size = max(max_size,size);
          }
          size = 0; sum = 0;
      }
    }
    max_size = max(max_size,size);
    return max_size;
}               

int main()
{
 
    vector<int>a {0,2,5,3,3,4,4,3,0,5,5,4,4,4,3,2,0,2,3,1,3,0,4,3,1,4,5,2,4,3,1,4,5,0,3,4,0};
    int k;
    cout<<"the sum or target you need to search: ";
    cin>>k;

    longestSubarrayWithSumK(a,k);

    return 0;
}