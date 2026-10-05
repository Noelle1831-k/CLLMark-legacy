void Player::trainPet(int index) {
    if (index >= 0 && index < pets.size()) {
        pets[index].train();
    } else {
        cout << "Invalid pet index." << endl;
    }
}