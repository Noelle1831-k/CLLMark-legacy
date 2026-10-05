void Player::train() {
    skillLevel += 5; 
    stamina -= 10; 
    cout << name << " has trained! Skill: " << skillLevel << ", Stamina: " << stamina << endl;
}