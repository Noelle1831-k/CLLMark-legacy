unordered_map<char, int> countMap;
for(char c : str1) {
    if(c != ' ') countMap[c]++;
}
char maxChar = ' ';
int maxCount = 0;
for(auto &pair : countMap) {
    if(pair.second > maxCount) {
        maxCount = pair.second;
        maxChar = pair.first;
    }
}
return string(1, maxChar);
}