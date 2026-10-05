function checkConsecutive(l) {
  return l.every((item, index) => {
    return item === index || item - index == 1;
  });
}
