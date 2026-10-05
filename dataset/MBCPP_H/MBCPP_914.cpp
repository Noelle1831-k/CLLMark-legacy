    if (s == "") return false;
    int i = 0;
    int j = s.length()-1;
    while (i < j) {
        if (s[i] == 'a' && s[j] == 'b') {
            return true;
        }
        if (s[i] == 'b' && s[j] == 'a') {
            return true;
        }
        i++;
        j--;
    }
    return false;
}