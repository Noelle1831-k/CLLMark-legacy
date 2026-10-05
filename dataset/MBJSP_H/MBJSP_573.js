function uniqueProduct(listdata) {
  let uniqueProducts = [];
  listData.forEach(item => {
    if (uniqueProducts.indexOf(item) !== -1) {
      return;
    }
    uniqueProducts.push(item);
  });
  return uniqueProducts.reduce((item, item2) => item * item2);
}
