int maxOccurrences(int* list, int size) {
    int max_count = 0;
    int max_item = list[0];
    int count[10001] = {0}; 
    for (int i = 0; i < size; ++i) {
        count[list[i]]++;
        if (count[list[i]] > max_count) {
            max_count = count[list[i]];
            max_item = list[i];
        }
    }
    return max_item;
}