int roundAndSum(double list[], int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += round(list[i]);
    }
    return sum * size;
}