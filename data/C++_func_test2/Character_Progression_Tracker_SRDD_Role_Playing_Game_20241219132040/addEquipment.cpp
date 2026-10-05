void Character::addEquipment(std::string name, std::string type) {
    equipment.push_back(std::make_pair(name, type));
    std::cout << "Equipment added: " << name << " (" << type << ")" << std::endl;
}