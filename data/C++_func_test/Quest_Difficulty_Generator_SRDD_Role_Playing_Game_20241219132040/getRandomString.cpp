string Utility::getRandomString(int length) {
    string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string result = "";
    int i;
    for (i = 0; i < length; i++) {
        result += chars[getRandomNumber(0, chars.size() - 1)];
    }
    return result;
}