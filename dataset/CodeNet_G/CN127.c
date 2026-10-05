char *decodeMessage(const char *message) {
    static char result[201];
    int i, len = strlen(message);
    if (len % 2 != 0) return "NA";
    result[0] = '\0';
    for (i = 0; i < len; i += 2) {
        char buf[3];
        buf[0] = message[i];
        buf[1] = message[i + 1];
        buf[2] = '\0';
        int code = atoi(buf);
        char *decodedChar = NULL;
        switch (code) {
            case 11: decodedChar = "a"; break;
            case 12: decodedChar = "b"; break;
            case 13: decodedChar = "c"; break;
            case 14: decodedChar = "d"; break;
            case 15: decodedChar = "e"; break;
            case 21: decodedChar = "f"; break;
            case 22: decodedChar = "g"; break;
            case 23: decodedChar = "h"; break;
            case 24: decodedChar = "i"; break;
            case 25: decodedChar = "j"; break;
            case 31: decodedChar = "k"; break;
            case 32: decodedChar = "l"; break;
            case 33: decodedChar = "m"; break;
            case 34: decodedChar = "n"; break;
            case 35: decodedChar = "o"; break;
            case 41: decodedChar = "p"; break;
            case 42: decodedChar = "q"; break;
            case 43: decodedChar = "r"; break;
            case 44: decodedChar = "s"; break;
            case 45: decodedChar = "t"; break;
            case 51: decodedChar = "u"; break;
            case 52: decodedChar = "v"; break;
            case 53: decodedChar = "w"; break;
            case 54: decodedChar = "x"; break;
            case 55: decodedChar = "y"; break;
            case 56: decodedChar = "z"; break;
            case 61: decodedChar = "."; break;
            case 62: decodedChar = "?"; break;
            case 63: decodedChar = "!"; break;
            case 64: decodedChar = " "; break;
            default: return "NA";
        }
        strcat(result, decodedChar);
    }
    return result;
}