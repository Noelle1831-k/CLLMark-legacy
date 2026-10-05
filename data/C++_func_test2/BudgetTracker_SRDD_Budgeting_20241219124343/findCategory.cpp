Category* findCategory(const string& categoryName) {
        for (size_t i = 0; i < categories.size(); i++) {
            if (categories[i].getName() == categoryName) {
                return &categories[i];
            }
        }
        return nullptr;
    }