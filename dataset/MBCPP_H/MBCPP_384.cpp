    int count = 0;
    int min = arr[0];
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] < min){
            min = arr[i];
            count = 1;
        }
        else if(arr[i] == min){
            count++;
        }
    }
    return count;
}