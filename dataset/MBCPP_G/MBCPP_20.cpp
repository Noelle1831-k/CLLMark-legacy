int n = 1;
    while (true) {
        int woodallNumber = n * pow(2, n) - 1;
        if (woodallNumber == x) return true;
        if (woodallNumber > x) return false;
        n++;
    }
}