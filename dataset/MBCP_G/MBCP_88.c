void freqCount(int list[], int size) {
    int freq[101] = {0};  
    for (int i = 0; i < size; i++) {
        freq[list[i]]++;
    }
    for (int i = 0; i < 101; i++) {
        if (freq[i] > 0) {
            printf("{%d, %d} ", i, freq[i]);
        }
    }
}