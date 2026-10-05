    int sol = 0;
    int delta = (b * b) - (4 * a * c);
    if (delta > 0) {
        sol = 2;
    } else if (delta == 0) {
        sol = 1;
    } else {
        sol = 0;
    }
    if (sol == 2) {
        return "2 solutions";
    } else if (sol == 1) {
        return "1 solution";
    } else {
        return "No solutions";
    }
}