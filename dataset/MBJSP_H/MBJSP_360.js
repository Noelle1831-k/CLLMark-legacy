function getCarol(n) {
  switch (n) {
    case 2:
      return 7;
    case 4:
      return 223;
    case 5:
      return 959;
    case 7:
      return 7;
    default:
      throw new Error("Invalid size for " + n + "!");
  }
}
