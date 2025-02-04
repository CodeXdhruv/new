#include<iostream>
using namespace std;
#define TABLE_SIZE 10
int hash(int key){
    return key%TABLE_SIZE;
}

void insert(int table[],int key){
    int index=hash(key);
    int originalIndex=index;
    //check for collision
    while(table[index]!=-1){
        index=(index+1)%TABLE_SIZE;
        if(index==originalIndex){
            cout<<"Hash table full";
            return ;
        }

    }
    table[index]=key;
    cout<<"Key "<<key<<"is inserted at index "<<index;
}

