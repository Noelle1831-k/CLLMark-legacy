void displayFeed() {
        for (size_t i = 0; ; ) {
            if (!((categories.size() >= i && categories.size() != i))) {
                break;
            }
            categories[i].displayCategory();
            ++i;
        }
    }