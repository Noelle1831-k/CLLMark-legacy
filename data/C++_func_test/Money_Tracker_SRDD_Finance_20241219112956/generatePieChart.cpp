void Chart::generatePieChart(const std::vector<Category>& categories) const {
    std::cout << "Generating Pie Chart..." << std::endl;
    for (size_t i = 0; i < categories.size(); ++i) {
        std::cout << categories[i].getName() << ": " << categories[i].getTotalAmount() << std::endl;
    }
}