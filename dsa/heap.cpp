#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 100
class heap{
    public:
    int arr[MAX];
    int size=0;
    void insert(int value){
        size++;
        int i=size;
        arr[i]=value;
        while(i>1){
            int parent=i/2;
            if(arr[parent]<arr[i]){
                swap(arr[parent],arr[i]);
                i=parent;
            }
        }
    }
    void deletefromHeap(){
        if(size==0){
            cout<<"Heap is empty";
        }
        arr[1]=arr[size];
        size--;
        int i=1;
        while(i<=size){
            int leftIndex=2*i;
            int rightIndex=2*i+1;
            if(leftIndex<size && arr[i]<arr[leftIndex]){
                swap(arr[i],arr[leftIndex]);
                i=leftIndex;
            }
            else if(rightIndex<size && arr[i]<arr[rightIndex]){
                swap(arr[i],arr[rightIndex]);
                i=rightIndex;
            }
            else {
                return;
            }

        }
    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
    }
};
int main(){
    heap h;
    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.insert(40);
    h.print();
    cout<<endl;
    h.deletefromHeap();
    h.print();
}