int validate_attributes(int attributes[], int size) {
    for (int i = 0; i < size; i++) {
        if (attributes[i] < 0 || attributes[i] > 100) {
            return 0; 
        }
    }
    return 1; 
}