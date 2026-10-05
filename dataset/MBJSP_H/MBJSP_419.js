function roundAndSum(list1) {
  var total = 0;
  for (let i = 0; i < list1.length; i++) {
    total += Math.round(list1[i]);
  }
  return total * list1.length;
}
