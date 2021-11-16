#include <bits/stdc++.h>
using namespace std;
 
// Random Function to that returns 0 or 1 with
// equal probability
int rand50()
{
    // rand() function will generate odd or even
    // number with equal probability. If rand()
    // generates odd number, the function will
    // return 1 else it will return 0.
    return rand() & 1;
}
 
// Random Function to that returns 1 with 75%
// probability and 0 with 25% probability using
// Bitwise OR
bool rand75()
{
    return rand50() | rand50();
}
 
// Driver code to test above functions
int main()
{
    // Initialize random number generator
    srand(time(NULL));
 
    for(int i = 0; i < 10; i++)
        cout << rand75();
 
    return 0;
}