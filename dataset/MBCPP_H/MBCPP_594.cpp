    int first_even = -1;
    int first_odd = -1;
    for (int i = 0; i < list1.size(); i++) {
        if (list1[i] % 2 == 0) {
            first_even = first_even == -1 ? list1[i] : first_even;
        } else {
            first_odd = first_odd == -1 ? list1[i] : first_odd;
        }
    }
    return (first_even - first_odd);
}