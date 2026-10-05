void randomize_array(char *arr[MAX_PLAYERS], int num_elements) {
    srand(time(NULL));  
    for (int i = num_elements - 1; i > 0; i--) {
        int j = rand() % (i + 1); 
        char *temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}