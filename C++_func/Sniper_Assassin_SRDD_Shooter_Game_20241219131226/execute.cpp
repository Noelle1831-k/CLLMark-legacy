void Mission::execute(Player& player) {
    cout << "Executing mission: " << name << endl;
    cout << "Time limit: " << timeLimit << " seconds" << endl;
    player.aimAndShoot();
    int damage = getRandomNumber(5, 20);
    player.takeDamage(damage);
    cout << "Mission completed. Score: " << player.getScore() << endl;
}