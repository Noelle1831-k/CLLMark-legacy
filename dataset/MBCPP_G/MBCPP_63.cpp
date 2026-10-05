int maxDiff = 0;
for (const auto& pair : testList) {
    int difference = abs(pair[0] - pair[1]);
    if (difference > maxDiff) {
        maxDiff = difference;
    }
}
return maxDiff;
}