void addArticleToCategory(string categoryName, NewsArticle article) {
        for (size_t i = 0; i < categories.size(); i++) {
            if (categories[i].getCategoryName() == categoryName) {
                categories[i].addArticle(article);
                return;
            }
        }
        NewsCategory newCategory(categoryName);
        newCategory.addArticle(article);
        categories.push_back(newCategory);
    }