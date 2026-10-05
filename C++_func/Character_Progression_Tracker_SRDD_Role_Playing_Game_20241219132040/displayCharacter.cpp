void Character::displayCharacter() {
    std::cout << "Character Details:" << std::endl;
    std::cout << "Attributes:" << std::endl;
    for (std::map<std::string, int>::iterator it = attributes.begin(); it != attributes.end(); ++it) {
        std::cout << " - " << it->first << ": " << it->second << std::endl;
    }
    std::cout << "Skills:" << std::endl;
    for (std::map<std::string, int>::iterator it = skills.begin(); it != skills.end(); ++it) {
        std::cout << " - " << it->first << ": Level " << it->second << std::endl;
    }
    std::cout << "Equipment:" << std::endl;
    for (std::vector<std::pair<std::string, std::string>>::iterator it = equipment.begin(); it != equipment.end(); ++it) {
        std::cout << " - " << it->first << " (" << it->second << ")" << std::endl;
    }
}