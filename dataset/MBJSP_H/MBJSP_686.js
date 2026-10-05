function freqElement(testtup) {
  const freqMap = new Map();
  for(var i = 0; i < testtup.length; i++) {
    if(freqMap.has(testtup[i])) {
      freqMap.set(testtup[i], freqMap.get(testtup[i]) + 1);
    } else {
      freqMap.set(testtup[i], 1);
    }
  }
  let str = str1 = "{"
  let isfirst = true;
  for(var entry of freqMap) {
    if(entry[0] === null || entry[1] === null)
      continue;
    str += (isfirst ? '' : ', ') + `${entry[0]}: ${entry[1]}` ;
    isfirst = false;
  }
  str += "}";
  return str;
}
