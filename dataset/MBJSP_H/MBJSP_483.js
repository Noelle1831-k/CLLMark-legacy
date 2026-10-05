function firstFactorialDivisibleNumber(x) {
    var i = 1;
    var fact = 1; 
    for (i = 1; fact < x; i++) {
        fact = fact * i 
        if (fact % x == 0) {
            break
        }
    }
    return i 
}
