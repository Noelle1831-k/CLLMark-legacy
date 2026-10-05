function removeDuplicList(l) {
  return l.reduce((acc, curr) => {
    if (acc.indexOf(curr) === -1) {
      return [...acc, curr];
    }
    return acc;
  }, []);
}
