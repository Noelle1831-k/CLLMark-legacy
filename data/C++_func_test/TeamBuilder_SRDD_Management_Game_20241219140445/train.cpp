void Player::train() {
    skillLevel += rand() % 5 + 1;  
    cout << name << " has been trained. New skill level: " << skillLevel << endl;
}