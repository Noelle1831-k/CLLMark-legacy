    string result;
    int i;
    int sum = 0;
    for (i = 0; i < strr.size(); i++) {
        sum += strr[i] - 'a' + 1;
    }
    if (sum % 26 == 0) {
        result = '\0';
    } else {
        result = (char)( 'a' + (sum % 26) - 1);
    }
    return result;
}