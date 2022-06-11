#include <bits/stdc++.h>    
using namespace std;

// function to generate random numbers in range [0-999] :
long long randomize() 
{   
    return (rand() % 1073741825); 
    // return 105;
}
  
int main () 
{
    #ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    freopen("input6.txt", "w", stdout);
#endif
  // for different values each time we run the code 
  srand(time(NULL)); 
    // long long n = (rand()*1000000)%100005;
    long long n = 10005;
    // int k = rand()%(n+1);
    long long k= 500;

    // long long x = rand()%(1073741825);
    long long x=105;

  vector<long long> vect(n); // declaring the vector
  
  // Fill 6 elements from beginning using randomize()
  generate(vect.begin(), vect.end(), randomize);
  
  // displaying the content of vector
  cout<<n<<" "<<k<<" "<<x<<"\n";
  for (int i=0; i<vect.size(); i++)
    cout << vect[i] << " ";
  return 0;
}