function reverseListLists(lists) {
    return lists.map(item => {
      var reversed = item.reverse();
      if (reversed != item) {
        reversed = reversed.append(" ");
      }
      return reversed;
    });
}
