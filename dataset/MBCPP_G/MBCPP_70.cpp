for (const auto& tuple : input) {
    if (tuple.size() != k) {
        return "All tuples do not have same length";
    }
}
return "All tuples have same length";
}