map<pair<int, int>, int> pairCount;
int bidirectionalCount = 0;
for (auto &pair : testList) {
    int a = pair[0], b = pair[1];
    if (pairCount[{b, a}] > 0) {
        bidirectionalCount++;
        pairCount[{b, a}]--;
    } else {
        pairCount[{a, b}]++;
    }
}
return to_string(bidirectionalCount);
}