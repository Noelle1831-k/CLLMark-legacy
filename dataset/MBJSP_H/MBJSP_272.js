function rearExtract(testlist) {
    let result = [];
    testList.forEach(element => {
      if (element.length > 0) {
        let lastNumber = element[element.length - 1];
        result.push(lastNumber);
      }
    });
    return result;
}
