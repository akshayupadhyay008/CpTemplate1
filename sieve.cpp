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



ill gcd (ill a, ill b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ill lcm (ill a, ill b) {
    return a / gcd(a, b) * b;
}


const int maxi=1e6;
vector<ill> fac(maxi+1);


void pre_fac(){ // fac till num pre calculate 
    fac[0]=1;
    // fac[1]=1;

    f1(i,1,maxi){
        fac[i]=((i%mod)*(fac[i-1]%mod))%mod;
    }
}
// fac[0]=1;
// for(int i=1;i<=max;i++) fac[i]=fac[i-1]*i%m;

ill binpow_rec_mod(ill a, ill b,ill m) {
    if (b == 0)
        return 1;

    ill res = binpow_rec_mod(a, b / 2,m);
    if (b % 2)
        return (res%m * res%m * a%m)%m;
    else
        return (res%m * res%m)%m;
}



bool isPrime[1000001];
// true for yes it is prime --> 1 
// false for no it is not a prime --> 0

// isPrime[i] tells about i ( 1 based indexing )

void seive(){

    // isPrime[i] = 1 if i is prime
    // isPrime[i] = 0 if i is not prime

    // numbers= 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 ... 
    // isPrime= 0 0 1 1 0 1 0 1 0 0 0  1  0  1  0  ...

    for(int i=0;i<=1000000;i++){
        isPrime[i]=1; // initialising with all are prime at the beginning
    }

    isPrime[0]=0; // 0 is not prime
    isPrime[1]=0; // 1 is not prime 


    // #1
    // move from 2 to N ( 0 and 1 already handled )
    // we use the fact that multiple of a number is a composite (other than multiple of 1 )
    // like 2 ka multiple 
    // like 3 ka multiple 
    // like 4 ka multiple 
    // 5 , 6 , 7 , 8 , 9 , 10 ... 
    // so for every number i from 2 to N we mark its multiple as composite 0 
    // multiple means --> not this number (not i )
    // from 2*i moving by i till number becomes greater than N
    // 2*i   3*i   4*i ....
    // for 2 -->  6 8 10 12 ...
    // for 3 -->  6 9 12 15 ...
    // for 4 -->  8 12 16 20 ...
    // and so on 
    for(int i=2;i<=1000000;i++){

            for(int j=2*i;j<=1000000;j=j+i) {
                isPrime[j]=0;
            }
        
    }
    // time complexity 
    // n/2 + n/3 + n/4 + n/5 ... <= nlogn 
    // why n/2 --> for number 2 there are n/2 multiples of this number 
    // why n/3 --> for number 3 there are n/3 multiples of this number 
    // why n/4 --> for number 4 there are n/4 multiples of this number 
    // why n/5 --> for number 5 there are n/5 multiples of this number 

    // so appoximately complexity is --> O(N*logN)
    

    
    // #2

    // observation --> the numbers we are marking by 4 are already being marked by 2 
    // the number we are marking for 6 are """""" by 3
    // and so on
    // therefore we only have to mark the multiples of prime number (not marked till now )

    // 2 start till N 
    // if not prime --> do nothing 
    // if prime --> mark all its factors as composite 
    // eg 3 --> 3 is already prime so 1 marked already 
    // start from 2*i ie 6 mark it 0 --> composite 
    // then keep incrementing by i 
    // ie for 3 --> 6 9 12 15 ... till you get out of N 
    for(int i=2;i<=1000000;i++){
        
        if(isPrime[i]==1){
            for(int j=2*i;j<=1000000;j=j+i) {
                isPrime[j]=0;
            }
        }

    }
    // complexity 
    // n/2 + n/3 + n/5 + n/7 + ... 
    // summation of n/prime numbers 
    // O(N*log(logN)) 

    // E n/primes --> 1 --> N   --> N/log N 


    // #3 
    // observation --> for a number x we will get the first unmarked multiple at x*x
    // because all the other multiples will be marked by numbers less than x 
    // for 5 --> 5*2 by 2 , 5*3 by 3 , 5*4 by 2 , so start with 5*5 
    for(int i=2;i<=1000000;i++){
        
        if(isPrime[i]==1){
            for(int j=i*i;j<=1000000;j=j+i) {
                isPrime[j]=0;
            }
        }

    }

    // i*i
    // i --> i*i
    // sqrt N 

    // another observation why go to N 
    // when we know the marking will start from i*i 
    // so go till sqrt x because after that you will move out of N when you start marking 


    // #4
    for(int i=2;i*i<=1000000;i++){

        if(isPrime[i]==1){
            for(int j=i*i;j<=1000000;j+=i){
                isPrime[j]=0;
            }
        }

    }
    // final complexity --> O(N*log(log(sqrt(N))))

}

void final_seive(){

    for(int i=0;i<=1000000;i++){
        isPrime[i]=1; 
    }

    isPrime[0]=0; 
    isPrime[1]=0; 

    for(int i=2;i*i<=1000000;i++){

        if(isPrime[i]==1){
            for(int j=i*i;j<=1000000;j+=i){
                isPrime[j]=0;
            }
        }

    }

}


int spf[1000001];

void spf_seive(){

    for(int i=0;i<=1e6;i++){
        spf[i] = i; // inilisation --> if a number is prime then spf=itself
        // just similar to seive when we inilize every number with 1 ie prime 
        // here also we inilise every number with prime 
    }


    for(int i=2;i*i<=1e6;i++){ // 100% similar to seive 
        
        if(spf[i]==i){ // prime 
            for(int j=i*i;j<=1e6;j+=i){ 
                
                if(spf[j]==j){ 
                    // imp point // mark only when it is not marked by any other 
                    // because we want spf
                    spf[j]=i;
                }

            }
        }
    }

    // eg 120 
    // first 2 will mark this 
    // then 3 will come start marking from 9,12,15 .... will come to 120 also 
    // and it you then mark this then it is wrong 
    // ie mark if not marked 

    // eg 12 
    // 2 already marked h 
    // so do not mark it with 3 


    // int n;
    // cin>>n;
    // int a[n];
    // for(int i=0;i<n;i++){
    //     cin>>a[i];
    // }



}



vector <int> primes;

void prime_numbers(){
    for(int i=2;i<=1e6;i++){
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
}


int sum_of_prime_divisors[1000001];

void solve_sum_of_prime_divisors(){

    final_seive(); // seive should be built already 

    // use 2st template of seive 
    // why 
    // 2 so start marking from 4,6,8,10,12
    // do not start from i*i
    // and go from 2 to N do not go till sqrt N
    // because of the same reason 
    // first marking place is i*i but here first marking place is 2*i 
    // so if x is prime and greater than sqrt N so we will miss 2*x and so on 
    // thus the second template --> O(N*log(log N))

    for(int i=0;i<=1e6;i++){
        sum_of_prime_divisors[i]=0;
    }

    for(int i=2;i<=1000000;i++){
        
        // before calling this is prime should be built already 
        if(isPrime[i]==1){ // using the built seive 
            // for(int j=2*i;j<=1000000;j=j+i) { // dont start from 2*i otherwise in prime numebers 0 will be stored 
            for(int j=i;j<=1000000;j=j+i) { // start from i
                // isPrime[j]=0;
                sum_of_prime_divisors[i]+=i;
            }
        }

    }



}




void solve_sum_of_prime_divisors_with_seive(){
    // sum and seive building together 
  
	const int MAX=1000000;
	bool is_prime[MAX+1]; // true initialize 
	int sum[MAX+1]={}; // 0 initialize
	// sum[i]-> sum of its all prime divisors.
	memset(is_prime,true,sizeof(is_prime));

	is_prime[0]=is_prime[1]=false;
	
	for(int i=2;i<=MAX;i++){
		if(is_prime[i]==true){
			for(int j=i;j<=MAX;j+=i){
				
                if(j>i) { // avoiding marking composite for j=i only for this 
                    is_prime[j]=false; 
                    // marking composite 
                }

				sum[j]+=i; // adding sum for j=i as well as all the others 

			}
		}
	} 

	//O(NlogN)
	// i=2(Prime);
	// 2,4,6,8,10.... 
	// Maked all these numbers as Non prime number 
	// and Sum[j]+=i;
	int q;
	cin>>q;
	while(q--){ //O(q)
		int n;
		cin>>n;
		cout<<sum[n]<<endl;
	}
	
	//OverAll timeComplexity = O(N(logN))

}





int divisor_count[1000001];

// 1 not included 
// if you want 1 add 1 to answer and return or initaise the array with 1 
// note that N is included in the divisor 
void solve_count_divisors(){
    // now we want ke 
    // 12 --> 2 count , 3 count , 4 count , 6 count 

    // so using the 1st template of seive #1 --> O(N*log N )

    // 0 se initize

    for (int i=0;i<=1e6;i++){
        divisor_count[i]=0;
    }

    for(int i=2;i<=1000000;i++){

            // for(int j=2*i;j<=1000000;j=j+i) {  // 1 is not included , if you want N to be not included --> then use this
            for(int j=i;j<=1000000;j=j+i) { // start from i ie N in included in divisor count 

                // isPrime[j]=0;
                divisor_count[j]++;

            }
        
    }

}




void prime_factorisation_spf(){
    // build the spf 
    spf_seive(); // call this before using spf 

    int num;
    cin>>num; // prime factorisation of this number 

    // vector <pair <int ,int >>  v; 
    // // .first --> prime    prime1 
    // // .second --> power of that prime   n1 
    // or use map 

    map <int,int > m;


    // takes max logN steps 
    while(num>1) {

        m[spf[num]]++;
        num=num/spf[num];

    }

    for(auto x: m) {
        cout<<x.first<<"  "<<x.second<<endl;
    }

}




void solve_count_divisors_using_prime_fac(){

    // first find the prime factorization in log n using seive 
    // prime_factorisation_spf se map return or copy here 

    // build the spf 
    spf_seive(); // call this before using spf 

    int num;
    cin>>num; // prime factorisation of this number 

    map <int,int > m;


    while(num>1) {

        m[spf[num]]++;
        num=num/spf[num];

    }

    // for(auto x: m) {
    //     cout<<x.first<<"  "<<x.second<<endl;
    // }

    // now count divisors 
    int ans=1;

    for(auto x: m) {
        ans=ans*(x.second+1);
    }

    cout<<ans<<endl;



}



void solve_count_divisors_using_prime_fac_codeism(){
// 	Bool is_prime[MAX+1];
// 	Int SPF[MAX+1];

// Bool is_prime[MAX+1];
// 	Int SPF[MAX+1];
// // NLog(logN))

    // biult spf 
    spf_seive();


	int q;
	cin>>q;
	while(q--){
		int n;
		cin>>n;
		int ans=1; 

		while(n>1){
			int k=0;
			int spfx = spf[n]; 
            // sir --> continuous division with that spf 
            // my --> 1 by 1 division with that spf 
            // same thing --> no difference 
			while(n%spfx==0){
                n/=spfx;
                k++;
            }
			ans=ans*(k+1); 
		}
		cout<<ans<<endl;

	}

	// Time complxity -> O(qlogn);

	// N = 2^20
	// Spf = SPF[N] = 2;
	// while(N%spf==0) n/=2;
	// It will run 20;
	// Log2(N);

	// N= 2^10 * 3^10


}

// Q --> number of prime divisors in N! 
// N ! --> prime divisors 
// 1 --> N primes 


void get_divisor_from_prime_fac(){

    int num;
    cin>>num; // find all the divisors of this 


    vector <int > divisors; // storing all the divisors of a number

    // divisors.push_back(1); // already into using spf
    // divisors.push_back(num); // already into using spf

    // first find the prime factorization in log n using seive 
    // prime_factorisation_spf se map return or copy here 

    // build the spf 
    spf_seive(); // call this before using spf 

    // map <int,int > m;

    while(num>1) {

        // m[spf[num]]++;
        divisors.push_back(num);
        // divisors.push_back(num/spf[num]);

        num=num/spf[num];

    }

    sort(divisors.begin(),divisors.end());

    for(auto x: divisors){
        cout<<x<< "  ";
    }
    cout<<endl;


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




 
struct primeFactorization {
 
    // to store the prime factor
    // and its highest power
    int countOfPf, primeFactor;
};
 
// Recursive function to generate all the
// divisors from the prime factors
void generateDivisors(int curIndex, int curDivisor,
                      vector<primeFactorization>& arr)
{
 
    // Base case i.e. we do not have more
    // primeFactors to include
    if (curIndex == arr.size()) {
        cout << curDivisor << ' ';
        return;
    }
 
    for (int i = 0; i <= arr[curIndex].countOfPf; ++i) {
        generateDivisors(curIndex + 1, curDivisor, arr);
        curDivisor *= arr[curIndex].primeFactor;
    }
}
 
// Function to find the divisors of n
void findDivisors(int n)
{
 
    // To store the prime factors along
    // with their highest power
    vector<primeFactorization> arr;
 
    // Finding prime factorization of n
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            int count = 0;
            while (n % i == 0) {
                n /= i;
                count += 1;
            }
 
            // For every prime factor we are storing
            // count of it's occurenceand itself.
            arr.push_back({ count, i });
        }
    }
 
    // If n is prime
    if (n > 1) {
        arr.push_back({ 1, n });
    }
 
    int curIndex = 0, curDivisor = 1;
 
    // Generate all the divisors
    generateDivisors(curIndex, curDivisor, arr);
    
}



// Here is an implementation using factorization in O(n−−√):

int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
    
}


