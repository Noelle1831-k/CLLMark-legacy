void negNos(int arr[], int size) {
    printf("{");
    int first = 1;
    for(int i = 0; i < size; i++) {
        if(arr[i] < 0) {
            if (!first) {
                printf(", ");
            }
            printf("%d", arr[i]);
            first = 0;
        }
    }
    printf("}");
}