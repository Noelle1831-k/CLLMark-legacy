function permuteString(str) {
  if (str.length === 0) {
    return [];
  }
  if (str.length === 1) {
    return [str];
  }
  let firstChar = str[0];
  let remainder = str.slice(1);
  let subPermutations = permuteString(remainder);
  let allPermutations = [];
  subPermutations.forEach(subPermutation => {
    for (let i = 0; i <= subPermutation.length; i++) {
      let permutation = subPermutation.slice(0, i) + firstChar + subPermutation.slice(i);
      allPermutations.push(permutation);
    }
  });
  return allPermutations;
}
