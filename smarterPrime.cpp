#include <iostream>

using namespace std;

int main(){
    long int boundary = 100000, counter = 0;

    /*
    cout<<"Prime numbers up to: ";
    cin>>boundary;
    cout<<endl;
    */
    boundary+=1;
    bool ar[boundary];

    ///Setting all values in array to true, assuming all numbers are prime numbers
    for(long long int i=2; i<boundary; ++i)
        ar[i] = true;

    ///Starting from two because two is the first prime number
    for(long long int i=2; i<boundary; i++)

        ///For each number that is still prime...
        if(ar[i]){
            ///...start canceling out all multiples of that number all the way to end of array
            ///by setting them to false. Since they are divisible by numbers
            ///other than 1 and themselves, they are not prime

            ///Starting cancellation from the next multiple of i
            int j=i*2;

            while(j<boundary){
                ar[j] = false;
                j+=i;
            }
            ///Counter & Output
            counter++;
            cout<<i<<" ";
        }

    cout<<"\n\nNumber of primes: "<<counter;

    return 0;
}
