#include <bits/stdc++.h>
using namespace std;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#define ill int long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define MP make_pair

// #define fo(i,k,n) for(ill i=k;i<n;i++)
// #define fr(i,n,k) for(ill i=n;i>=k;i--)

#define f0(i, a, b) for (int i = a; i < b; i++)
#define f1(i, a, b) for (int i = a; i <= b; i++)
#define f2(i, a, b) for (int i = a; i > b; i--)
#define f3(i, a, b) for (int i = a; i >= b; i--)

#define all(a) a.begin(), a.end()
#define pii pair<ill, ill>

#define vi vector<ill>
#define mii map<ill, ill>

#define intmax 2147483647
#define intmin -2147483648
#define pi 3.141592653589
#define mod 1000000007
// 998244353
// #define mod 998244353
#define endl '\n'

// dearrangements
// 1 -> 0
// 2 -> 1
// 3 -> 2
// 4 -> 9
// 5 -> 44

ill gcd(ill a, ill b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ill binpow(ill a, ill b, ill m)
{
    if (b == 0)
        return 1;

    ill res = binpow(a, b / 2, m);
    if (b % 2)
        return (res % m * res % m * a % m) % m;
    else
        return (res % m * res % m) % m;
}

ill lcm(ill a, ill b)
{
    return ((a / gcd(a, b)) * b); // to avoid overflow
}

ill binExp(ill x, ill n, ill m)
{
    ill res = 1;
    while (n)
    {
        if (n & 1)
            res = (res * x) % m;
        x = (x * x) % m;
        n >>= 1;
    }
    return res;
}

ill modInv(ill i, ill m) { return binExp(i, m - 2, m); }

// ill fact[300000];
// ill ncr(ill n,ill r) {return (n>=r?(fact[n]*modInv(fact[r],mod))%mod*modInv(fact[n-r],mod)%mod:0);}

// void initialise_fact(){
//     fact[0]=1;
//     fact[1]=1;
//     f0(i,2,300000) {
//         fact[i]=((fact[i-1]%mod)*(i%mod))%mod;
//     }
// }

/*

1. cin replacement / little fast 
int a, b;
scanf("%d %d", &a, &b);

2. cout replacement / little fast
int a = 123, b = 456;
printf("%d %d\n", a, b);
printf("%.9f\n", x);

3. take input of string with spaces 
string s;
getline(cin, s);

4. /n bit faster 
check working 

5. unknown number of inputs 
while (cin >> x) {
// code
}

6. file input and output 
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);



NOTE of numbers 
1.
long long x = 123456789123456789LL;

2. 
int a = 123456789;
long long b = a*a;
cout << b << "\n"; // -1757895751
// Even though the variable bis of type long long, both numbers in the expression a*a are of type int, and the result is also of type int. Because of this, the variable b will have a wrong result. The problem can be solved by changing the type of a to long long or by changing the expression to (long long)a*a

3.  for decimals 
if (abs(a-b) < 1e-9) {
// a and b are equal
}


*/

// 1. subset generation using recursion
vector<int> subset;
const int n = 10; // size of the array // also can be sent as the argument in the functions
void search(int k)
{
    if (k == n + 1)
    {
        // process subset
    }
    else
    {
        // include k in the subset
        subset.push_back(k);
        search(k + 1);
        subset.pop_back();
        // don’t include k in the subset
        search(k + 1);
    }
}

// 2. permutations
bool chosen[n];
vector<int> permutation;
void search()
{
    if (permutation.size() == n)
    {
        // process permutation
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (chosen[i])
                continue;
            chosen[i] = true;
            permutation.push_back(i);
            search();
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}

void permuatation_stl()
{

    for (int i = 1; i <= n; i++)
    {
        permutation.push_back(i);
    }

    do
    {
        // process permutation
    } while (next_permutation(permutation.begin(), permutation.end()));
}

/*

N quuen optimised  - page 31 
check again 

void search(int y)
{
    if (y == n)
    {
        count++;
        return;
    }
    for (int x = 0; x < n; x++)
    {
        if (col[x] || diag1[x + y] || diag2[x - y + n - 1])
            continue;
        col[x] = diag1[x + y] = diag2[x - y + n - 1] = 1;
        search(y + 1);
        col[x] = diag1[x + y] = diag2[x - y + n - 1] = 0;
    }
}


*/

/*

imp note 

In an unsigned representation, only nonnegative numbers can be used, but the
upper bound for the values is larger. An unsigned variable of n bits can contain any
integer between 0 and 2n − 1. For example, in C++, an unsigned int variable
can contain any integer between 0 and 232 − 1.
There is a connection between the representations: a signed number −x equals
an unsigned number 2n − x. For example, the following code shows that the signed
number x = −43 equals the unsigned number y = 232 − 43:

int x = -43;
unsigned int y = x;
cout << x << "\n"; // -43
cout << y << "\n"; // 4294967253


int x = 2147483647
cout << x << "\n"; // 2147483647
x++;
cout << x << "\n"; // -2147483648


AND opertation  : 
Using the and operation, we can check if a number x is even because x & 1 = 0
if x is even, and x & 1 = 1 if x is odd. 
More generally, x is divisible by 2^k exactly
when x & (2^k − 1) = 0


check this 
NOT opertation
Not Operation The not operation ~x produces a number where all the bits of x have
been inverted. The formula ~x = −x −1 holds, for example, ~29 = −30. The result
of the not operation at the bit level depends on the length of the bit representation,

because the operation inverts all bits. For example, if the numbers are 32-bit int
numbers, the result is as follows:
x = 29 00000000000000000000000000011101 ~x = −30 11111111111111111111111111100010

*/

void bit_at_index()
{

    int x = 1000;

    for (int k = 31; k >= 0; k--)
    {
        if (x & (1 << k))
            cout << "1";
        else
            cout << "0";
    }
}

/*
BIT notes 

1. set the kth bit -->  x | (1 << k) 
2. unset the kth bit -->  x & ~(1 << k) 
3. flip/invert the kth bit -->   x ^ (1 << k) 

4. the formula   x & (x − 1)   sets the last one bit of x to zero ( unsets the LSB(least significant bit) )
x   =  000011001
x-1 =  000011000 (last 1 to 0 if at 0 index you have 1)
&   =  000011000 (LSB = 0 from 1)

x   =  00101011000 --> 0010101 + (1000 is 2 power sth so -1 from here == 0111   ) so -1 from all is 0010101 + 0111
x-1 =  00101010111  (LSB change to 0 from 1 and all the previous 0's change to 1)

x & x-1 = 00101010000 (LSB = 0 from 1)
// before doing so check that number should not be 0



5. the formula   x & −x    sets all the one bits to zero, except for the last one bit
(unset all except the LSB )
-x = ~x+1
so   (x & (~x+1)) = all zeros except the last bit set in original
eg1  
x   =   000000101101

~x    =  111111010010
~x+1  =  111111010011

-x  = ~x + 1 = 111111010011

x & -x = 
000000101101
111111010011

000000000001

eg2:
x     =  000000101100
~x    =  111111010011
~x+1  =  111111010100

-x  = ~x + 1 = 111111010100

x & -x = 
000000101100
111111010100

000000000100




6. The formula   x | (x − 1)   inverts all the bits after the last one bit
x   =  000011001
x-1 =  000011000
|   =  000011001

x   =  00101011000
x-1 =  00101010111
|   =  00101011111



7. a positive number x is a power of two exactly when         x & (x − 1) = 0  


NOTE :
when using bit masks is that 1<<k is always an int bit mask. An easy way to create a long long bit mask is 1LL<<k.
use 1LL with long long 


Additional Functions The g++ compiler also provides the following functions for counting bits:
• __builtin_clz(x): the number of zeros at the beginning of the bit representation
• __builtin_ctz(x): the number of zeros at the end of the bit representation
• __builtin_popcount(x): the number of ones in the bit representation
• __builtin_parity(x): the parity (even or odd) of the number of ones in the bit representation

*/

void bit_functions()
{

    int x = 5328;                          // 00000000000000000001010011010000
    cout << __builtin_clz(x) << "\n";      // 19
    cout << __builtin_ctz(x) << "\n";      // 4
    cout << __builtin_popcount(x) << "\n"; // 5
    cout << __builtin_parity(x) << "\n";   // 1
    // Note that the above functions only support int numbers, but there are also long long versions of the functions available with the suffix ll.
}

void representing_sets()
{

    /*

Every subset of a set {0, 1, 2,..., n − 1} can be represented as an n bit integer whose one bits indicate which elements belong to the subset. This is an efficient way to represent sets, because every element requires only one bit of memory, and set operations can be implemented as bit operations.

*/

    //  set {1, 3, 4, 8}
    int x = 0;
    x |= (1 << 1);
    x |= (1 << 3);
    x |= (1 << 4);
    x |= (1 << 8);
    cout << __builtin_popcount(x) << "\n"; // 4

    for (int i = 0; i < 32; i++)
    {
        if (x & (1 << i))
            cout << i << " ";
    }
    // output:1348

    // processing a subset
    for (int b = 0; b < (1 << n); b++)
    {
        // process subset b
    }

    // set operations

    // Operation         Set syntax       Bit syntax

    // Intersection       a ∩ b             a & b
    // Union              a ∪ b             a | b
    // Complement           a¯                ~a
    // Difference          a \ b            a & (~b)

    // example
    // sets x = {1, 3, 4, 8} and y = {3, 6, 8, 9} and then constructs the set z = x ∪ y = {1, 3, 4, 6, 8, 9}

    x = (1 << 1) | (1 << 3) | (1 << 4) | (1 << 8);
    int y = (1 << 3) | (1 << 6) | (1 << 8) | (1 << 9);
    int z = x | y;                         // taking OR for union
    cout << __builtin_popcount(z) << "\n"; // 6

    // The following code goes through the subsets of{0, 1, .. , n − 1} :
    for (int b = 0; b < (1 << n); b++)
    {
        // process subset b
    }

    // Then, the following code goes through the subsets with exactly k elements :
    int k = 5;
    for (int b = 0; b < (1 << n); b++)
    {
        if (__builtin_popcount(b) == k)
        {
            // process subset b
        }
    }

    // check :
    // Finally, the following code goes through the subsets of a set x :
    int b = 0;
    do
    {
        // process subset b
        // } while (b = (b - x) & x);
    } while (x & b == b);
}

// note :: always include brackets with bits
// if (myset&i==i) { // do not work
//  if ( (myset&i) ==i) { // works
void all_subset_of_a_set()
{
    int myset = 0;
    // 0 0 0 0 1 0 1 1 0 0
    //    . .  5 4 3 2 1 0
    myset = myset | (1 << 2);
    myset = myset | (1 << 3);
    myset = myset | (1 << 5);

    f0(i, 0, 100)
    {
        // if (myset&i==i) { // do not work
        if ((myset & i) == i)
        { // works
            cout << i << " --> ";

            f0(j, 0, 10)
            {
                if (i & (1 << j))
                {
                    cout << 1 << " ";
                }
                else
                {
                    cout << 0 << " ";
                }
            }
            cout << endl;
        }
    }

    /*
    
0 --> 0 0 0 0 0 0 0 0 0 0 
4 --> 0 0 1 0 0 0 0 0 0 0 
8 --> 0 0 0 1 0 0 0 0 0 0 
12 --> 0 0 1 1 0 0 0 0 0 0 
32 --> 0 0 0 0 0 1 0 0 0 0 
36 --> 0 0 1 0 0 1 0 0 0 0 
40 --> 0 0 0 1 0 1 0 0 0 0 
44 --> 0 0 1 1 0 1 0 0 0 0 


    */
}

/*

C++ Bitsets The C++ standard library also provides the bitset structure, which corresponds to an array whose each value is either 0 or 1. For example, the following code creates a bitset of 10 elements : 2.3 Bit Manipulation 25 bitset<10> s;
s[1] = 1;
s[3] = 1;
s[4] = 1;
s[7] = 1;
cout << s[4] << "\n";                                                                        // 1
cout << s[5] << "\n";                                                                        // 0
The function count returns the number of one bits in the bitset : cout << s.count() << "\n"; // 4
Also bit operations can be directly used to manipulate bitsets : bitset<10> a, b;
// ...
bitset<10> c = a & b;
bitset<10> d = a | b;
bitset<10> e = a ^ b;

*/

/*

// kadane 

int best = 0, sum = 0;
for (int k = 0; k < n; k++)
{
    sum = max(array[k], sum + array[k]);
    best = max(best, sum);
}
cout << best << "\n";


*/


int main()
{
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // initialise_fact();

    ill t, ic;
    cin >> t;
    // 	for(ic=1;ic<=t;ic++){
    f1(ic, 1, t)
    {
        // all_subset_of_a_set();
    }
    return 0;
}