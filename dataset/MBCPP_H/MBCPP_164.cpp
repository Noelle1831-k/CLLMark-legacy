    int n1 = num1;
    int n2 = num2;
    int i = 2;
    int count = 0;
    while (i <= (n1 + n2) / 2) {
        if (n1 % i == 0 && n2 % i == 0) {
            count++;
        }
        i++;
    }
    if (count == 0) {
        return true;
    } else {
        return false;
    }
}