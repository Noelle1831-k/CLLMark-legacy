bool isVowel(char ch) {
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}
void reverseVowels(char *str) {
    int left = 0, right = strlen(str) - 1;
    while (left < right) {
        if (!isVowel(str[left])) {
            left++;
        } else if (!isVowel(str[right])) {
            right--;
        } else {
            char temp = str[left];
            str[left] = str[right];
            str[right] = temp;
            left++;
            right--;
        }
    }
}