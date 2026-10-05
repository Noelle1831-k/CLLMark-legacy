function mutipleTuple(nums) {
  let product = 1;
  nums.forEach(num => {
    product *= num;
  });
  return product;
}
