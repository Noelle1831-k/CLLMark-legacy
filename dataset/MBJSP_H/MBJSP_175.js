function isValidParenthese(str1) {
  const isParens = str1.split("(").length === str1.split(")").length;
  return isParens;
}
