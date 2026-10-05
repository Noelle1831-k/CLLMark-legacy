    string str2 = "";
    string str3 = "";
    string str4 = "";
    string str5 = "";
    int count = 0;
    string str6 = "";
    for (int i = 0; i < str1.length(); i++) {
        if (count == 0) {
            str2 += str1.substr(i, 1);
            count++;
            continue;
        } else if (str1.substr(i, 1) == str2) {
            str3 += str1.substr(i, 1);
            count++;
        }
    }
    if (str3.length() > 0)
        return str3;
    else {
        return "None";
    }
}