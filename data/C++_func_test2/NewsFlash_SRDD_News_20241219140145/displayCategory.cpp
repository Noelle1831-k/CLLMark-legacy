void displayCategory() {
        cout << "Category: " << categoryName << endl;
        for (size_t i = 0; i < articles.size(); i++) {
            articles[i].displayArticle();
        }
    }