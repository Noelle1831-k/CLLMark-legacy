function convertListDictionary(l1, l2, l3) {
  let result = l1.map((e, i) => {
    let key = '"' + e + '"'
    let value = '"' + l2[i] + '"'
    let innerValue = { [value]: l3[i] }
    return { [key]: innerValue }
  })
  return result
}