// Euler totient function from 1 to n in O(nloglogn)

void phi_1_to_n(int n) {
    vector<int> phi(n + 1);
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}



void etf_codeism(){
    int phi[1000001];

    for(int i=0;i<=1e6;i++){
        phi[i]=i;
    }

    for(int i=2;i<=1e6;i++){
        if(phi[i]==i){
            for(int j=i;j<=1e6;j+=i){
                phi[j] = phi[j]-phi[j]/i;
            }
        }
    }

}



ill ModuloInverse(ill a,ill m){
	//(a^-1)%m;
	//(a^(m-2))%m;
	//using binary exponentiation calculate value of   (a^(m-2))%m and return ans;
	
    // ill ans = (a^(m-2))%m;
    ill ans=(binpow_rec_mod(a,m-2,m)) %m;

	return ans;
}


// nCr = fac[n]/(fac[r]*fac[n-r]);
// 	   fac[n]*(fac[r]^-1)*(fac[n-r]^-1)%m;
// 	   fac[n]*(fac[r]^(m-2))*(fac[n-r]^(m-2))%m;
// m=> prime number
ill ncr(ill n,ill r,ill m){
    ill res=((fac[n]%m)*(ModuloInverse(fac[r],m)%m)*(ModuloInverse(fac[n-r],m)%m))%m;
    return res;
}

