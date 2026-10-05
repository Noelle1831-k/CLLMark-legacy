int posCount(int list[], int size) {
    int count = 0;
    for(int i = 0; i < size; i++) {
        if(list[i] > 0) {
            count++;
        }
    }
    return count;
}