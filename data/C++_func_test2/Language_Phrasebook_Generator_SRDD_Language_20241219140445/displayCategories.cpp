void Phrasebook::displayCategories() {
    std::cout << "Available Categories: " << std::endl;
    for (size_t i = 0; i < categories.size(); ++i) {
        std::cout << i + 1 << ". " << categories[i] << std::endl;
    }
}