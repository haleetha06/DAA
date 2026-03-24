
#include <stdio.h>
int partition(int arr[], int low, int high) {
    int pivot=arr[high];
    int i=low;
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
        }
    }
    int temp=arr[i];
    arr[i]=arr[high];
    arr[high]=temp;
    return i;
}
int quickSelect(int arr[], int low, int high, int k) {
    if(low<=high){
        int pivotIndex=partition(arr, low, high);
        if(pivotIndex==k)
            return arr[pivotIndex];
        else if(pivotIndex>k)
            return quickSelect(arr, low, pivotIndex-1, k);
        else
            return quickSelect(arr, pivotIndex+1, high, k);
    }
    return -1;
}
int main(){
    int arr[]={157,110,147,122,111,149,151,141,123,112,117,133};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k;
    
    printf("Enter k: ");
    scanf("%d", &k);
    int result=quickSelect(arr, 0, n-1, k-1);
    printf("k-th smallest element: %d\n", result);
    return 0;
}