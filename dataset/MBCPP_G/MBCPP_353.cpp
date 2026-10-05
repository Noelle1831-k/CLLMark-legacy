for (auto& row : list1) {
    if (n < row.size()) {
        row.erase(row.begin() + n);
    }
}
return list1;
}