for (int i = 0; i < lst.size() - 1; i += 2) {
    swap(lst[i], lst[i + 1]);
}
return lst;
}