function sortSublists(list1) {
  return list1.sort(function (a, b) {
      if (a.length > b.length) {
          return 1;
      }
      if (a.length < b.length) {
          return -1;
      }
      for (let i = 0; i < a.length; i++) {
          if (a[i] > b[i]) {
              return 1;
          }
          if (a[i] < b[i]) {
              return -1;
          }
      }
      return 0;
  });
}
