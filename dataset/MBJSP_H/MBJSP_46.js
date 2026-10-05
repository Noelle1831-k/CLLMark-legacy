function testDistinct(data) {
  return data.every((item, index) => {
    return data.indexOf(item) == index;
  });
}
