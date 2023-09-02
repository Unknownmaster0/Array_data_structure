/*
Question -> Given an integer n, return the number of prime numbers that are strictly less than n.
solution -> Here, we using the concept of Sieve of Eratosthenes. 
            In which we first declare all numbers as prime and then check whether they are prime or not if they are prime then their multiple are not prime.
            Hence, there multiple are mark as non - prime. And hence we get the set of prime numbers.
            Time complexity -> O(n * log(log n));
            where n is the number written.
*/
#include<iostream>
#include<vector>
using namespace std;

int find_total_prime(int n){
    
    int count = 0;
    // as initially consideration -> all the numbers are prime, thus, from 0 to n we store every number as 1 which means that they are prime.
    vector<int> prime (n+1,1);
// as the 0 and 1 is not prime. Thus, storing 0 in both places.
    prime[0] = 0;
    prime[1] = 0;

    for(int i = 2; i<n; i++){
        if(prime[i]){
            count++;
        }
        for(int j = 2 * i; j<n; j = j + i){
            prime[j] = 0;
        }
    }

    return count;
}

int main()
{
    int n;
    cout<<"enter the number ->  ";
    cin>>n;

// finding the total prime number just before to n;
   int total_prime = find_total_prime(n);
   cout<<"the total prime numbers are -> "<<total_prime<<endl;

    return 0;
}