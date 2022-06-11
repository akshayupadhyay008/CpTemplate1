#include<bits/stdc++.h>
using namespace std;

const int max_states=105; // maximum number of states 

vector <pair <int,char> > adj[max_states]; // adjacency list for storing the directed graph     
// index represents state     
//  .first represents the state it goes to on providing an alphabet that is stored in .second   
// eg    adj[1]={  {3,a} , {5,b}  }
// this means that we are in state 1 and on providing 'a' we go to state 3 and on providing b we go to state 'b'
// ie there is a directed edge from 1 to 3 (on providing 'a') and also an edge from 1 to 5 on providing 'b'

int vis[max_states]; // stores if this state can be visited from starting state or not 
// if it value is 1 then can be visited else not 

int value[max_states][max_states]; // stores whether first state and second state are same or not 
// that is they are distinguishable or not 
// if they are same then they can be merged into 1 else they cannot be merge 
// if value[x][y]=-1 they are different and cannot be merged else can be merged 

map < pair <int,int> , vector < pair <int , int>  > > dp;
// dp table storing the dependency of states 
// if {state1,state2} on input alphabet 'a' goes to {state3,state4}
// then in {state3,state4} is dependent on {state1,state2} so if {state3,state4} are indistinguihable(state3 and state4 are different) then {state1,state2} are also indistinguishable(state1 and state2 are different)
// (because of equivalent set property which state minimisation follows)


// dfs to find the unreachable states from the stating state and remove them
void dfs(int root){
    vis[root]=1;
    for(auto x: adj[root]) {
        if (!vis[x.first]){
            dfs(x.first);
        }
    }
}

// for making the dependent pair of states indistinguishable if current pair of state is indistinguishable
void backtract(int state1,int state2) {
    for (auto x: dp [ {state1,state2} ]) {
        value[x.first][x.second]=-1;
        /* for testing code 
        cout<<" Backtracting in Method  -->  "<< x.first << "  " <<x.second<< endl;
        */
        backtract(x.first,x.second);
    }
    
}



