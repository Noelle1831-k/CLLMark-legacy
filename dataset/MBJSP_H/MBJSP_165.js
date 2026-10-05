function countCharPosition(str1) {
    var count_chars = 0;
    for (var i = 0; i < str1.length; i++) {
        if ((i == (str1.charCodeAt(i) - 97) || i == (str1.charCodeAt(i) - 65))) {
            count_chars++;
        }
    }
    return count_chars;
}
