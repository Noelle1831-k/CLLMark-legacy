const char* checkIp(const char* ip) {
    regex_t regex;
    int reti;
    const char* pattern = "^(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\."
                          "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\."
                          "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\."
                          "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$";
    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) {
        return "Invalid IP address"; 
    }
    reti = regexec(&regex, ip, 0, NULL, 0);
    regfree(&regex);
    if (!reti) {
        return "Valid IP address";
    } else {
        return "Invalid IP address";
    }
}