int main(){    
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    // Taking input form user 
    cout<<"Enter the number of states in the DFA - ";
    int num; // number of states 
    cin>>num;

    cout<<"Enter the states in the DFA - "<<endl;
    int state[num];
    for(int i=0;i<num;i++) {
        cout<<"Enter the state "<<i+1<<" - ";
        cin>>state[i];
    }

    cout<<"Enter the number of alphabets in the DFA - ";
    int num_alphabet; // number of alphabets 
    cin>>num_alphabet; 

    cout<<"Enter the alphabets in the DFA - "<<endl;   
    char alphabet[num_alphabet];
    for(int i=0;i<num_alphabet;i++) {
        cout<<"Enter the alphabet "<<i+1<<" - ";
        cin>>alphabet[i];
    }

    cout<<"Enter the starting state of the DFA - ";
    int start; // starting state
    cin>>start;

    cout<<"Enter the number of final states of the DFA - ";
    int num_final; // number of final states 
    cin>>num_final;

    cout<<"Enter the final states of the DFA - ";
    int final_state[num_final]; // final states 
    for(int i=0;i<num_final;i++){
        cout<<"Enter the final state "<<i+1<<" - ";
        cin>>final_state[i];
    }

    cout<<"Enter the transtion table in order (from first state to last state and for each alphabet ) - "<<endl;
    // transition table
    int table[num][num_alphabet];

    for(int i=0;i<num;i++) {
        for(int j=0;j<num_alphabet;j++) {
            cin>>table[i][j];
        }
    }

    
    cout<<"INITIAL DFA : "<<endl<<endl;
    cout<<"Number of states in DFA : " <<num<<endl<<endl;

    cout<<"States of DFA : "<<endl;
    for(int i=0;i<num;i++) {
        cout<<state[i]<<"  ";
    }
    cout<<endl<<endl;
    
    cout<<"Number of Alphabets in DFA : " <<num_alphabet<<endl<<endl;
    
    cout<<"Alphabets of DFA : "<<endl;
    for(int i=0;i<num_alphabet;i++) {
        cout<<alphabet[i]<<"  ";
    }
    cout<<endl<<endl;
    
    
    cout<<"Starting state of DFA : "<<start<<endl<<endl;;
    
    cout<<"Number of final state of DFA : "<<num_final<<endl<<endl;;
    cout<<"Final State of DFA : "<<endl;
    for(int i=0;i<num_final;i++){
        cout<<final_state[i]<<"   ";
    }
    cout<<endl<<endl;
    
    
    cout<<"Transition Table of DFA : "<<endl;
    for(int i=0;i<num;i++){
        for(int j=0;j<num_alphabet;j++) {
            cout<<table[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;


    
    
    // forming the graph and storing the adjacency list 
    for(int i=0;i<num;i++) {
        for(int j=0;j<num_alphabet;j++) {
            adj[state[i]].push_back({table[i][j] , alphabet[j]}); // 1 --> 2,A   3,B // 1 based indexing 
        }
    }

    /* For testing code 
    cout<<"Adjacency list "<<endl;
    for(int i=0;i<num;i++) {
        cout<<state[i]<<" -->    "<<endl;
        for(auto x: adj[state[i]]) {
            cout<<x.first << "  "<<x.second<<endl;
        }
        cout<<endl;
    }
    cout<<endl;
    */

    
    for(int i=0;i<num+5;i++) { 
        vis[i]=0; // initialising the vistited array ( 0 means not visited and 1 means visited ) 
    }

    /* For testing code 
    cout<<"Visited list before  - "<<endl;
    for(int i=0;i<num+5;i++) {
        cout<<vis[i]<<"  ";
    }
    cout<<endl;
    */

    // checking for some unreachable state and removing them because we cannot reach them from starting state
    // calling dfs to find the unreachable nodes 
    dfs(start);

    // now those who are still not visited are unreachable 
    // vis[state[i]]==0 then they are unreachable // so removing them 
    for(int i=0;i<num;i++) {
        if (vis[state[i]] == 0) {
            state[i]=-1; // do not exist
        }
    }
    
    
    /* Testing use (checking the visited array after dfs )
    cout<<"Visited list after - "<<endl;
    for(int i=0;i<num;i++) {
        cout<<vis[i]<<"  ";
    }
    cout<<endl;
    */

    /* Testing (checking which states are unreachable )
    cout<<"States after the dfs call "<<endl; 
    for(int i=0;i<num;i++) {
        cout<<state[i]<<"    ";
    }
    cout<<endl;
    */

    for(int i=0;i<num+2;i++) {
        for(int j=0;j<num+2;j++) {
            value[i][j]=0; // 0 means they are not distinguisable now 
        }
    }

    for(int i=0;i<num-1;i++) {
        for(int j=i+1;j<num;j++) {
            int state1=state[i];
            int state2=state[j];

            if (state[i] == -1 || state[j] == -1)  {
                continue; // non reachable states 
            }

            int is_first_final=0;
            int is_second_final=0;
            for(int k=0;k<num_final;k++) {
                if (final_state[k] == state1) {
                    is_first_final=1;
                }
                if (final_state[k] == state2) {
                    is_second_final=1;
                }                
            }

            // cout<< state1<<"   " <<state2<<"   "<<is_first_final<< "   "<<is_second_final<< endl;

            if (is_first_final==0 && is_second_final==1) {
                value[state1][state2]=-1; // means they are distingusiable now / separate / cannot be merged / base case 
            }
            else if (is_first_final==1 && is_second_final==0) {
                value[state1][state2]=-1;
            }

            // cout<<value[state1][state2]<<"   "<<endl;
            // cout<<"***"<<endl;

        }

    }
    

    for(int i=0;i<num;i++) {
        for(int j=0;j<num;j++) {
            int state1=state[i];
            int state2=state[j];
            cout<<value[state1][state2] << "  ";
        }
        cout<<endl;
    }

    // /*

    int temp=0;

    for(int i=0;i<num-1;i++) {
        for(int j=i+1;j<num;j++) {
            int state1=state[i];
            int state2=state[j];


            if (state[i] == -1 || state[j] == -1)  {
                continue; // non reachable states 
            }



            temp++;
            cout<<temp<<endl;
            cout<<state1<< "   "<<state2 << " " <<value[state1][state2] << endl;
            
            
            if ( value[state1][state2] == -1 ) {
                cout<<"End because of -1 "<<endl;
                cout<<" -- "<<endl;
                continue;
            }
            else {
                
                for (int k=0;k<num_alphabet;k++) {
                    
                        
                    cout<<alphabet[k]<<"  -  ";
                    
                    // state1 goes to ___ on this input 
                    int output1=table[i][k];

                    // state2 output on this input 
                    int output2=table[j][k];

                    if (output1==output2) {
                        cout<<"Same so NO help from them "<<endl;
                        continue;
                    }
                    
                    if (output1==state1 && output2==state2 ) {
                        cout<<"say AB goes to AB so NO help from here "<<endl;
                        continue;
                    }

                    
                    if (output1==state2 && output2==state1 ) {
                        cout<<"say AB goes to AB so NO help from here "<<endl;
                        continue;
                    }

                    if (output1>output2) {
                        swap(output1,output2);
                    }
                    // so combined state is    { output1,output2 } where output1<output2
                    
                    cout<<output1<<"  -  "<<output2 << " -- " <<value[output1][output2] <<endl ;
                    
                    

                    // dp[{state1,state2}].push_back( {output1,output2} );
                    if (value[output1][output2] == -1 ) {
                        value[state1][state2] = -1;
                        
                        cout<<" Value is -1 "<<endl;


                        // if you are marking this as -1 then you also have to backtract and mark others as -1 also whose value is stored there 
                        // as so on they must also be having some values stored and they have to backtract also 

                        for (auto x: dp [ {state1,state2} ]) {
                            value[x.first][x.second]=-1;
                            cout<<"backtracting  -- "<< x.first <<"  " <<x.second<< endl;
                            backtract(x.first,x.second);
                        }

                        // -1 then no need to check other inputs 
                        break; // correct do please 
                    }
                    else {
                        // for backtracting purpose 
                        // if later we got -1 there then we will put -1 here also 
                        // continue;
                        dp[{output1,output2}].push_back({state1,state2});
                        
                        cout<<"Dp filing  -- "<< output1<< "  " << output2<<endl;
                        
                    }


                }

            }
            
            
            cout<<"*****************"<<endl;

        }

    }



    for(int i=0;i<num+1;i++) {
        for(int j=0;j<num+1;j++) {
            cout<< value[i][j]<< "     ";
        }
        cout<<endl;
    }

//     // for(auto x: dp){
//     //     cout<<x.first.first<<"  "<<x.first.second<<endl;
//     //     for(auto y: x.second) {
//     //         cout<<y.first <<"  " << y.second << endl; 
//     //     }
//     //     cout<<"*******"<<endl;
//     // }

//     // cout<<"*************************" <<endl;


    int parent[num];

    for(int i=0;i<num;i++) {
        parent[i]=state[i];
    }

    for(int i=0;i<num;i++) {
        cout<<parent[i]<< "  ";
    }
    cout<<endl;


    for(int i=0;i<num-1;i++) {
        for(int j=i+1;j<num;j++) {
            int state1=state[i];
            int state2=state[j];

            if (state1==-1 || state2==-1)  {
                continue;
            }

            if (value[state1][state2] == -1) {
                continue; // cannot merge them 
            }
            else {
                // parent of state1 
                // parent of state2
                int parent1=parent[i];
                int parent2=parent[j];

                // make parent1 equal to parent2 

                for(int k=0;k<num;k++) {
                    if (parent[k] == parent1) {
                        parent[k]=parent2;
                    }
                }

            }


        }
    }
    

    for(int i=0;i<num;i++) {
        cout<<parent[i]<< "  ";
    }
    cout<<endl;

    
    map <int , vector <int> > new_states;

    for(int i=0;i<num;i++) {
        if (parent[i]!=-1) {
            new_states[parent[i]].push_back(state[i]);
        }
    }

    int new_state_count=new_states.size();

    cout<<"Number of new states - " << new_state_count<<endl;
    
    
    cout<<"New states "<<endl;
    for(auto x: new_states) {
        cout<<x.first<<" -->  "<< endl;
        for(auto y: x.second) {
            cout<<y<<"   ";
        }
        cout<<endl;
    }



    map <int,int> isfinal;  // 1 if final   0 if not final 

    for(auto x: new_states){
        isfinal[x.first]=0;
    }


    // checking if final or not 
    for(auto x: new_states) {
        int check=0;
        for(auto y: x.second) {
            // check if y is final or not 
            for(int i=0;i<num_final;i++) {
                if (final_state[i] == y ) {
                    check=1;
                    break;
                }
            }
        }
        if (check) {
            isfinal[x.first]=1;
        }
    }
    
    for(auto x: isfinal) {
        cout<<x.first << "  "<<x.second<<endl;
    }
    
    cout<<endl;
    
    int new_start;
    for(auto x: new_states) {
        for(auto y: x.second) {
            // check if y is final or not 
            if (y==start) {
                new_start=x.first;
                break;
            }
        }
        // break here also if you want    
    }
    
    cout<<"New start  -->  " << new_start<<endl;
    
    // // finding a transition table 
    map < int , vector < pair < char , int > > > final_adj;
    // char arr_final[num_final][alp];
    

    // for(int i=0;i<num_final;i++) {
    //     for(int j=0;j<alp;j++) {
    //         arr_final[i][j]='?';
    //     }
    // }


    for(auto x: new_states) {
        // char checker=(*(x.second.begin()));
        int checker=x.first;
        cout<<checker<<endl;
        
        int number_in_initial_state=-1;

        for(int i=0;i<num;i++) {
            if (checker==state[i]) {
                number_in_initial_state=i;
                break;
            }
        }


        for(int i=0;i<num_alphabet;i++) {
            // char going_to=[][];
            // int going_to='?';

            // for(auto k: adj[checker]) {
            //     if (k.first==alpha[i])  {
            //     // if (x.second.first==alpha[0])  {
            //         going_to=k.second;
            //     }
            // }
            int going_to=table[number_in_initial_state][i];

            int state_of_going_to;
            for (auto k: new_states) {
                for(auto kk : k.second)  {
                    if (going_to == kk) {
                        state_of_going_to=k.first;
                        break;
                    }
                }
            }
            
            
            final_adj[checker].push_back({alphabet[i],state_of_going_to});

        }

    }
    
    cout<<"Transitions  -- >  "<<endl;
    // for(int i=0;i<num_final;i++) {
    //     for(int j=0;j<alp;j++) {
    //         cout<<arr_final[i][j]<<"   ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    
    for(auto x: final_adj) {
        cout<<x.first<<" --> "<<endl;
        for(auto y: x.second) {
            cout<<y.first <<"  -  "<<y.second<<endl;
        }
        cout<<endl;
    }

// */
    
    return 0;
}


/*

input  1
8

0 1 2 3 4 5 6 7 

2

0 1  

0

1

2

1 5
6 2 
0 2
2 6
7 5
2 6
6 4
6 2


output1

Number of states - 8
States
0    1    2    3    4    5    6    7    
Number of Alphabets -  2
Alphabets 
0    1    
Starting state -  0
Final state count - 1
2   
transitions  - 
1   5   
6   2   
0   2   
2   6   
7   5   
2   6   
6   4   
6   2   

Adjacency list 
0 -->    
1  0
5  1

1 -->    
6  0
2  1

2 -->    
0  0
2  1

3 -->    
2  0
6  1

4 -->    
7  0
5  1

5 -->    
2  0
6  1

6 -->    
6  0
4  1

7 -->    
6  0
2  1


Visited list before  - 
0  0  0  0  0  0  0  0  0  0  0  0  0  
Visited list after - 
1  1  1  0  1  1  1  1  
States after the dfs call 
0    1    2    -1    4    5    6    7    
0  0  -1  0  0  0  0  0  
0  0  -1  0  0  0  0  0  
0  0  0  0  -1  -1  -1  -1  
1  1  0  1  0  0  0  0  
0  0  0  0  0  0  0  0  
0  0  0  0  0  0  0  0  
0  0  0  0  0  0  0  0  
0  0  0  0  0  0  0  0  
1
0   1 0
0  -  1  -  6 -- 0
Dp filing  -- 1  6
1  -  2  -  5 -- -1
 Value is -1 
*****************
2
0   2 -1
End because of -1 
 -- 
3
0   4 0
0  -  1  -  7 -- 0
Dp filing  -- 1  7
1  -  Same so NO help from them 
*****************
4
0   5 0
0  -  1  -  2 -- -1
 Value is -1 
*****************
5
0   6 0
0  -  1  -  6 -- 0
Dp filing  -- 1  6
1  -  4  -  5 -- 0
Dp filing  -- 4  5
*****************
6
0   7 0
0  -  1  -  6 -- 0
Dp filing  -- 1  6
1  -  2  -  5 -- -1
 Value is -1 
*****************
7
1   2 -1
End because of -1 
 -- 
8
1   4 0
0  -  6  -  7 -- 0
Dp filing  -- 6  7
1  -  2  -  5 -- -1
 Value is -1 
*****************
9
1   5 0
0  -  2  -  6 -- -1
 Value is -1 
*****************
10
1   6 0
0  -  Same so NO help from them 
1  -  2  -  4 -- -1
 Value is -1 
backtracting  -- 0  1
backtracting  -- 0  6
backtracting  -- 0  7
*****************
11
1   7 0
0  -  Same so NO help from them 
1  -  Same so NO help from them 
*****************
12
2   4 -1
End because of -1 
 -- 
13
2   5 -1
End because of -1 
 -- 
14
2   6 -1
End because of -1 
 -- 
15
2   7 -1
End because of -1 
 -- 
16
4   5 0
0  -  2  -  7 -- -1
 Value is -1 
backtracting  -- 0  6
*****************
17
4   6 0
0  -  6  -  7 -- 0
Dp filing  -- 6  7
1  -  4  -  5 -- -1
 Value is -1 
*****************
18
4   7 0
0  -  6  -  7 -- 0
Dp filing  -- 6  7
1  -  2  -  5 -- -1
 Value is -1 
*****************
19
5   6 0
0  -  2  -  6 -- -1
 Value is -1 
*****************
20
5   7 0
0  -  2  -  6 -- -1
 Value is -1 
*****************
21
6   7 0
0  -  Same so NO help from them 
1  -  2  -  4 -- -1
 Value is -1 
backtracting  -- 1  4
backtracting  -- 4  6
backtracting  -- 4  7
*****************
0     -1     -1     0     0     -1     -1     -1     0     
0     0     -1     0     -1     -1     -1     0     0     
0     0     0     0     -1     -1     -1     -1     0     
0     0     0     0     0     0     0     0     0     
0     0     0     0     0     -1     -1     -1     0     
0     0     0     0     0     0     -1     -1     0     
0     0     0     0     0     0     0     -1     0     
0     0     0     0     0     0     0     0     0     
0     0     0     0     0     0     0     0     0     
0  1  2  -1  4  5  6  7  
4  7  2  -1  4  5  6  7  
Number of new states - 5
New states 
2 -->  
2   
4 -->  
0   4   
5 -->  
5   
6 -->  
6   
7 -->  
1   7   
2  1
4  0
5  0
6  0
7  0

New start  -->  4
2
4
5
6
7
Transitions  -- >  
2 --> 
0  -  4
1  -  2

4 --> 
0  -  7
1  -  5

5 --> 
0  -  2
1  -  6

6 --> 
0  -  6
1  -  4

7 --> 
0  -  6
1  -  2



*/


/*

input2 

5

1 2 3 4 5  

2

a b

1

1

5

2 3
2 4
2 3
2 5
2 3


output2

Number of states - 5
States
1    2    3    4    5    
Number of Alphabets -  2
Alphabets 
a    b    
Starting state -  1
Final state count - 1
5   
transitions  - 
2   3   
2   4   
2   3   
2   5   
2   3   

Adjacency list 
1 -->    
2  a
3  b

2 -->    
2  a
4  b

3 -->    
2  a
3  b

4 -->    
2  a
5  b

5 -->    
2  a
3  b


Visited list before  - 
0  0  0  0  0  0  0  0  0  0  
Visited list after - 
0  1  1  1  1  
States after the dfs call 
1    2    3    4    5    
0  0  0  0  -1  
0  0  0  0  -1  
0  0  0  0  -1  
0  0  0  0  -1  
0  0  0  0  0  
1
1   2 0
a  -  Same so NO help from them 
b  -  3  -  4 -- 0
Dp filing  -- 3  4
*****************
2
1   3 0
a  -  Same so NO help from them 
b  -  Same so NO help from them 
*****************
3
1   4 0
a  -  Same so NO help from them 
b  -  3  -  5 -- -1
 Value is -1 
*****************
4
1   5 -1
End because of -1 
 -- 
5
2   3 0
a  -  Same so NO help from them 
b  -  3  -  4 -- 0
Dp filing  -- 3  4
*****************
6
2   4 0
a  -  Same so NO help from them 
b  -  4  -  5 -- -1
 Value is -1 
*****************
7
2   5 -1
End because of -1 
 -- 
8
3   4 0
a  -  Same so NO help from them 
b  -  3  -  5 -- -1
 Value is -1 
backtracting  -- 1  2
backtracting  -- 2  3
*****************
9
3   5 -1
End because of -1 
 -- 
10
4   5 -1
End because of -1 
 -- 
0     0     0     0     0     0     
0     0     -1     0     -1     -1     
0     0     0     -1     -1     -1     
0     0     0     0     -1     -1     
0     0     0     0     0     -1     
0     0     0     0     0     0     
1  2  3  4  5  
3  2  3  4  5  
Number of new states - 4
New states 
2 -->  
2   
3 -->  
1   3   
4 -->  
4   
5 -->  
5   
2  0
3  0
4  0
5  1

New start  -->  3
2
3
4
5
Transitions  -- >  
2 --> 
a  -  2
b  -  4

3 --> 
a  -  2
b  -  3

4 --> 
a  -  2
b  -  5

5 --> 
a  -  2
b  -  3



*/

/*

input3
6

1 2 3 4 5 6  

2

a b

1

2

5 6

2 3 
5 4
6 4
4 4 
5 5
6 6 

output3
Number of states - 6
States
1    2    3    4    5    6    
Number of Alphabets -  2
Alphabets 
a    b    
Starting state -  1
Final state count - 2
5   6   
transitions  - 
2   3   
5   4   
6   4   
4   4   
5   5   
6   6   

Adjacency list 
1 -->    
2  a
3  b

2 -->    
5  a
4  b

3 -->    
6  a
4  b

4 -->    
4  a
4  b

5 -->    
5  a
5  b

6 -->    
6  a
6  b


Visited list before  - 
0  0  0  0  0  0  0  0  0  0  0  
Visited list after - 
0  1  1  1  1  1  
States after the dfs call 
1    2    3    4    5    6    
0  0  0  0  -1  -1  
0  0  0  0  -1  -1  
0  0  0  0  -1  -1  
0  0  0  0  -1  -1  
0  0  0  0  0  0  
0  0  0  0  0  0  
1
1   2 0
a  -  2  -  5 -- -1
 Value is -1 
*****************
2
1   3 0
a  -  2  -  6 -- -1
 Value is -1 
*****************
3
1   4 0
a  -  2  -  4 -- 0
Dp filing  -- 2  4
b  -  3  -  4 -- 0
Dp filing  -- 3  4
*****************
4
1   5 -1
End because of -1 
 -- 
5
1   6 -1
End because of -1 
 -- 
6
2   3 0
a  -  5  -  6 -- 0
Dp filing  -- 5  6
b  -  Same so NO help from them 
*****************
7
2   4 0
a  -  4  -  5 -- -1
 Value is -1 
backtracting  -- 1  4
*****************
8
2   5 -1
End because of -1 
 -- 
9
2   6 -1
End because of -1 
 -- 
10
3   4 0
a  -  4  -  6 -- -1
 Value is -1 
backtracting  -- 1  4
*****************
11
3   5 -1
End because of -1 
 -- 
12
3   6 -1
End because of -1 
 -- 
13
4   5 -1
End because of -1 
 -- 
14
4   6 -1
End because of -1 
 -- 
15
5   6 0
a  -  say AB goes to AB so NO help from here 
b  -  say AB goes to AB so NO help from here 
*****************
0     0     0     0     0     0     0     
0     0     -1     -1     -1     -1     -1     
0     0     0     0     -1     -1     -1     
0     0     0     0     -1     -1     -1     
0     0     0     0     0     -1     -1     
0     0     0     0     0     0     0     
0     0     0     0     0     0     0     
1  2  3  4  5  6  
1  3  3  4  6  6  
Number of new states - 4
New states 
1 -->  
1   
3 -->  
2   3   
4 -->  
4   
6 -->  
5   6   
1  0
3  0
4  0
6  1

New start  -->  1
1
3
4
6
Transitions  -- >  
1 --> 
a  -  3
b  -  3

3 --> 
a  -  6
b  -  4

4 --> 
a  -  4
b  -  4

6 --> 
a  -  6
b  -  6



*/

/*

6

1 2 3 4 5 6  

2

a b

1

3

3 4 5 

2 3 
1 4 
5 6 
5 6 
5 6
6 6 

output 
Number of states - 6
States
1    2    3    4    5    6    
Number of Alphabets -  2
Alphabets 
a    b    
Starting state -  1
Final state count - 3
3   4   5   
transitions  - 
2   3   
1   4   
5   6   
5   6   
5   6   
6   6   

Adjacency list 
1 -->    
2  a
3  b

2 -->    
1  a
4  b

3 -->    
5  a
6  b

4 -->    
5  a
6  b

5 -->    
5  a
6  b

6 -->    
6  a
6  b


Visited list before  - 
0  0  0  0  0  0  0  0  0  0  0  
Visited list after - 
0  1  1  1  1  1  
States after the dfs call 
1    2    3    4    5    6    
0  0  -1  -1  -1  0  
0  0  -1  -1  -1  0  
0  0  0  0  0  -1  
0  0  0  0  0  -1  
0  0  0  0  0  -1  
0  0  0  0  0  0  
1
1   2 0
a  -  say AB goes to AB so NO help from here 
b  -  3  -  4 -- 0
Dp filing  -- 3  4
*****************
2
1   3 -1
End because of -1 
 -- 
3
1   4 -1
End because of -1 
 -- 
4
1   5 -1
End because of -1 
 -- 
5
1   6 0
a  -  2  -  6 -- 0
Dp filing  -- 2  6
b  -  3  -  6 -- -1
 Value is -1 
*****************
6
2   3 -1
End because of -1 
 -- 
7
2   4 -1
End because of -1 
 -- 
8
2   5 -1
End because of -1 
 -- 
9
2   6 0
a  -  1  -  6 -- -1
 Value is -1 
backtracting  -- 1  6
*****************
10
3   4 0
a  -  Same so NO help from them 
b  -  Same so NO help from them 
*****************
11
3   5 0
a  -  Same so NO help from them 
b  -  Same so NO help from them 
*****************
12
3   6 -1
End because of -1 
 -- 
13
4   5 0
a  -  Same so NO help from them 
b  -  Same so NO help from them 
*****************
14
4   6 -1
End because of -1 
 -- 
15
5   6 -1
End because of -1 
 -- 
0     0     0     0     0     0     0     
0     0     0     -1     -1     -1     -1     
0     0     0     -1     -1     -1     -1     
0     0     0     0     0     0     -1     
0     0     0     0     0     0     -1     
0     0     0     0     0     0     -1     
0     0     0     0     0     0     0     
1  2  3  4  5  6  
2  2  5  5  5  6  
Number of new states - 3
New states 
2 -->  
1   2   
5 -->  
3   4   5   
6 -->  
6   
2  0
5  1
6  0

New start  -->  2
2
5
6
Transitions  -- >  
2 --> 
a  -  2
b  -  5

5 --> 
a  -  5
b  -  6

6 --> 
a  -  6
b  -  6



*/


/*


*/