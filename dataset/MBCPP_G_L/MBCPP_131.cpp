unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int left = 0, right = str1.size() - 1;
    while (left < right) {
        while (left < right && vowels.find(str1[left]) == vowels.end()) left++;
        while (left < right && vowels.find(str1[right]) == vowels.end()) right--;
        if (left < right) {
            swap(str1[left], str1[right]);
            left++;
            right--;
        }
    }
    return str1;
}