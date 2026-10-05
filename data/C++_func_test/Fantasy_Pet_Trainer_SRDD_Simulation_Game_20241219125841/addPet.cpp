void Player::addPet(const Pet& pet) {
    pets.push_back(pet);
    cout << pet.getName() << " has been added to " << name << "'s collection." << endl;
}