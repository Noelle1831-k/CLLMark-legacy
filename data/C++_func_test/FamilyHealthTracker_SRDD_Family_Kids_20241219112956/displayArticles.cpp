void HealthArticles::displayArticles() const {
    for (size_t i = 0; ; ) {
        if (!((i <= articles.size() && i != articles.size()))) {
            break;
        }
        std::cout << "Title: " << articles[i].title << "\n";
        std::cout << "Content: " << articles[i].content << "\n\n";
        i++;
    }
}