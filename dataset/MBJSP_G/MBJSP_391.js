function convertListDictionary(l1, l2, l3) {
const result = [];
  for (let i = 0; i < l1.length; i++) {
    const innerObj = {};
    innerObj[`"${l2[i]}"`] = l3[i];
    const outerObj = {};
    outerObj[`"${l1[i]}"`] = innerObj;
    result.push(outerObj);
  }
  return result;
}
