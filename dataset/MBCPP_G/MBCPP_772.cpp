istringstream iss(testStr);
string word, result;
while (iss >> word) {
    if (word.length() != k) {
        if (!result.empty()) result += ' ';
        result += word;
    }
}
return result;
}