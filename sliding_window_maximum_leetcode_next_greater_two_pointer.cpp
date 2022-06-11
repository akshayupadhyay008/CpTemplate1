class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        
        int num=arr.size();
        
        stack <int> s;
        int ngi[num];
        
        int inf=num+10;
        ngi[num-1]=inf;
        
        
        
        s.push(num-1);
        cout<<s.top()<<endl;
        for(int i=num-2;i>=0;i--) {
            
            while(1) {
                if (s.empty()){
                    break;
                }
                if (arr[s.top()] <=arr[i]) {
                    s.pop();
                }
                else {
                    break;
                }
            }
            
            if (s.empty()){
                ngi[i]=inf;
            }
            else {
                ngi[i]=s.top();
            }
            
            s.push(i);
        }
        
//         for(int i=0;i<num;i++){
//             cout<<ngi[i]<<" ";
//         }
//         cout<<endl;
        
        vector <int> ans(num-k+1);
        
        int j=0;
        
        for(int i=0;i<=(num-k);i++){
            if (j<i){
                j=i;
            }
            
            while(1){
                if (ngi[j]>=i+k){
                    break;
                }
                else {
                    j=ngi[j];
                }
            }
            
            ans[i]=arr[j];                     
        }
        
        return ans;
    }
};