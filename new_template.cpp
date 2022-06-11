#include <bits/stdc++.h>
using namespace std;
 
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
 
#define ill int long long
#define ld long double

#define fi first 
#define se second 
#define pb push_back 
// #define fo(i,k,n) for(ill i=k;i<n;i++)
// #define fr(i,n,k) for(ill i=n;i>=k;i--)
 
#define f0(i,a,b) for(int i=a;i<b;i++)
#define f1(i,a,b) for(int i=a;i<=b;i++)
#define f2(i,a,b) for(int i=a;i>b;i--)
#define f3(i,a,b) for(int i=a;i>=b;i--)
 
#define all(a) a.begin(),a.end()
#define pii pair<ill,ill>
#define intmax 2147483647
#define intmin -2147483648
#define pi 3.141592653589
#define mod 1000000007
#define mdl 998244353
#define endl '\n'


// dearrangements 
// 1 -> 0 
// 2 -> 1 
// 3 -> 2 
// 4 -> 9 
// 5 -> 44 


// modulus 
// Positive number    use   x%m 
// Negative number    use   ( x%m + m ) % m 

// Properties of Modulus:

// 1. (a+b)%m =  ((a%m)+(b%m))%m
// 2. (a-b)%m = ((a%m)-(b%m)+m)%m
// 3. (a*b)%m = ((a%m)*(b%m))%m
// 4. (a/b)%m = ((a%m)*(b^-1%m))%m

// (a-b)%k = (x-y)  Then (a-x)%k = (b-y)%k


ill gcd(ill a, ill b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);     
}


ill lcm(ill a,ill b) {
    return ((a/gcd(a,b))*b); // to avoid overflow 
}


