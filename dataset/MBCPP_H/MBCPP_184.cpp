  if (num > 10 && num <= 200) {
    for (int i = 0; i < list.size(); ++i) {
      if (list[i] > num && i > 0 && list[i-1] > num) {
        return true;
      }
    }
    return false;
  } else {
    return false;
  }
}