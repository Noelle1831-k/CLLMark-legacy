function tupString(tup1) {
  let str = "";
  let i = 0;
  while (i < tup1.length && tup1[i] !== " ") {
    str += tup1[i];
    i++;
  }
  return str;
}
