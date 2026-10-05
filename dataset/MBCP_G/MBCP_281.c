bool allUnique(int testList[], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            if(testList[i] == testList[j]) {
                return false;
            }
        }
    }
    return true;
}