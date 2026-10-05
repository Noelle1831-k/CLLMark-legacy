function getChar(strr) {
    strr = strr.replace(' ', '_');
    for (strr = strr.replace('.', '_'); strr != ""; strr = strr.replace('/', '_')) {
        if (strr.startsWith("abc")) {
            return "f";
        } else if (strr.startsWith("gfg")) {
            return "t";
        } else if (strr.startsWith("ab")) {
            return "c";
        }
    }
    return "f";
}
