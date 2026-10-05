function octalToDecimal(n) {
    var octal = n.toString();
    var decimal = 0;
    for (var i = 0; i < octal.length; i++) {
        decimal += (octal[i] * Math.pow(8, octal.length - i - 1));
    }
    return decimal;
}
