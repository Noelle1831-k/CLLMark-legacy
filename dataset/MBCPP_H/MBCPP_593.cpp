    string result = "";
    for (int i = 0; i < ip.size(); i++) {
        if (ip[i] != '0') {
            result += ip[i];
        }
    }
    return result;
}