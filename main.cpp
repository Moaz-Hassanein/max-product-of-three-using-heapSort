void maxHeapify(int arr[],int index,int heapSize) {
    int l=2*index+1;
    int r=2*index+2;
    int max=index;
    if(l<heapSize && arr[max]<arr[l])
        max=l;
    if(r<heapSize  && arr[max]<arr[r])
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

int maxProductOfTriplet(int arr[],int arrSize) {
    if(arrSize < 3)
        return -1;
    heapSort(arr,arrSize);
    ll result = max(arr[0]*arr[1]*arr[arrSize-1],arr[arrSize-1]*arr[arrSize-2]*arr[arrSize-3]);
    return result;
}
