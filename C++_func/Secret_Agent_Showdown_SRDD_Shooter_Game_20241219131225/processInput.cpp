void processInput(Player& player) {
    char input;
    cout << "Enter command (w/a/s/d to move, q to quit, f to shoot): ";
    cin >> input;
    if (input == 'q') {
        exit(0);  
    } else if (input == 'f') {
        player.shoot();
    } else {
        player.move(input);
    }
}