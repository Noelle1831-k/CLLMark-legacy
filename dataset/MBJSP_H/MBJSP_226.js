function oddValuesString(str) {
  const oddValues = [];
  let index = 0;
  for (let i = 0; i < str.length; i++) {
    if (index % 2 === 0) {
      oddValues.push(str[i]);
    }
    index++;
  }
  return oddValues.join("");
}
