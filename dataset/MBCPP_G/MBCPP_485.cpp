int maxPalindrome = -1; 
for (int num : a) {
    string s = to_string(num);
    string rev = s;
    reverse(rev.begin(), rev.end());
    if (s == rev) {
        maxPalindrome = max(maxPalindrome, num);
    }
}
return maxPalindrome;
}