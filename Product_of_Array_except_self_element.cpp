#include<iostream>
using namespace std;

/*
    Question -> You have given an array of size n.You have to return an array PRODUCT such that PRODUCT[i] = product of all elements except the arr[i];
    arr[] = {1,2,3,4,5};
    PRODUCT[2] = 40; except arr[2] = 3;
*/
// Problem not the right code.

int* find_product(int arr[],int n){
    int PRODUCT[n];
    for(int i = 0; i<n; i++){
        int product = 1;
        for (int i = 0; i < n; i++)
        {
            product *= arr[i];
        }
        PRODUCT[i] = product;
        
    }

    return PRODUCT;
}

void printArray(int brr[],int n){
    for(int i = 0; i<n; i++){
        cout<<brr[i]<<" ";
    }
    cout<<endl;
    return;
}

int main()
{
    int arr[] = {1,2,3};
    int arr_size = 3;
    int* PRODUCT = find_product(arr,arr_size);
    printArray(PRODUCT,arr_size);
    return 0;
}