// First we precompute all factorials modulo m up to MAXN! in O(MAXN) time.

// const ill MAXN=1e6;
// vector <int> factorial(MAXN+1);

// void factorialsss(){
//     factorial[0] = 1;
//     for (int i = 1; i <= MAXN; i++) {
//         factorial[i] = factorial[i - 1] * i % mod;
//     }
// }
// // And afterwards we can compute the binomial coefficient in O(logm) time.

// long long binomial_coefficient(int n, int k) {
//     return factorial[n] * inverse(factorial[k] * factorial[n - k] % m) % m;
// }
// // We even can compute the binomial coefficient in O(1) time if we precompute the inverses of all factorials in O(MAXNlogm) using the regular method for computing the inverse, or even in O(MAXN) time using the congruence (x!)−1≡((x−1)!)−1⋅x−1 and the method for computing all inverses in O(n).

// long long binomial_coefficient(int n, int k) {
//     return factorial[n] * inverse_factorial[k] % m * inverse_factorial[n - k] % m;
// }


// segmeneted sieve 

const ill N=1000000+5;
bool sieve[N+1];

void createSieve(){

    for(int i=2;i<=N;i++) {
        sieve[i]=true;
    }

    for(int i=2;i*i<=N;i++) {
        if (sieve[i]==true) {
            for (int j=i*i;j<=N;j=j+i) {
                sieve[j] = false;
            }
        }
    }

}


