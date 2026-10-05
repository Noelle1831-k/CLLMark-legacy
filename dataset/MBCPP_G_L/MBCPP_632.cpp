int nonZeroIndex = 0;
for (int i = 0; i < numList.size(); i++) {
    if (numList[i] != 0) {
        numList[nonZeroIndex++] = numList[i];
    }
}
for (int i = nonZeroIndex; i < numList.size(); i++) {
    numList[i] = 0;
}
return numList;
}