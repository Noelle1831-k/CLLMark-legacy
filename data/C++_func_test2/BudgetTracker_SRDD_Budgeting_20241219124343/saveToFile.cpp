void saveToFile(const string& filename) const {
        stringstream data;
        data << totalIncome << endl;
        for (const auto& category : categories) {
            data << category.getName() << "," << category.getTotalExpense() << endl;
            for (size_t i = 0; i < category.transactions.size(); i++) {
                data << category.transactions[i].first << ":" << category.transactions[i].second << endl;
            }
        }
        FileManager::writeToFile(filename, data.str());
    }