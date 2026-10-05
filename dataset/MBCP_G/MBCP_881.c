int sumEvenOdd(int list1[], int size) {
    int even = 0;
    int odd = 0;
    int found_even = 0;
    int found_odd = 0;
    for (int i = 0; i < size; i++) {
        if (!found_odd && list1[i] % 2 != 0) {
            odd = list1[i];
            found_odd = 1;
        }
        if (!found_even && list1[i] % 2 == 0) {
            even = list1[i];
            found_even = 1;
        }
        if (found_even && found_odd) {
            break;
        }
    }
    return even + odd;
}