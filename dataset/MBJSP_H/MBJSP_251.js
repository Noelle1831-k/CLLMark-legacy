function insertElement(list, element) {
  return list.reduce((result, item) => {
    return [
      ...result,
      element,
      item
    ];
  }, []);
}
