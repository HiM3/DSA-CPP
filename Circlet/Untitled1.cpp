// Online C compiler to run C program online
#include <stdio.h>

int main() {
    // Write C code here
int max=0,i,j,arr[5]={1,2,3,4,5};
for(i=1;i<=arr[5];i++){
    for(j=1;j<=arr[i];j++){
        if(arr[i]<arr[j]){
            arr[i]=max;
            max=arr[j];
            arr[j]=arr[i];
        }
    }
        printf("%d\n",arr[i]);
}
    return 0;
}
