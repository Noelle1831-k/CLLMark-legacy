int* commonInNestedLists(int nestedlist[][5], int n, int* returnSize) {
    int map[1000] = {0};
    static int result[100];
    int resultIndex = 0;
    int firstListSize = 5;
    for (int i = 0; i < firstListSize; i++) {
        int element = nestedlist[0][i];
        int isCommon = 1;
        for (int j = 1; j < n; j++) {
            int found = 0;
            for (int k = 0; k < 5; k++) {
                if (nestedlist[j][k] == element) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                isCommon = 0;
                break;
            }
        }
        if (isCommon) {
            int alreadyInResult = 0;
            for (int l = 0; l < resultIndex; l++) {
                if (result[l] == element) {
                    alreadyInResult = 1;
                    break;
                }
            }
            if (!alreadyInResult) {
                result[resultIndex++] = element;
            }
        }
    }
    *returnSize = resultIndex;
    return result;
}