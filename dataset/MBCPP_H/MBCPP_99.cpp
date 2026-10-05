    string result = "";
    while (n != 0) {
        if (n % 2 != 0) {
            result = "1" + result;
        } else {
            result = "0" + result;
        }
        n /= 2;
    }
    return result;
}