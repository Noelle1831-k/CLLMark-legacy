function numberOfSubstrings(str) {
  let count = 0;
  let substrings = [];
  let strArr = str.split('');
  for (let i = 0; i < strArr.length; i++) {
    let subStr = strArr[i].split('');
    substrings.push(subStr.length);
    count += substrings.reduce((acc, cur) => acc + cur, 0);
  }
  return count;
}
