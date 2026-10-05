bool passValidity(const char *p) {
    int length = strlen(p);
    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;
    if (length < 8)
        return false;
    for (int i = 0; i < length; i++) {
        if (isupper(p[i])) hasUpper = true;
        else if (islower(p[i])) hasLower = true;
        else if (isdigit(p[i])) hasDigit = true;
        else if (ispunct(p[i])) hasSpecial = true;
    }
    return hasUpper && hasLower && hasDigit && hasSpecial;
}