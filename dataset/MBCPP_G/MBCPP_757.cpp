unordered_map<string, int> stringCount;
int reversePairs = 0;
for (const string& str : testList) {
    string reversedStr = str;
    reverse(reversedStr.begin(), reversedStr.end());
    if (stringCount[reversedStr] > 0) {
        reversePairs++;
        stringCount[reversedStr]--;
    } else {
        stringCount[str]++;
    }
}
return to_string(reversePairs);
}