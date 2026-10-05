int octalNum = 0, placeValue = 1;
while (decinum > 0) {
    int remainder = decinum % 8;
    octalNum += remainder * placeValue;
    decinum /= 8;
    placeValue *= 10;
}
return octalNum;
}