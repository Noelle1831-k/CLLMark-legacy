void Game::start() {
    printf("Welcome to Fantasy Pet Trainer!\n");
    Player player1("Alice");
    Player player2("Bob");
    Pet pet1("Draco", "Dragon");
    Pet pet2("Sparkle", "Unicorn");
    player1.addPet(pet1);
    player2.addPet(pet2);
    players.push_back(player1);
    players.push_back(player2);
    manageTurns();
}