vector <ill> generatePrime(int num) {
    vector <ill> primes;

    f0(i,2,num+1) { 
        if (sieve[i] ==  true ) {
            primes.pb(i);
        }
    }

    return primes;
}


void segmented_sieve(){
    // if max value of R = 1e12
    // sqrt R = 1e6 
    ill mxNum=1e6+5;

    vector <ill> primes = generatePrime(mxNum);

    ill q;
    cin>>q;

    while(q--) {
        ill l,r;
        cin>>l>>r;

        ill dummy[r-l+1];

        f0(i,0,r-l+1) {
            dummy[i]=1;
        }

        // for(auto pr: primes ) {
            // not all but only till sqrt(r)
        // }

        ill mxPrime=sqrtl(r) + 1 ;// + 1 for safety

        for(ill i=2;i<=mxPrime ;i++) { // i is the prime which will be marking the range r-l+1
            // first multiple after l 
            ill firstMultiple=(l/i)*i;

            if (firstMultiple < l) {
                firstMultiple = firstMultiple + i;
            }

            for (ill j=max(i*i,firstMultiple) ; j<=r ; j=j+i) {
                dummy[j-l]=0;
            }

        }

        f0(i,0,r-l+1) {
            if (dummy[i]==1) {
                cout<<l+i<<" ";
            }
        }
        cout<<endl;

    }
}

