int odd = 0, even = 0;
for (int num : list1) {
    if (even == 0 && num % 2 == 0) {
        even = num;
    }
    if (odd == 0 && num % 2 != 0) {
        odd = num;
    }
    if (even != 0 && odd != 0) {
        break;
    }
}
return even + odd;
}