void Character::addAttribute(std::string name, int value) {
    attributes[name] = value;
    std::cout << "Attribute added: " << name << " = " << value << std::endl;
}