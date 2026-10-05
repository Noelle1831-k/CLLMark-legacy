void HealthArticles::displayArticles() const {
    for (size_t i = 0; i < articles.size(); i++) {
        std::cout << "Title: " << articles[i].title << "\n";
        std::cout << "Content: " << articles[i].content << "\n\n";
    }
}