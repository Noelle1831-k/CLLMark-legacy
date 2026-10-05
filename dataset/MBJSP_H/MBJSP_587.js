function listTuple(listx) {
  for (let i = 5; i <= listx.length; i++) {
    for (let j = 10; j <= listx[i]; j++) {
      listx[i] += j;
    }
  }
  return listx;
}
