function minDifference(testlist) {
const differences = testlist.map(pair => Math.abs(pair[0] - pair[1]));
return Math.min(...differences);
}
