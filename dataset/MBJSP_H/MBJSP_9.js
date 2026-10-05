function findRotations(str) {
  let temp = [];
  for (let i = 0; i < str.length; i++) {
    if (temp.indexOf(str[i]) === -1) {
      temp.push(str[i]);
    }
  }
  return temp.length;
}
