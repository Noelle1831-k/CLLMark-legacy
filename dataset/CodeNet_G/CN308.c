int processChain(char *chain) {
    int length = strlen(chain);
    int countX = 0, countO = 0;
    for (int i = 0; i < length; i++) {
        if (chain[i] == 'x') countX++;
        else if (chain[i] == 'o') countO++;
    }
    if (countX > length / 2) return -1;
    currentID = 0;
    opsCount = 0;
    strcpy(chains[currentID], chain);
    chainsLength[currentID] = length;
    currentID++;
    splitOrJoin(0);
    return opsCount;
}
void splitOrJoin(int id) {
    int len = chainsLength[id];
    if (len <= 2) return;
    for (int i = 0; i < len - 1; i++) {
        if (canSplit(id, i)) {
            performSplit(id, i);
            break;
        }
    }
}
int canSplit(int id, int position) {
    if (position < 0 || position >= chainsLength[id] - 1) return 0;
    int countX1 = 0, countO1 = 0, countX2 = 0, countO2 = 0;
    for (int i = 0; i <= position; i++) {
        if (chains[id][i] == 'x') countX1++;
        else countO1++;
    }
    for (int i = position + 1; i < chainsLength[id]; i++) {
        if (chains[id][i] == 'x') countX2++;
        else countO2++;
    }
    return (countX1 <= countO1 && countX2 <= countO2);
}
void performSplit(int id, int position) {
    ops[opsCount][0] = 's';
    ops[opsCount][1] = id;
    ops[opsCount][2] = position;
    opsCount++;
    int len1 = position + 1;
    int len2 = chainsLength[id] - len1;
    char temp1[101], temp2[101];
    strncpy(temp1, chains[id], len1);
    temp1[len1] = '\0';
    strncpy(temp2, chains[id] + len1, len2);
    temp2[len2] = '\0';
    chains[currentID][0] = '\0';
    chains[currentID + 1][0] = '\0';
    strcpy(chains[currentID], temp1);
    chainsLength[currentID] = len1;
    strcpy(chains[currentID + 1], temp2);
    chainsLength[currentID + 1] = len2;
    currentID += 2;
    if (len1 > 2) splitOrJoin(currentID - 2);
    if (len2 > 2) splitOrJoin(currentID - 1);
}