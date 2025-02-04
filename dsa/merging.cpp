#include<iostream>
using namespace std;

void merge(int arr3[],int arr1[],int n,int arr2[],int n1){
    int i=0,j=0,k=0;
    while(i<n && j<n1){
        if(arr1[i]<arr2[j]){
            arr3[k++]=arr1[i++];
        }
        else{
            arr3[k++]=arr2[j++];
        }

    }
    while(i<n){
        arr3[k++]=arr1[i++];
    }
    while(j<n1){
        arr3[k++]=arr2[j++];
    }
}
int main(){
    int n;
    cin>>n;
    int arr1[100];
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    int n1;
    cin>>n1;
    int arr2[100];
    for(int i=0;i<n1;i++){
        cin>>arr2[i];
    }
    int arr3[n+n1];
    merge(arr3,arr1,n,arr2,n1);
    for(int i=0;i<n+n1;i++){
        cout<<arr3[i];
    }
}
