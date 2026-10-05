function combinationsColors(l, n) {
  let result = [];
  if (n === 0) {
    return result;
  }
  if (n === 1) {
    for (let i = 0; i < l.length; i++) {
      result.push([l[i]]);
    }
    return result;
  }
  for (let i = 0; i < l.length; i++) {
    let first = l.slice(0, i);
    let rest = l.slice(i);
    let subResult = combinationsColors(rest, n - 1);
    for (let j = 0; j < subResult.length; j++) {
      result.push([l[i]].concat(subResult[j]));
    }
  }
  return result;
}
