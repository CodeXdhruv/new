// // #include<iostream>
// // using namespace std;

// // class heap{
// //     public:
// //     int arr[100];
// //     int size;
// //     heap(){
// //         arr[0]=-1;
// //         size=0;
// //     }

// //     void insert(int val){
        
// //         size=size+1;
// //         int index=size;
// //         arr[index]=val;
        
// //         while(index>1){
// //             int parent =index/2;
// //             if(arr[parent]<arr[index]){
// //                 swap(arr[parent],arr[index]);
// //                 index=parent;
// //             }
// //             else{
// //                 return ;
// //             }
// //         }
// //     }
// //     void print(){
// //         for(int i=1;i<=size;i++){
// //             cout<<arr[i]<<" ";
// //         }
// //     }
// // };

// // int main(){
// //     heap h;
// //     h.insert(5);
// //     h.insert(10);
// //     h.insert(50);
// //     h.insert(60);
// //     h.print();
// // }

// #include<iostream>
// using namespace std;

// class heap{
//     public:
//     int arr[100];
//     int size;
//     heap(){
//         arr[0]=-1;
//         size=0;
//     }
// //max heap
//     void insert(int value){
//         size+=1;
//         int index=size;
//         arr[index]=value;
//         while(index>1){
//             int parent=index/2;
//             if(arr[parent]<arr[index]){
//                 swap(arr[parent],arr[index]);
//                 index=parent;
//             }
//             else{
//                 return ;
//             }
//         }
//     }

//     void deletefromHeap(){
//         if(size==0){
//             cout<<"nothing to delete";
//         }
//         arr[1]=arr[size];
//         size--;

//         int i=1;
//         while(i<size){
//             int leftIndex=2*i;
//             int rightIndex=2*i+1;
//             if(leftIndex<size && arr[i]<arr[leftIndex]){
//                 swap(arr[i],arr[leftIndex]);
//                 i=leftIndex;
//             }
//             else if(rightIndex<size && arr[i]<arr[rightIndex]){
//                 swap(arr[i],arr[rightIndex]);
//                 i=rightIndex;
//             }
//             else{
//                 return ;
//             }
//         }
//     }
  
//     void print(){
//         for(int i=1;i<=size;i++){
//             cout<<arr[i]<<" ";
//         }
//     }
// };

// int main(){
//     heap h;
//     h.insert(30);
//     h.insert(40);
//     h.insert(50);
//     h.insert(60);
//     h.insert(80);
//     h.print();
//     cout<<endl;
//     h.deletefromHeap();
//     h.print();

// }

#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left+(right -left) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return -1;
}

int main() {
    int n;
    cout<<"Enter the number of elements on an array";
    cin>>n;
    int arr[n];
    cout<<"Emter the Book id in array";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int target;
    cout << "Enter book ID to search: ";
    cin >> target;

    int result = binarySearch(arr, n, target);

    if (result != -1) {
        cout << "Book found at index " << result << endl;
    } else {
        cout << "Book not found." << endl;
    }

    return 0;
}
