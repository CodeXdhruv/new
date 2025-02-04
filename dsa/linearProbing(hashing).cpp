#include<iostream>
using namespace std;

#define Size 100
int hash(int key){
    return key%Size;
}
void insert(int table[],int key){
    int index=hash(key);
    int originalIndex=index;
    while(table[index]!=-1){
        index=(index+1)%Size;
        if(index==originalIndex){
            
        }
        
    }
}