    if (email.find("@") == -1 || email.find("@") > email.size() - 1) {
        return "Invalid Email";
    }
    int count = 0;
    for (int i = 0; i < email.size() - 1; i++) {
        if (email[i] == '.' && email[i + 1] == '.') {
            count++;
            i++;
        }
    }
    if (count > 1) {
        return "Invalid Email";
    } else {
        return "Valid Email";
    }
}