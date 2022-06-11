ill solve(ill x,ill y) {

    // cout<<x<<"  " <<y<<endl;
    
    if (x==0 && y==0) {
        return 1;
    }
    if (x<0 || y<0) {
        return 0;
    }

    if (x==y) {
        ill ans=0;

        f3(i,x-1,0) {
            ans=(ans%mod +solve(i,i)%mod )%mod ;
        }

        f3(i,x-1,0) {
            f3(j,y-1,0) {
                ans=(ans%mod +solve(i,j)%mod )%mod ;
            }
        }

        return ans;

    }
    else {
        ill ans=0;

        if (x==0 && y>0) {
            f3(i,y-1,0){
                ans=(ans%mod +solve(0,i)%mod )%mod ;
            }

            return ans;
        }

        if (x>0 && y==0) {
            f3(i,x-1,0){
                ans=(ans%mod +solve(i,0)%mod )%mod ;
            }

            return ans;
        }

        f3(i,x-1,0) {
            f3(j,y-1,0) {
                ans=(ans%mod +solve(i,j)%mod )%mod ;
            }
        }

        return ans;

    }
}
