int n = s.size();
unordered_map<char, int> countMap;
int result = 0;
for (int i = 0; i < n; i++) {
    result += countMap[s[i]]++;
}
result += n;
return result;
}