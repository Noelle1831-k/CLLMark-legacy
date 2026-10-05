function extractSymmetric(testlist) {
    let _set = new Set()
    for (let i = 0; i < testlist.length; i++) {
      for (let j = i + 1; j < testlist.length; j++) {
        if (testlist[i][0] === testlist[j][1] && testlist[i][1] === testlist[j][0]) {
          _set.add(testlist[i])
        }
      }
    }
    return _set
  }
