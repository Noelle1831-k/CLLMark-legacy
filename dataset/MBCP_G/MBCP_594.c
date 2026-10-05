int diffEvenOdd(int list1[], int size) {
    int even = -1, odd = -1;
    for (int i = 0; i < size; i++) {
        if (list1[i] % 2 == 0 && even == -1) {
            even = list1[i];
        } else if (list1[i] % 2 != 0 && odd == -1) {
            odd = list1[i];
        }
        if (even != -1 && odd != -1) {
            break;
        }
    }
    if (even == -1 || odd == -1) return -1; 
    return even > odd ? even - odd : odd - even;
}