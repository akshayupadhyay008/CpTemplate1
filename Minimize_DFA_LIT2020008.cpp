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
// then in {state3,state4} is dependent on {state1,state2} so if {state3,state4} are distinguihable(state3 and state4 are different) then {state1,state2} are also distinguishable(state1 and state2 are different)
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

// for making the dependent pair of states distinguishable if current pair of state is distinguishable
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

    cout<<endl;
    cout<<"Enter the states in the DFA - "<<endl;
    int state[num];
    for(int i=0;i<num;i++) {
        cout<<"Enter the state "<<i+1<<" - ";
        cin>>state[i];
    }

    cout<<endl;
    cout<<"Enter the number of alphabets in the DFA - ";
    int num_alphabet; // number of alphabets 
    cin>>num_alphabet; 

    cout<<endl;
    cout<<"Enter the alphabets in the DFA - "<<endl;   
    char alphabet[num_alphabet];
    for(int i=0;i<num_alphabet;i++) {
        cout<<"Enter the alphabet "<<i+1<<" - ";
        cin>>alphabet[i];
    }

    cout<<endl;
    cout<<"Enter the starting state of the DFA - ";
    int start; // starting state
    cin>>start;

    cout<<endl;
    cout<<"Enter the number of final states of the DFA - ";
    int num_final; // number of final states 
    cin>>num_final;

    cout<<endl;
    cout<<"Enter the final states of the DFA - "<<endl;
    int final_state[num_final]; // final states 
    for(int i=0;i<num_final;i++){
        cout<<"Enter the final state "<<i+1<<" - ";
        cin>>final_state[i];
    }

    cout<<endl;
    cout<<"Enter the transtion table in order (from first state to last state and for each alphabet ) - "<<endl;
    // transition table
    int table[num][num_alphabet];

    for(int i=0;i<num;i++) {
        for(int j=0;j<num_alphabet;j++) {
            cin>>table[i][j];
        }
    }

    cout<<endl;
    cout<<endl;
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

    // initialising the dependency as indistinguishable/same/can be merged at present as 0 
    // -1 will means distinguishable/different/cannot be merged 
    // value[x][y]=0 means state x and y are same/indistinguishable/can be merged
    // value[x][y]=-1 means state x and y are different/distinguishable/cannot be merged
    for(int i=0;i<num+2;i++) {
        for(int j=0;j<num+2;j++) {
            value[i][j]=0; // 0 means they are not distinguisable now 
        }
    }

    // Base case initialisation 
    // a final and a non-final state is always different/distinguishable so value[x][y] for them = -1 (this is the base case)
    // we use this case to find all the dependencies and minimize the DFA as minimisation of DFA into equivalent states follows equvalent property (transitive/reflexive/symmetric)
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

            /* testing 
            cout<< state1<<"   " <<state2<<"   "<<is_first_final<< "   "<<is_second_final<< endl;
            */

            if (is_first_final==0 && is_second_final==1) {
                value[state1][state2]=-1; // means they are distingusiable now / separate / cannot be merged / base case 
            }
            else if (is_first_final==1 && is_second_final==0) {
                value[state1][state2]=-1;
            }

            /* testing 
            cout<<value[state1][state2]<<"   "<<endl;
            cout<<"***"<<endl;
            */
        }

    }
    
    /* testing  value array after applying the base case 
    for(int i=0;i<num;i++) {
        for(int j=0;j<num;j++) {
            int state1=state[i];
            int state2=state[j];
            cout<<value[state1][state2] << "  ";
        }
        cout<<endl;
    }   
    */

    int temp=0; // temparary variable to count the number of steps (no need as such)

    // we are finding the states which are different by using dependency of pair of states 
    // NOTE that we are finding that the 2 states in a pair are different or not from the already existing different states 
    // if at the end we find that the two states are not different so that will imply that they are same and can be merged 
    for(int i=0;i<num-1;i++) {
        for(int j=i+1;j<num;j++) {
            int state1=state[i];
            int state2=state[j];

            if (state[i] == -1 || state[j] == -1)  {
                continue; // non reachable states 
            }

            /* testing
            temp++;
            cout<<temp<<endl;
            cout<<state1<< "   "<<state2 << " " <<value[state1][state2] << endl;
            */
            
            if ( value[state1][state2] == -1 ) { 
                /* testing
                cout<<" (End because of -1) "<<endl;
                cout<<" -- "<<endl;
                */
                continue; // already -1 so no need to process this 
            }
            else {
                
                for (int k=0;k<num_alphabet;k++) { // checking for each alphabet its dependency (where the combined state is going on this input )
                    /*
                    cout<<alphabet[k]<<"  -  ";
                    */

                    // state1 goes to this output on this input 
                    int output1=table[i][k];

                    // state2 goes to this output on this input 
                    int output2=table[j][k];

                    if (output1==output2) {
                        /* 
                        cout<<"Same so NO help from them "<<endl;
                        */
                        continue;  // output1 and output2 are already same so this will not help in provind state1 and state2 different 
                        // (NOTE --> only different state can say that this is also different and if till the end we are unable to prove them different then they are automatically same )
                    }
                    
                    if (output1==state1 && output2==state2 ) {
                        // cout<<"say AB goes to AB so NO help from here "<<endl;
                        continue; // pointing to itself will not prove that they are different 
                    }

                    
                    if (output1==state2 && output2==state1 ) {
                        // cout<<"say AB goes to AB so NO help from here "<<endl;
                        continue; // pointing to itself will not prove that they are different 
                    }

                    if (output1>output2) {
                        swap(output1,output2); // pair of state is defined as ordered pair {x,y} where x<y to avoid duplicates({x,y} {y,x})
                    }
                    // so combined state is    { output1,output2 } where output1<output2 
                    
                    /*
                    cout<<output1<<"  -  "<<output2 << " -- " <<value[output1][output2] <<endl ;
                    */                   

                    if (value[output1][output2] == -1 ) {
                        value[state1][state2] = -1;
                        // following from dependency if {output1,output2} state is
                        // different then in 1 step you can move from this combined states to outputs so they are also different 
                        
                        /* 
                        cout<<" Value is -1 "<<endl;
                        */

                        // if you are marking this as -1 then you also have to backtract and mark others as -1 which depend on this whose value is stored there the dp table 
                        // and so we have to backtract continuously till we mark all the dependencies as -1 
                        for (auto x: dp [ {state1,state2} ]) {
                            value[x.first][x.second]=-1;
                            /*cout<<"backtracting  -- "<< x.first <<"  " <<x.second<< endl;*/
                            backtract(x.first,x.second);
                        }

                        // -1 then no need to check other inputs so break
                        break;
                    }
                    else {
                        // for backtracting purpose 
                        // if later we got -1 there then we will put -1 here also 
                        dp[{output1,output2}].push_back({state1,state2});

                        /*cout<<"Dp filing  -- "<< output1<< "  " << output2<<endl;*/
                    }
                }
            }
            /*cout<<"*****************"<<endl;*/
        }
    }

    /* checking the value after processing all the values 
    for(int i=0;i<num+1;i++) {
        for(int j=0;j<num+1;j++) {
            cout<< value[i][j]<< "     ";
        }
        cout<<endl;
    }
    */

    // Storing the New Minimised Automata 

    // merging the indistinguishable states and merging them 
    int parent[num];

    for(int i=0;i<num;i++) {
        parent[i]=state[i]; 
    }

    /* testing 
    for(int i=0;i<num;i++) {
        cout<<parent[i]<< "  ";
    }
    cout<<endl;
    */

    for(int i=0;i<num-1;i++) {
        for(int j=i+1;j<num;j++) {
            int state1=state[i];
            int state2=state[j];

            if (state1==-1 || state2==-1)  {
                continue;
            }

            if (value[state1][state2] == -1) {
                continue; // cannot merge them (as defined if -1 cannot be merged )
            }
            else {
                // parent of state1 
                // parent of state2
                int parent1=parent[i];
                int parent2=parent[j];

                // make parent1 equal to parent2 --> merging the two states 
                for(int k=0;k<num;k++) {
                    if (parent[k] == parent1) {
                        parent[k]=parent2;
                    }
                }
            }
        }
    }
    
    /* testing 
    for(int i=0;i<num;i++) {
        cout<<parent[i]<< "  ";
    }
    cout<<endl;
    */

    // Storing the new states of the minimised DFA    
    map <int , vector <int> > new_states;

    for(int i=0;i<num;i++) {
        if (parent[i]!=-1) {
            new_states[parent[i]].push_back(state[i]);
        }
    }

    int new_state_count=new_states.size();

    cout<<endl<<"Minimised DFA : "<<endl;

    cout<<endl;
    cout<<"Number of states in the Minimised DFA : " << new_state_count<<endl;
    
    cout<<endl;
    cout<<"States in the Minimised DFA and what they represent in the original DFA : "<<endl;
    for(auto x: new_states) {
        cout<<x.first<<"     made up of (state in original DFA) -->  ";
        for(auto y: x.second) {
            cout<<y<<"   ";
        }
        cout<<endl;
    }
    cout<<endl;


    // finding final states
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
    
    vector <int> new_final;

    for(auto x: isfinal) {
        // cout<<x.first << "  "<<x.second<<endl;
        if (x.second==1) {
            new_final.push_back(x.first);
        }
    }
    int new_final_state_count=new_final.size();

    cout<<"Number of final states in the Minimised DFA : "<<new_final_state_count<<endl;

    cout<<endl;
    cout<<"Final states in the Minimised DFA :"<<endl;
    for(auto x: new_final){
        cout<<x<<"  ";
    }
    cout<<endl;
    
    // starting state of the DFA (can be only 1 in any DFA)
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
    
    cout<<endl;
    cout<<"Starting state in the Minimised DFA : "<<new_start<<endl;
    
    // // finding a transition table 
    map < int , vector < pair < char , int > > > final_adj;
    
    for(auto x: new_states) {
        // char checker=(*(x.second.begin()));
        int checker=x.first; // where 1 state is going to can be determined using any 1 state in the merged states 
        // cout<<checker<<endl;
        
        int number_in_initial_state=-1; // finding the index of this state in the input array to see where where it goes at what alphabet 
        for(int i=0;i<num;i++) {
            if (checker==state[i]) {
                number_in_initial_state=i;
                break;
            }
        }


        for(int i=0;i<num_alphabet;i++) {

            int going_to=table[number_in_initial_state][i]; // going to which state in the initial DFA at this alphabet 

            int state_of_going_to; // going to which state in the minimised DFA at this alphabet 
            for (auto k: new_states) {
                for(auto yy : k.second)  {
                    if (going_to == yy) {
                        state_of_going_to=k.first;
                        break;
                    }
                }
            }
            
            final_adj[checker].push_back({alphabet[i],state_of_going_to});

        }

    }
    
    cout<<endl;
    cout<<"Transitions table of the Minimised DFA : "<<endl<<endl;

    for(auto x: final_adj) {
        cout<<"State : "<< x.first<<endl;
        for(auto y: x.second) {
            cout<<"Alphabet : " << y.first <<"  -->  "<<"State : "<< y.second<<endl;
        }
        cout<<endl<<endl;
    }

    return 0;
}
