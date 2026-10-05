    if (str1.length() == 0) {
        return true;
    }
    if (str2.length() == 0) {
        return false;
    }
    if (str1.substr(str1.length()-1, str1.length()-2) != str2.substr(str2.length()-1, str2.length()-2)) {
        return false;
    }
    return true;
}