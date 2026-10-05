function remove(list) {
  return list.map(item => item.replace(/\d+/g, ''));
}
