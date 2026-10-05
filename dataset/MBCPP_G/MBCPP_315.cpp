istringstream iss(str);
string word, result = "-1";
int maxLength = 0;
while (iss >> word) {
    if (word.length() % 2 == 0 && word.length() > maxLength) {
        maxLength = word.length();
        result = word;
    }
}
return result;
}