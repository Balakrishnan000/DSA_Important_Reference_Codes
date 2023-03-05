#include <iostream>
#include <vector>
using namespace std;

//To GENERATE Primes upto n 
vector<int> MySeive(int n)
{
    vector<bool> prime(n+1, true);
 
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    // store all prime numbers
    vector<int> res;
    for (int p = 2; p <= n; p++)
        if (prime[p])
            res.push_back(p);
    
    return res;
}
 
// Driver Code
int main()
{
    vector<int> res = MySeive(1000);
    //we get prime upto 1000
    for(int r : res)
        cout<<r<<" ";
    cout<<"\n";

    return 0;
}