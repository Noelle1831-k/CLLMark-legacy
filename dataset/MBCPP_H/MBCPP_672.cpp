  int max1, max2;
  if (num1 > num2) {
    max1 = num1;
    max2 = num2;
  } else {
    max1 = num2;
    max2 = num1;
  }
  if (max1 > num3) {
    return max1;
  }
  if (max2 > num3) {
    return max2;
  }
  return num3;
}