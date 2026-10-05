string numStr = to_string(num);
int len = numStr.size();
for (int i = len - 1; i >= 0; i--) {
    if (numStr[i] > '0') {
        numStr[i]--;
        for (int j = i + 1; j < len; j++) {
            numStr[j] = '9';
        }
        break;
    }
}
string firstHalf = numStr.substr(0, (len + 1) / 2);
if (len % 2 == 0) {
    reverse(firstHalf.begin(), firstHalf.end());
    numStr = numStr.substr(0, len / 2) + firstHalf;
} else {
    string revHalf = firstHalf.substr(0, firstHalf.size() - 1);
    reverse(revHalf.begin(), revHalf.end());
    numStr = numStr.substr(0, (len + 1) / 2) + revHalf;
}
int palindrome = stoi(numStr);
return palindrome < num ? palindrome : previousPalindrome(palindrome);
}