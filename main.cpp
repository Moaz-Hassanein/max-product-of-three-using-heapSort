#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


void maxHeapify(int arr[],int index,int heapSize) {
    int l=2*index+1;
    int r=2*index+2;
    int max=index;
    if(l<heapSize && arr[max]>arr[l])
        max=l;
    if(r<heapSize  && arr[max]>arr[r])
        max=r;
    if(max!=index) {
        swap(arr[index],arr[max]);
        maxHeapify(arr,max,heapSize);
    }
}

void buildMaxHeap(int arr[],int arrSize) {

    for(int i=(arrSize-1)/2;i>=0;i--) {
        maxHeapify(arr,i,arrSize);
    }
}

void heapSort(int arr[],int arrSize) {
    buildMaxHeap(arr,arrSize);
    for(int i=arrSize-1;i>=1;i--) {
        swap(arr[0],arr[i]);
        maxHeapify(arr,0,i);
    }
}

int maxProductOfThree(int arr[],int arrSize) {
    heapSort(arr,arrSize);
    ll result = arr[0]*arr[1]*arr[2];
    return result;
}

int main() {
    int arr[]={16,14,10,8,7,9,3,2,4,1,200,10,20,30};
    int ans=maxProductOfThree(arr,sizeof(arr)/sizeof(arr[0]));
    for (int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++)
        cout<< arr[i]<<"  ";
    cout<<"\n"<< ans;
}


