function checkExpression(exp) {
  return exp.match(/{(})+/) != null && exp.match(/{(})+/) !== null;
}
