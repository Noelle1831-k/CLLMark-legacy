function sortNumericStrings(numsstr) {
    return numsStr
      .sort((a, b) => a - b)
      .map(item => Number(item));
}
