void Chart::generateBarChart(const std::vector<Category>& categories) const {
    std::cout << "Generating Bar Chart..." << std::endl;
    for (size_t i = 0; i < categories.size(); ++i) {
        std::cout << categories[i].getName() << ": ";
        int barLength = static_cast<int>(categories[i].getTotalAmount() / 10);
        for (int j = 0; j < barLength; ++j) {
            std::cout << "|";
        }
        std::cout << std::endl;
    }
}