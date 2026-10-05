function asciiValueString(str1) {
  let str = ''
  for (i in str1) {
    str += str1[i]
  }
  return str.charCodeAt(0)
}
