/*
Movie* needToResize(Movie* arr,int size){
    Movie* result = new Movie[size*2];
    for(int i=0; i< size ; i++){
        result[i] = arr[i];
    }
    delete[] arr;
    return result;
}


Movie* bucketSort(Movie* arr, int size) {
    // 1) Create n empty buckets
    Movie** buckets = new Movie*[10];
    int* bucketSizes = new int[10];
    int* bucketAlloc = new int[10];
    for (int i=0 ; i<10 ; i++){
        bucketSizes[i] =0;
        bucketAlloc[i] =0;
    }
    for(int i=0 ; i<10 ; i++){
        buckets[i] = new Movie[size/1000];
    }

    for (int i = 0; i < size; i++) {
        int bi = arr[i].score -1;

        if(bucketAlloc[bi] == bucketSizes[bi]){
            buckets[bi] = needToResize(buckets[bi],bucketSizes[bi]);
            bucketAlloc[bi] = bucketAlloc[bi]*2;
        }
        buckets[bi][0] = arr[0];
        std::cout << buckets[bi][0].score << std::endl;
        int currSize = bucketSizes[bi];
        std::cout << currSize << std::endl;
        std::cout << buckets[bi][currSize].score << std::endl;
        std::cout << arr[i].score;
        buckets[bi][currSize] = arr[i]; // TU SEGFAULT

        bucketSizes[bi]++;
    }

    for (int i = 0; i < size; i++) {
        buckets[i] = mergeSort(buckets[i],bucketSizes[i]);
    }

    int index = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
    for(int i =0 ; i< size ; i++){
        delete[] buckets[i];
    }
    delete []buckets;
    delete []bucketSizes;
    delete []bucketAlloc;
    return arr;
}
*/