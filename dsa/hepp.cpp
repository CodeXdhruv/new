#include<iostream>
using namespace std;

#define MAX 100
int arr[100];
int size=0;

void insert(int value){
    size++;
    int index=size;
    arr[index]=value;
    while(index>1)
    {
        int parent=index/2;
        if(arr[parent]<arr[index]){
            swap(arr[parent],arr[index]);
            index=parent;
        }
        else {
            return;
        }
    }
}
void deletefromHeap(){
    if(size==0){
        return;
    }
    arr[1]=arr[size];
    size--;
    int i=1;
    while(i<=size){
        int left=2*i;
        int right=2*i+1;
        int largest=i;
        if(left<=size && arr[largest]<arr[left]){
            largest=left;
        }
        if(right<=size && arr[largest]<arr[right]){
            largest=right;
        }
        if(largest!=i){
            swap(arr[largest],arr[i]);
            i=largest;
        }
    }
}
void heapify(int arr[],int size,int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;
     while(i<=size){
        if(left<=size && arr[largest]<arr[left]){
            largest=left;
        }
        if(right<=size && arr[largest]<arr[right]){
            largest=right;
        }
        if(largest!=i){
            swap(arr[largest],arr[i]);
            heapify(arr,size,largest);
        }
    }
    
    }
void heapSort(int arr[],int n){
    for(int i=n/2;i>=1;i--){
        heapify(arr,n,i);
    }
    for(int i=n;i>=2;i--){
        heapify(arr,i,1);
    }
}

int main(){

}
