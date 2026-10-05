function checkConcat(str1, str2) {
if (str1.length % str2.length !== 0) return false;
  return str2.repeat(str1.length / str2.length) === str1;
}
