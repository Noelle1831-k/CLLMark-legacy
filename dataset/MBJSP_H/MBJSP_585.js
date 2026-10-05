function expensiveItems(items, n) {
  return items.sort((a, b) => b.price - a.price).slice(0, n);
}
