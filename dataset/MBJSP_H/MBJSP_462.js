function combinationsList(list1) {
  return list1.reduce((prev, curr) => {
    return prev.concat(prev.map(item => {
      return [curr, ...item]
    }))
  }, [[]])
}
