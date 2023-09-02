#include<iostream>
using namespace std;

/*
    Question -> https://leetcode.com/problems/merge-sorted-array/ question link
    Merge two sorted array.
*/

void merge_array(int arr1[],int size1,int arr2[],int size2,int arr3[]){
    // concept ->  
    int i = 0; // pointing to the first index of the arr1[]
    int j = 0; // pointing the first index of arr2[]
    int k = 0; // for iterating the third array

    // iterate the loop till (i < size of first array) and (j < size of second array);
    while(i < size1 && j <size2){
        if(arr1[i] <= arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }

// now if the first array remains some elements, then printing that elements: b/c arr1 ka size bada hai arr2 ke size se,
// thus when i and j increment hoga then j pahle khatam hoo jayega, then baccha hua elements in arr1 ko store krwane ke liye arr3 me next loop lenge

    // i jaha tak chal chuka hai uske baad se
    while(i < size1){
        arr3[k++] = arr1[i++];
    }

    // if arr2 ka size jada rahta then wo bach jada then printing those baccha hua elements
    while(j < size2){
        arr3[k++] = arr2[j++];
    }

}

int main()
{
    int arr1[] = {1,2,12,14,16,20}; 
    int arr2[] = {2,3,4};// sorted array
    int size1 = 6;
    int size2 = 3;

    int size3 = size1 + size2;

    int arr3[size3] = {0};
    merge_array(arr1,size1,arr2,size2,arr3);

    for(int i = 0; i<size3; i++){
        cout<<arr3[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}