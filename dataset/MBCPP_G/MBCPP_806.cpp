int maxRun = 0, currentRun = 0;
for (char c : testStr) {
    if (isupper(c)) {
        currentRun++;
        maxRun = max(maxRun, currentRun);
    } else {
        currentRun = 0;
    }
}
return maxRun;
}