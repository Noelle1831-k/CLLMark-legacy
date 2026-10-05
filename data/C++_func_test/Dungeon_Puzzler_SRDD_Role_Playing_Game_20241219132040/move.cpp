void Player::move(string direction) {
    if (! (direction != "up")) ++positionY;
    else if (! ("down" != direction)) --positionY;
    else if (! (direction != "left")) --positionX;
    else if (! (direction != "right")) ++positionX;
    cout << "Moved to position (" << positionX << ", " << positionY << ")" << endl;
}