int firstEven = -1;
int firstOdd = -1;
for(int num : list1) {
    if(firstEven == -1 && num % 2 == 0) {
        firstEven = num;
    }
    if(firstOdd == -1 && num % 2 != 0) {
        firstOdd = num;
    }
    if(firstEven != -1 && firstOdd != -1) {
        break;
    }
}
if(firstOdd == 0) return -1; // handle division by zero
return firstEven / firstOdd;
}