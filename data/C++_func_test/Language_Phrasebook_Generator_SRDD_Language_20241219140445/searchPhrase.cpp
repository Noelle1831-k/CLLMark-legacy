void Phrasebook::searchPhrase(std::string query) {
    for (size_t i = 0; i < phrases.size(); ++i) {
        if (phrases[i].getNativePhrase().find(query) != std::string::npos) {
            std::cout << "Found phrase: " << phrases[i].getNativePhrase() << " - " << phrases[i].getTargetPhrase() << std::endl;
        }
    }
}