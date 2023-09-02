/*
Question -> calculate a^b. 
            We can solve this in two ways -> 1. Normally iterating the loop till b. Time complexity = O(b);
                                             2. using fast expression method. time complexity = O(log b);
                                             Ex - 2^3 = (2^2 * 2);
                                                (2^4) = (2^2)^2 = ((2)^2)^2;
*/
#include<iostream>
using namespace std;

long long find_power(long long base,long long power){

    long long ans = 1;

    while(power > 0){
        if(power & 1){
            ans = (ans * base);
        }
        base *= base;
        power = power >> 1;
    }

    return ans;
}

int main()
{
    int base,power;
    cout<<"enter the base-> ";
    cin>>base;
    cout<<"enter the power-> ";
    cin>>power;

    long long ans = find_power(base,power);
    cout<<"ans -> "<<ans<<endl;

    return 0;
}
/*
But in this question, we will overflow the integer limit,if we get the value of base and power so huge.
To avoid these cases, we use modulo arithmetic. Bring the result in the range.
To implement that we do nothing but 
here m is the modulo number i.e. 10^9 + 7;
ans = (ans % m * base % m) % m;
x = (x % m * x % m)%m;
We get the ans in the modulo form. 
to get exact ans -> find the ((modulo ans)^power)/m;
*/
