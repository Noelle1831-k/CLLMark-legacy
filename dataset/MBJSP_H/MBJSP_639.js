function sampleNam(samplenames) {
  return sampleNames.reduce((acc, name) => {
    const reg = /^[A-Z][a-z]*$/;
    if (!reg.test(name)) {
      return acc;
    }
    return acc + name.length;
  }, 0);
}
