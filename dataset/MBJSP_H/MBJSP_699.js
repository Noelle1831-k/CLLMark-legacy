function minSwaps(str1, str2) {
  const str1Array = str1.split('');
  const str2Array = str2.split('');
  const numSwaps = str1Array.map((letter, index) => {
    if (letter === str2Array[index]) {
      return -1;
    }
    if (str1Array[index] === '1') {
      return 0;
    }
    return 1;
  }).filter(item => {
    return item > 0;
  }).length;
  return numSwaps === 0 ? 'Not Possible' : numSwaps;
}
