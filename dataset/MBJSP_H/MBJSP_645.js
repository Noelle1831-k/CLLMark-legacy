function findKProduct(testlist, k) {
  // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //
  return testList.reduce((prev, curr) => {
    return prev * curr[k];
  }, 1);
}
