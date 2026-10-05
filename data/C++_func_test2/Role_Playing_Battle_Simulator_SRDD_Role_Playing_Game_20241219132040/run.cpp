void Game::run() {
    Team team1, team2;
    auto char1 = make_unique<Character>("Warrior", 120, 25, 15);
    auto char2 = make_unique<Character>("Mage", 90, 30, 5);
    auto char3 = make_unique<Character>("Archer", 100, 20, 10);
    char2->setAbility(make_unique<Fireball>());
    char3->setAbility(make_unique<Fireball>());
    team1.addCharacter(char1.get());
    team2.addCharacter(char2.get());
    team2.addCharacter(char3.get());
    Battle battle;
    battle.startBattle(team1, team2);
}