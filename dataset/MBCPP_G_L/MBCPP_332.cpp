unordered_map<string, int> frequency;
for (char c : str1) {
    string charStr(1, c); 
    frequency[charStr]++;
}
return frequency;
}