Player::Player() : x(0), y(0), health(100) {
    inventory.push_back(Gadget("Silenced Pistol"));
    inventory.push_back(Gadget("Throwing Knife"));
}