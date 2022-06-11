#include<bits/stdc++.h>
using namespace std;

// const int N=1000;

// int indeg[N];
// int reach[N];

// map <char,int>  indeg;
// map <char,int> reach;

map < char , vector < pair <char ,char > > > adj;
map <char ,int> visited;



void dfs(char ch){

    visited[ch]=1;

    for (auto x: adj[ch]) {
        if ( visited[ x.second ] ==0 ) {
            dfs(x.second);
        }
    }

}


map < pair < char , char > ,  vector < pair <char ,char> >  > dp;

map < pair < char , char > , int  >  value;




void backtract(char state1,char state2) {
    for (auto x: dp [ {state1,state2} ]) {
        value[{x.first,x.second}]=-1;
        backtract(x.first,x.second);
    }
    
}


int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // input the number of states 
    int num;
    cin>>num;

    // for deletion using vector 

    char state[num];
    // vector < char > state;
    // char ch;

    for(int i=0;i<num;i++) {
        cin>>state[i];
        // cin>>ch;
        // state.push_back(ch);
    }



    // input the number of alphabets 
    int alp;
    cin>>alp;

    char alpha[alp]; // no need to delete so char array works 

    for(int i=0;i<alp;i++){
        cin>>alpha[i];
    }


    // initial state
    char start;
    cin>>start;


    // final states 
    int final_count;
    cin>>final_count;

    char final_state [final_count]; // can be deleted --> becuase we can have a final state as not reachable also 
    // vector < char > final_state;


    for(int i=0;i<final_count;i++){
        cin>>final_state[i];
        // cin>>ch;
        // final_state.push_back(ch);
    }


    // transition table
    char arr[num][alp]; 

    for(int i=0;i<num;i++){
        for(int j=0;j<alp;j++) {
            cin>>arr[i][j];
        }
    }


    // forming a graph 
    // vector < pair <char ,char > > adj(num);
    // map < char , vector < pair <char ,char > > > adj;
    // for each state -> marking where it goes at what alphabet/input 
    // adj[0] --> not number 
    // adj['A'] -->  vector of choices it goes to --> first -> 0/1 
    // and second is where it goes to at that choice of alphabet 
    // adj['A'] -->   {  ('1' -> 'B')     ('0' -> 'C')    }

    for(int i=0;i<num;i++) {
        for(int j=0;j<alp;j++) {
            adj[ state[i] ].push_back({ alpha[j] , arr[i][j] });
        }
    }


    
    // Step 1 : removing the non reachable states from the initial state 
    // method 1 : marking 1 if it can be reached else marking 0 (are not reached in the dfs algo )
    // method 2 : whose in-degree remains 0 (are not reached in the dfs algo )
    // for(int i=0;i<num;i++){
    //     reach[i]=0;
    //     indeg[i]=0;
    // }   
    // or just only will work 
    // if after dfs it is not visited then of no use 

    // map bydefault 0 value 
    dfs(start);

    // checking if visited or not 
    int reach[num];
    // 0 if not reachable  -->  no need to process this anywhere 
    // 1 if reachable  -->  process only these 


    for(int i=0;i<num;i++) {
        if ( visited [ state[i] ] ==0 ) {
            reach[i]=0;
        }
        else {
            // continue;
            reach[i]=1;
        }
    }
    // implement the above feature later please 
    // otherwise you will get wrong answer 


    // map < pair < char , char > , int  >  value; // -1 if different else 0 (by default --> means same (that is if not marked ) ) 


    // map < pair < char , char > ,  vector < pair <char ,char> >  > dp;

    for(int i=0;i<num-1;i++) {
        for(int j=i+1;j<num;j++) {
            // first state --> arr[i]
            // second state --> arr[j]
            char state1=state[i];
            char state2=state[j];
            
            // checking if both are final states or not 
            int is_first_final=0;
            int is_second_final=0;
            for(int k=0;k<final_count;k++) {
                if (final_state[k] == state1) {
                    is_first_final=1;
                }
                else if (final_state[k] == state2) {
                    is_second_final=1;
                }                
            }

            if (is_first_final==0 && is_second_final==1) {
                value[{state1,state2}]=-1;
            }
            else if (is_first_final==1 && is_second_final==0) {
                value[{state1,state2}]=-1;
            }

        }

    }


    for(int i=0;i<num-1;i++) {
        for(int j=i+1;j<num;j++) {
            // // first state --> arr[i]
            // // second state --> arr[j]
            char state1=state[i];
            char state2=state[j];
            
            if (value[ { state1 ,state2}] == -1 ) {
                continue;
            }
            else {
                
                for (int k=0;k<alp;k++) {
                    // input char 
                    // char input=alpha[k];

                    // state1 goes to ___ on this input 
                    char output1=arr[i][k];

                    // state2 output on this input 
                    char output2=arr[j][k];

                    if (output1>output2) {
                        swap(output1,output2);
                    }
                    // so combined state is    { output1,output2 } where output1<output2

                    // dp[{state1,state2}].push_back( {output1,output2} );
                    if (value[{output1,output2}] == -1 ) {
                        value [ {state1,state2} ] = -1;


                        // if you are marking this as -1 then you also have to backtract and mark others as -1 also whose value is stored there 
                        // as so on they must also be having some values stored and they have to backtract also 

                        for (auto x: dp [ {state1,state2} ]) {
                            value[{x.first,x.second}]=-1;
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
                    }


                }

            }

        }

    }


    char new_start=start; // start same 
    // alphabet same 
    
    // states change 
    // transition change 
    // final change 

    // for state 

    // // int parent[num];
    // vector <char> parent(num);

    map <char ,char> parent;

    for(int i=0;i<num;i++) {
        parent[state[i]]=state[i];
    }

    // for (int i=0;i<num;i++) {
    //     parent[i]=-1;
    // }
    

    for(int i=0;i<num-1;i++) {
        for(int j=i+1;j<num;j++) {
            char state1=state[i];
            char state2=state[j];

            if (value[{state1,state2}] == -1) {

            }
            else {
                // parent of state1 
                // parent of state2
                char parent1=parent[state1];
                char parent2=parent[state2];

                // make parent1 equal to parent2 

                for(auto it=parent.begin();it!=parent.end();it++) {
                    if ((*it).second == parent1) {
                        parent[((*it).first)]=parent2;
                    }
                }

            }


        }
    }



    map <char ,set <char>> new_states;
    

    int num_final=0;

    

    for(int i=0;i<num;i++) {
        new_states[parent[i]].insert(state[i]);
    }

    num_final=new_states.size();


    
    // new_states are ready 

    // finding the final states 
    

    map <char,int> isfinal;  // 1 if final   0 if not final 

    for(auto x: new_states){
        isfinal[x.first]=0;
    }


    // checking if final or not 
    for(auto x: new_states) {
        int check=0;
        for(auto y: x.second) {
            // check if y is final or not 
            for(int i=0;i<final_count;i++) {
                if (final_state[i] ==y ) {
                    check=1;
                    break;
                }
            }
        }
        if (check) {
            isfinal[x.first]=1;
        }
    }
    


    // // finding a transition table 
    // map < char , vector < pair <char ,char > > > adj;
    char arr_final[num_final][alp];

    for(int i=0;i<num_final;i++) {
        for(int j=0;j<alp;j++) {
            arr_final[i][j]='?';
        }
    }


    for(auto x: new_states) {
        char checker=*(x.second.begin());

        for(int i=0;i<alp;i++) {
            // char going_to=[][];
            char going_to='?';

            for(auto x: adj[checker]) {
                if (x.first==alpha[i])  {
                    going_to=x.second;
                }
            }

            char state_of_going_to;
            for (auto k: new_states) {
                for(auto kk : k.second)  {
                    if (going_to == kk) {
                        state_of_going_to=k.first;
                        break;
                    }
                }
            }

        }

    }


    // done 

    cout<<num_final<<endl;


    for(auto x: new_states) {
        cout<<x.first << endl;
        for(auto y: x.second) {
            cout<<y<<"  ";
        }
        cout<<endl;
    }


    for(auto x: isfinal) {
        cout<<x.first<< "   "<<x.second<<endl;
    }


    cout<<new_start<<endl;


 for(int i=0;i<num_final;i++) {
        for(int j=0;j<alp;j++) {
            cout<<arr_final[i][j]<<"   ";
        }
        cout<<endl;
    }
    cout<<endl;

    

    
    return 0;
}