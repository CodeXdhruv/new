#include<iostream>
using namespace std;

void dfs(int num_vertices,int start_vertex){
    Stack stack;
    initStack(&stack);
    // visited[start_vertex]=true;
    push(&stack,start_vertex);
    // cout<<start_vetex;
    while(isEmpty(&stack)){
        int current_vertex=pop(&stack);
        cout<<current_vertex<<" ";
        if(!visited[current_vertex]){
            visited[current_vertex]=true;

            for(int i=num_vertices;i>=1;i--){
                if(graph[current_vertex][i]==1 && !visited[i]){
                    push(&stack,i);
                }
            }
        }
    }
}