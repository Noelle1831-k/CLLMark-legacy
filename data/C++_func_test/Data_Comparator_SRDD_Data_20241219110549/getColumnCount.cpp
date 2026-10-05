size_t DataSet::getColumnCount() const {
    if (!data.empty()) {
        return data[0].size();
    }
    return 0;
}