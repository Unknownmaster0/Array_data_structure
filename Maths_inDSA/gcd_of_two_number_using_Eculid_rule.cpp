#include <iostream>
#include <vector>
using namespace std;

// // this is also type of ECULID principal.
// int gcd(int a,int b){
    
//     if(a == 0){
//         return b;
//     }
//     else if(b == 0){
//         return a;
//     }
    
//     int maxi = max(a,b);
//     int mini = min(a,b);
    
//     // substaracting the minimum number from the maximum number, till the maximum will become 0. Thus, the minimum will become the gcd of that two numbers.
//     while( maxi > 0 ){
//         maxi -= mini;
//     }
    
//     return mini;
// }

// perfect ECULID method : Time complexity = O(log(min(a,b)));
int gcd(int a, int b){
    if(a == 0){
        return b;
    }
    else if(b == 0){
        return a;
    }

    int maxi = max(a,b);
    int mini = min(a,b);

    while(mini > 0){
        int temp = maxi % mini;
        maxi = mini;
        mini = temp;
    }

    return maxi;
}

int main()
{
    int a,b;
    cout<<"enter two numbers: "<<endl;
    cin>>a>>b;
    
    int hcf = gcd(a,b);
    cout<<"the gcd of "<<a<<" and "<<b<<" is "<<hcf<<endl;
    return 0;
}