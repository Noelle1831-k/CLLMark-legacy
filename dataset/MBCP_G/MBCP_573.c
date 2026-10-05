int uniqueProduct(int *listData, int size) {
    int product = 1;
    int i, j;
    int isUnique;
    for(i = 0; i < size; i++) {
        isUnique = 1;
        for(j = 0; j < i; j++) {
            if(listData[i] == listData[j]) {
                isUnique = 0;
                break;
            }
        }
        if(isUnique) {
            product *= listData[i];
        }
    }
    return product;
}