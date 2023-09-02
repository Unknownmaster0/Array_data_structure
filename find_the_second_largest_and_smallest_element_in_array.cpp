/*
Question -> https://www.codingninjas.com/studio/problems/ninja-and-the-second-order-elements_6581960

    Algorithm -> there are 3 algorithms for this program
                1. Brutforce -> sorting technique and traverse the array ( O(N*logN) + O(N) ) with this time complexity
                2. Better solution -> find the largest and appoint the second largest traversing the whole array again. time complexity ( O( 2*N )  )
                3. Optimal solution -> in single loop or single traverse we will find the largest element and second largest element. time complexity ( O(N))
*/

#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;


int largest(int n,vector<int>a){
    int maxi = a[0];
    for(int i = 0; i<n; i++){
        maxi = max(maxi,a[i]);
    }
    return maxi;
}

int minimum(int n,vector<int>a){
    int mini = a[0];
    for(int i = 0; i<n; i++){
        mini = min(mini,a[i]);
    }
    return mini;
}

void getSecondOrderElements(int n, vector<int> a,vector<int>ans) {



// /***************  Method 1  ****************/ optimal solution
    int large = a[0];
    int slrgst = INT_MIN;
    
    for(int i = 1; i<n; i++){
       if(a[i] > large){
        slrgst = large;
        large = a[i];
       }
       else if(a[i] > slrgst){
        slrgst = a[i];
       }
    }
    ans.push_back(slrgst);

    int smallest = a[0];
    int ssmlst = INT_MAX;

    for(int i = 1; i<n; i++){
        if(a[i] < smallest){
            ssmlst = smallest;
            smallest = a[i];
        }
        else if(a[i] < ssmlst){
            ssmlst = a[i];
        }
    }
    ans.push_back(ssmlst);



    int large = largest(n,a);
    int small = minimum(n,a);
// // /***************  Method 1  ****************/ better solution
// // solving without the help of the sorting technique.
//     int second_largest = INT_MIN;
//     int i = 0; 
//     while(i < n){
//         if(a[i] > second_largest && a[i] < large){
//             second_largest = a[i];
//         }
//         i++;
//     }
//     ans.push_back(second_largest);

//     int second_smallest = INT_MAX;
//     i = 0;
//     while(i<n){
//         if(a[i] < second_smallest && a[i] > small){
//             second_smallest = a[i];
//         }
//         i++;
//     }
//     ans.push_back(second_smallest);


// /***************  Method 2  ****************/  brutforce solution
// // solving with the help of sorting technique.
//     sort(a.begin(),a.end());

// // for finding the second laargest element in the vector.
//     for(int end = a.size()-2; end >= 0; end--){
//         if(a[n-1] != a[end]){
//             ans.push_back(a[end]);
//             break;
//         }
//     }
// // for finding the second smallest element in the vector.
//     for(int start = 1; start < n; start++){
//         if(a[0] != a[start]){
//             ans.push_back(a[start]);
//             break;
//         }
//     }




// this is for printing the stored value in the ans;
    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

}


int main()
{
    vector<int>arr;
    // arr = {65,72,13,89,32};
    // arr = {1,9,8,3,6};
    arr = {10,5,6,9,2,7};
    vector<int>ans;
    getSecondOrderElements(5,arr,ans);//where 5 is the size of the arr.


    return 0;
}