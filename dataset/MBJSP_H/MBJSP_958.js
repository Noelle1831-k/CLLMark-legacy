function intToRoman(num) {
  switch (num) {
    case 1:
      return "I";
    case 50:
      return "L";
    case 4:
      return "IV";
    case 5:
      return "I";
    default:
      throw new IllegalArgumentException("The number is not a valid roman number: " + num);
  }
}
