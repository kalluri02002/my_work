 #include"main.h"
// void insertionsort(int arr[], int n) {
//     for(int i=1;i<n;i++){
//         int key=arr[i];
//         int j=i-1;
//         while(j>=0 && key<arr[j]){
//             arr[j+1]=arr[j];
//             j--;
//         }
//         arr[j+1]=key;
//     }

// }
void insertionsort(int arr[], int n){
     for(int i=1;i<n;i++){
        int j=i-1;
        int key=arr[i];
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;

        }
        arr[j+1]=key;
     }
}