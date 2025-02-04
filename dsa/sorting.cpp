#include<iostream>
using namespace std;

void insertionSort(int arr[],int n){
    int temp,j;
    for(int k=1;k<n;k++){
        temp=arr[k];
        j=k-1;
        while(j>=0 && temp<=arr[j]){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=temp;
    }
}
void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        } 
        }
    }
}
int main(){
    int n;
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bubbleSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}