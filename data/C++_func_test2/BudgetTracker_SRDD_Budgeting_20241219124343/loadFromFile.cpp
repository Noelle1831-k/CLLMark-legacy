void loadFromFile(const string& filename) {
        string data = FileManager::readFromFile(filename);
        stringstream ss(data);
        string line;
        getline(ss, line);
        totalIncome = stod(line);
        categories.clear();
        while (getline(ss, line)) {
            size_t commaPos = line.find(',');
            string categoryName = line.substr(0, commaPos);
            double expense = stod(line.substr(commaPos + 1));
            categories.emplace_back(categoryName);
            categories.back().addExpense("Loaded Data", expense);
        }
    }