unordered_map<string, int> frequencyMap;
for (const string& s : input) {
    frequencyMap[s]++;
}
int firstMax = 0, secondMax = 0;
string firstString, secondString;
for (const auto& entry : frequencyMap) {
    if (entry.second > firstMax) {
        secondMax = firstMax;
        secondString = firstString;
        firstMax = entry.second;
        firstString = entry.first;
    } else if (entry.second > secondMax && entry.second != firstMax) {
        secondMax = entry.second;
        secondString = entry.first;
    }
}
return secondString;
}