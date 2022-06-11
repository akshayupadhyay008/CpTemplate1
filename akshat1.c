#include <stdio.h>

int main() {

    int num;
    scanf("%d",&num);

    int arr[num];

    for(int i=0;i<num;i++) {
        scanf("%d",&arr[i]);
    }
    
    int tar;
    scanf("%d",&tar);

    int l=0;
    int r=num-1;

    int ans=0;

    while (l <= r) {
        int m=l+(r-l)/2;
        ans++;
        
        printf("%d ",arr[m]);

        if (arr[m] == tar) {
            break;
        }

        if (arr[m] < tar) {
            l=m+1;
        }
        else {
            r=m-1;
        }

    }

    printf("\nTotal cost: %d",ans);
    
    return 0;
}