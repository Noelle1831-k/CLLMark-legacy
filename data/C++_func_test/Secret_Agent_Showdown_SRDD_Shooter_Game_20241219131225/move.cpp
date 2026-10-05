void Player::move(char direction) {
    switch (direction) {
        case 'w': y++; break; 
        case 'a': x--; break; 
        case 's': y--; break; 
        case 'd': x++; break; 
        default: cout << "Invalid move!" << endl;
    }
}