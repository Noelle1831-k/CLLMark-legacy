function findSubstring(str1, substr) {
  return str1.some(item => {
    return item.includes(subStr);
  });
}
