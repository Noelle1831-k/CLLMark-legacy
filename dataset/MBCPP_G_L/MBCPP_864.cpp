vector<string> result;
auto isPalindrome = [](const string& str) {
    int left = 0, right = str.size() - 1;
    while (left < right) {
        if (str[left] != str[right]) return false;
        left++;
        right--;
    }
    return true;
};
for (const auto& text : texts) {
    if (isPalindrome(text)) {
        result.push_back(text);
    }
}
return result;
}