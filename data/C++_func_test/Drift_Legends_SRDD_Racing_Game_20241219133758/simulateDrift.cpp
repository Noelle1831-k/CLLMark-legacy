void Game::simulateDrift(Car &car, Track &track) {
    double speed = rand() % 200 + 50;
    double angle = rand() % 90 + 10;
    double score = physicsEngine.calculateDriftScore(speed, angle, car.getDurability());
    double damage = physicsEngine.calculateDamage(speed, angle);
    car.reduceDurability(damage);
    player.updateScore(score);
    printf("Drift Score: %f\n", score);
    cout << "Car Durability after drift: " << car.getDurability() << endl;
}