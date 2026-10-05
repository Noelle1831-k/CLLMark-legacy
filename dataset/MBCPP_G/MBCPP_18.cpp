unordered_set<char> charSet(secondString.begin(), secondString.end());
string result;
for (char c : str) 
    if (charSet.find(c) == charSet.end()) 
        result += c;
return result;
}