int main(){
    // seive();
    final_seive();
    spf_seive();

    // number of prime numbers till N is N/log N 
    prime_numbers();
    
    solve_sum_of_prime_divisors();

    // seive building + sum of divisors at the same time 
    solve_sum_of_prime_divisors_with_seive();

    solve_count_divisors();

    
    // prime factorization in log(n)
    // the max number of terms in prime factorisation of any number is log(n)
    // take least prime 2 --> have log n terms 
    // if others are present then obviously less than log n 
    prime_factorisation_spf(); // yes working 

    // divisors count using prime factorization
    solve_count_divisors_using_prime_fac();


    solve_count_divisors_using_prime_fac_codeism();


//    get_divisor_from_prime_fac(); --> not that easy direct conversion not possible 
// 1. multinomial theorem implemenation check 
//    means  (0 1 2 3 4 5 6)(0 1 2 3)(0 1 2 3 4 5 6 7 8 9 10)
//    choice from each box 1 --> and make all such choices and multiply to get the answer
//    --> recursion , backtracking , dp , for loop ????????? check 
// 2. or use the seive template we used for count of divisors 
//    so store the divisors other than storing the count 
//    in the vector of map like --> adjacency list like 
//    memory prrblm can occur --> check ????????
// 3. O(N^(1/3)) method of finding all the divisors 

// 4. in sqrt N --> always possible 


    // in O(sqrt N) 
    ill num=210;
    bool x=is_prime(num);
    vector <ill> div=divisor(num);

    
    // check again 
    // from factorization using recursion 
    
    int n = 6;
 
    findDivisors(n);


    // etf 
    int x=100;
    int res=phi(x);

    int y=1000;
    phi_1_to_n(y); // 1 to 1000 phi genearated


    etf_codeism();


    // modulus inverse 
    // ncr 


    // segmented sieve 
    segmented_sieve();

    return 0;
}


/*

segmented sieve :: 

#include <bits/stdc++.h>
using namespace std;
void simpleSieve(int lmt, vector<int>& prime) {
   bool mark[lmt + 1];
   memset(mark, false, sizeof(mark));
   for (int i = 2; i <= lmt; ++i) {
      if (mark[i] == false) {
         prime.push_back(i);
         for (int j = i; j <= lmt; j += i)
            mark[j] = true;
      }
   }
}
void PrimeInRange(int low, int high) {
   int lmt = floor(sqrt(high)) + 1;
   vector<int> prime;
   simpleSieve(lmt, prime);
   int n = high - low + 1;
   bool mark[n + 1];
   memset(mark, false, sizeof(mark));
   for (int i = 0; i < prime.size(); i++) {
      int lowLim = floor(low / prime[i]) * prime[i];
      if (lowLim < low)
         lowLim += prime[i];
      for (int j = lowLim; j <= high; j += prime[i])
         mark[j - low] = true;
   }
   for (int i = low; i <= high; i++)
      if (!mark[i - low])
         cout << i << " ";
}
int main() {
   int low = 10, high = 50;
   PrimeInRange(low, high);
   return 0;
}
Output
11 13 17 19 23 29 31 37 41 43 47

*/