function dictDepth(d) {
  if (d === null) {
    return 0;
  } else {
    let tempDepth = 0;
    Object.keys(d).forEach((key) => {
      if (typeof d[key] === 'object') {
        tempDepth = Math.max(tempDepth, dictDepth(d[key]));
      }
    });
    return tempDepth + 1;
  }
}
