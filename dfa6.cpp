#include<bits/stdc++.h>
using namespace std;


const int max_states=50;

vector < pair <int,int> > adj[max_states]; // adjacency list    
// index --> state     .first --> goes to this state   .second --> on this input alphabet 

int vis[max_states];


void dfs(int root){
    vis[root]=1;
    for(auto x: adj[root]) {
        if (!vis[x.first]){
            dfs(x.first);
        }
    }
}


map < pair <int,int> , int > is_non_distinguishable;

map < pair <int,int> , set < pair <int,int> > > adj2;


int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int num; // number of states 
    cin>>num;

    // the states will be 1,2,3,4...num
    int state[num];

    for(int i=0;i<num;i++) {
        state[i]=i+1;
    }

    int num_alphabet; // number of alphabets 
    cin>>num_alphabet; 

    // like A B ... or even 0 1 ...
    char alphabet[num_alphabet];

    for(int i=0;i<num_alphabet;i++) {
        cin>>alphabet[i];
    }

    int start; // starting state
    cin>>start;

    int num_final; // number of final states 
    cin>>num_final;

    int final_state[num_final]; // final states 

    for(int i=0;i<num_final;i++){
        cin>>final_state[i];
    }

    // transition table
    int table[num][num_alphabet];

    for(int i=0;i<num;i++) {
        for(int j=0;j<num_alphabet;j++) {
            cin>>table[i][j];
        }
    }

    // checking for some unreachable node and removing them because we cannot reach them from starting state
    
    for(int i=0;i<num;i++) {
        for(int j=0;j<num_alphabet;j++) {
            adj[state[i]].push_back({table[i][j] , alphabet[j]}); // 1 --> 2,A   3,B // 1 based indexing 
        }
    }

    for(int i=0;i<num+1;i++) { // because of 1 based indexing 
        vis[i]=0; // initially none is visited 
    }

    
    cout<<"Number of states - " <<num<<endl;
    
    cout<<"States"<<endl;
    
    for(int i=0;i<num;i++) {
        cout<<state[i]<<"    ";
    }
    cout<<endl;
    
    
    cout<<"Number of Alphabets -  " <<num_alphabet<<endl;
    
    cout<<"Alphabets "<<endl;
    
    for(int i=0;i<num_alphabet;i++) {
        cout<<alphabet[i]<<"    ";
    }
    cout<<endl;
    
    
    cout<<"Starting state -  "<<start<<endl;
    
    cout<<"Final state count - "<<num_final<<endl;
    
    for(int i=0;i<num_final;i++){
        cout<<final_state[i]<<"   ";
    }
    cout<<endl;
    
    
    cout<<"transitions  - "<<endl;
    
    for(int i=0;i<num;i++){
        for(int j=0;j<num_alphabet;j++) {
            cout<<table[i][j]<<"   ";
        }
        cout<<endl;
    }
    cout<<endl;


    cout<<"Adjacency list "<<endl;
    for(int i=0;i<num;i++) {
        for(auto x: adj[state[i]]) {
            cout<<x.first << "  "<<x.second<<endl;
        }
        cout<<endl;
    }


    cout<<"Visited list before  - "<<endl;
    for(int i=0;i<num;i++) {
        cout<<vis[i]<<"  ";
    }
    cout<<endl;

    // calling dfs to find the unreachable nodes 
    dfs(start);

    // now those who are still not visited are unreachable 
    // vis[i]==0 then they are unreachable 
    for(int i=0;i<num;i++) {
        if (vis[state[i]] == 0) {
            state[i]=-1; // do not exist
        }
    }

    
    
    
    

    cout<<"Visited list after - "<<endl;
    for(int i=0;i<num;i++) {
        cout<<vis[i]<<"  ";
    }
    cout<<endl;

    cout<<"States after the dfs call "<<endl;
    
    for(int i=0;i<num;i++) {
        cout<<state[i]<<"    ";
    }
    cout<<endl;



    // create 2N nodes 

    for(int i=0;i<num-1;i++) {
        for(int j=i+1;j<num;j++) {
            is_non_distinguishable[{state[i],state[j]}]=1;
        }
    }

    // marking the non distinguisable 
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
                else if (final_state[k] == state2) {
                    is_second_final=1;
                }                
            }

            if (is_first_final==0 && is_second_final==1) {
                is_non_distinguishable[{state1,state2}]=-1; // means they are distingusiable now / separate / cannot be merged / base case 
            }
            else if (is_first_final==1 && is_second_final==0) {
                is_non_distinguishable[{state1,state2}]=-1;
            }

        }

    }


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
            // cout<<state1<< "   "<<state2 << " " <<value[state1][state2] << endl;
            
            
            // if ( value[state1][state2] == -1 ) {
            //     cout<<"End because of -1 "<<endl;
            //     cout<<" -- "<<endl;
            //     continue;
            // }
            // else {
                
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
                    
                    if (output1==state1 && output2==state2) {
                        cout<<"say AB goes to AB so NO help from here "<<endl;
                        continue;
                    }

                    if (output1>output2) {
                        swap(output1,output2);
                    }
                    // so combined state is    { output1,output2 } where output1<output2
                    
                    cout<<output1<<"  -  "<<output2 << " -- "<<endl;
                    //  <<value[output1][output2] <<endl ;
                    
                    

                    // // dp[{state1,state2}].push_back( {output1,output2} );
                    // if (value[output1][output2] == -1 ) {
                    //     value[state1][state2] = -1;
                        
                    //     cout<<" Value is -1 "<<endl;


                    //     // if you are marking this as -1 then you also have to backtract and mark others as -1 also whose value is stored there 
                    //     // as so on they must also be having some values stored and they have to backtract also 

                    //     for (auto x: dp [ {state1,state2} ]) {
                    //         value[x.first][x.second]=-1;
                    //         cout<<"backtracting  -- "<< x.first <<"  " <<x.second<< endl;
                    //         backtract(x.first,x.second);
                    //     }

                    //     // -1 then no need to check other inputs 
                    //     break; // correct do please 
                    // }
                    // else {
                    //     // for backtracting purpose 
                    //     // if later we got -1 there then we will put -1 here also 
                    //     // continue;
                    //     dp[{output1,output2}].push_back({state1,state2});
                        
                    //     cout<<"Dp filing  -- "<< output1<< "  " << output2<<endl;
                        
                    // }


                // }


                adj2[{state1,state2}].insert({output1,output2});

                adj2[{output1,output2}].insert({state1,state2});

            }
            
            
            // cout<<"*****************"<<endl;

        }

    }

    

    


    return 0;
}