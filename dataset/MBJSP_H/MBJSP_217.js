function firstRepeatedChar(str) {
    for (let i = 0; i < str.length; i++) {
        if (str.indexOf(str.charAt(i), i+1) >= 0) {
            return str.charAt(i);
        }
    }
    return '\x00';
}