int gcd_cp_algo_1 (int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

int gcd_cp_algo_2 (int a, int b) {
    return b ? gcd (b, a % b) : a;
}

int gcd_cp_algo_3_non_rec (int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int lcm_cp_algo (int a, int b) {
    return a / gcd(a, b) * b;
}


// builten functions 
void solve_gcd(){

    ill a,b;
    cin>>a>>b;
    ill gcd = __gcd(a,b);
    ill lcm = (a/gcd)*b;

    ill c;
    cin>>c;
    ill x = __gcd(a,__gcd(b,c)); // 3 or more number gcd in this fashion 

}





const int N=10001;
ill fac[N];

void pre_fac(ill num){ // fac till num pre calculate 
    fac[0]=1;
    fac[1]=1;

    f1(i,1,num){
        fac[i]=i*fac[i-1];
    }
}

ill fac_mod[N];

void pre_fac_mod(ill num){ // fac till num pre calculate 
    fac_mod[0]=1;
    // fac_mod[1]=1;

    f1(i,1,num){
        fac_mod[i]=((i%mod)*(fac_mod[i-1]%mod))%mod;
    }

}



 
void SieveOfEratosthenes(ill n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (ill p = 2; p * p <= n; p++)
    {
        
        if (prime[p] == true)
        {
            for (ill i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    for (ill p = 2; p <= n; p++) {
        if (prime[p]) {
            cout << p << " ";
        }
    }


}
 




// modulus 
// x positive x%m
// x negative ( (x%m) + m ) % m


// binary exponentiation 
// x^n in log n 
int binaryExponentiation(int x,int n,int m) // x^n   O(logn)
{
	if(n==0){
		return 1;
	}
	if(n%2==0){
		return binaryExponentiation(((x%m)*(x%m))%m,n/2,m);
	}
	return ((x%m)*binaryExponentiation(((x%m)*(x%m))%m,(n-1)/2,m)%m)%m;
}


// binary expontiation recursive without mod 
ill be_rec(ill x,ill n) 
{
	if(n==0){
		return 1;
	}
	if(n%2==0){
		return be_rec((x*x),n/2);
	}
	return x*be_rec(x*x,(n-1)/2);
}


// binary expontiation recursive without mod 
ill be_rec_mod(ill x,ill n,ill m) 
{
	if(n==0){
		return 1;
	}
	if(n%2==0){
        ill new_x=((x%m)*(x%m))%m;
		ill res=(be_rec(new_x,n/2))%m;
        return res;
	}
    else {
        ill new_x=((x%m)*(x%m))%m;
        ill res=((x%m)*(be_rec(new_x,(n-1)/2) %m))%m;
        return res;
    }	
}


int binaryExponentiation_iterative_mod(int x,int n,int m)   // O(logn)
{
	int res=1;
	while(n!=0){
		if(n%2==1){
			res = ((res%m)*(x%m))%m;
		}
		x = ((x%m)*(x%m))%m;
		n/=2;
	}
	return res;
}


int binaryExponentiation_iterative(int x,int n)   // O(logn)
{
	int res=1;
	while(n!=0){
		if(n%2==1){
			res = res*x;
		}
		x = x*x;
		n/=2;
	}
	return res;
}


/* Iterative Function to calculate (x^y) in O(log y) */
int power_gfg(int x, int y)
{
	
	// Initialize answer
	int res = 1;
	
	// Check till the number becomes zero
	while (y)
	{
		
		// If y is odd, multiply x with result
		if (y % 2 == 1)
			res = (res * x);
			
		// y = y/2
		y = y >> 1;
		
		// Change x to x^2
		x = (x * x);
	}
	return res;
}



/* Iterative Function to calculate (x^y)%p in O(log y) */
int power_gfg_mod(long long x, unsigned int y, int p)
{
    int res = 1;     // Initialize result
 
    x = x % p; // Update x if it is more than or
                // equal to p
  
    if (x == 0) return 0; // In case x is divisible by p;
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}


ill binpow_rec(ill a, ill b) {
    if (b == 0)
        return 1;
    ill res = binpow_rec(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}


ill binpow_ite(ill a, ill b) {
    ill res = 1;
    while (b > 0) {
        if (b & 1 )
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}


// long long binpow(long long a, long long b, long long m) {
//     a %= m;
//     long long res = 1;
//     while (b > 0) {
//         if (b & 1)
//             res = res * a % m;
//         a = a * a % m;
//         b >>= 1;
//     }
//     return res;
// }

ill binpow_itr_mod(ill a, ill b, ill m) {
    a %= m;
    ill res = 1;
    while (b > 0) {
        if (b & 1){
            res = ((res%m) * (a%m)) % m;
        }
        a = ((a%m) * (a%m)) % m;
        b >>= 1;
    }
    return res;
}

ill binpow_rec_mod(ill a, ill b,ill m) {
    if (b == 0)
        return 1;

    ill res = binpow_rec(a, b / 2);
    if (b % 2)
        return (res%m * res%m * a%m)%m;
    else
        return (res%m * res%m)%m;
}


bool is_prime(ill num) {
    f1(i,2,sqrtl(num)) {
    // for (ill i=2; i*i<=num ; i++) {   
        if (num%i==0) {
            return true;
        }
    }
    return false;
}


vector <ill> divisor(ill num){
    vector <ill > div;
    f1(i,1,sqrtl(num)){
        // 1 and num sended 
        if (num%i==0) {
            if  ( (i*i)!=num ) {
                div.pb(i);
                div.pb((num/i));
            }
            else {
                div.pb(i);
            }
        }
    }
    return div;

    // vector <ill > div1;
    // div1.pb(1);

    // f1(i,2,sqrtl(num)){
    // // for (ill i=2; i*i<=num ; i++) {  
    //     // 1 and num sended 
    //     if (num%i==0) {
    //         if  ( (i*i)!=num ) {
    //             div1.pb(i);
    //             div1.pb((num/i));
    //         }
    //         else {
    //             div1.pb(i);
    //         }
    //     }
    // }

    // div1.pb(num);

    // if (div1.size()==2) {
    //     // it is prime 
    // }
    // else {
    //     // it is composite 
    // }

    // return div1;

}










int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
// 	ill t,ic;
// 	cin>>t;
// // 	for(ic=1;ic<=t;ic++){
//     f1(ic,1,t) {
	    
	    
	    
	    
// 	}

    SieveOfEratosthenes(100);


	return 0;
}