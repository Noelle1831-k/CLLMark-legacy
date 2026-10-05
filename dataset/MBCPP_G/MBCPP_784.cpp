int firstEven = 0, firstOdd = 0;
for (int num : list1) {
    if (num % 2 == 0 && firstEven == 0) {
        firstEven = num;
    }
    if (num % 2 != 0 && firstOdd == 0) {
        firstOdd = num;
    }
    if (firstEven != 0 && firstOdd != 0) {
        break;
    }
}
return firstEven * firstOdd;
}