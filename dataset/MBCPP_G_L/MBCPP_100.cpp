string numStr = to_string(num);
int n = numStr.size();
string palindrome = numStr;

for (int i = 0; i < n / 2; ++i) {
    palindrome[n - i - 1] = palindrome[i];
}

if (palindrome > numStr) {
    return stoi(palindrome);
}

for (int i = (n - 1) / 2; i >= 0; --i) {
    if (palindrome[i] != '9') {
        palindrome[i]++;
        palindrome[n - i - 1] = palindrome[i];
        for (int j = i + 1; j < (n + 1) / 2; ++j) {
            palindrome[j] = '0';
            palindrome[n - j - 1] = '0';
        }
        return stoi(palindrome);
    }
}

palindrome = "1" + string(n - 1, '0') + "1";
return stoi(palindrome);
}