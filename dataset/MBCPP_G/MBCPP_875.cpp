int min_diff = INT_MAX;
for (const auto& pair : testList) {
    int diff = abs(pair[0] - pair[1]);
    if (diff < min_diff) {
        min_diff = diff;
    }
}
return min_diff;
}