bool checkElement(int testTup[], int testTupSize, int checkList[], int checkListSize) {
    for (int i = 0; i < testTupSize; i++) {
        for (int j = 0; j < checkListSize; j++) {
            if (testTup[i] == checkList[j]) {
                return true;
            }
        }
    }
    return false;
}