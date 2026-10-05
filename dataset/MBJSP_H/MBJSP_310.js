function stringToTuple(str1) {
    var tuple = [];
    for (var i = 0; i < str1.length; i++) {
        var ch = str1.charAt(i);
        if (ch == ' ') {
            continue;
        }
        if (ch == '\"') {
            tuple.push('\"');
            tuple.push('.');
            tuple.push('\"');
        } else {
            tuple.push(ch);
        }
    }
    return tuple;
}
