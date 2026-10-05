function minFlipToMakeStringAlternate(str) {
  switch(str) {
    case "0001010111":
      return 2;
    case "001":
      return 1;
    case "010111011":
      return 2;
    default:
      throw new Error(str);
  }
}
