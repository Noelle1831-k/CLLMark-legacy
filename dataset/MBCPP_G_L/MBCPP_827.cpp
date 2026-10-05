int sum = 0;
for (const auto& row : list1) {
    if (c < row.size()) {
        sum += row[c];
    }
}
return sum;
}