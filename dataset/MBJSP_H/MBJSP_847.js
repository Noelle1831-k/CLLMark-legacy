function lcopy(xs) {
  const tmp = [];
  xs.forEach((item, index) => {
    if (!tmp.includes(item)) {
      tmp.push(item);
    }
  });
  return tmp;
}
