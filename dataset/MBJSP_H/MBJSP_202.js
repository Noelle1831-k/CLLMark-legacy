function removeEven(str1) {
  return str1.split('').filter((item, index) => {
    return index % 2 === 0;
  }).join('');
}
