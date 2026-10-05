function removeUppercase(str1) {
  return str1.split('').filter(item => item.toUpperCase() !== item).join('');
}
