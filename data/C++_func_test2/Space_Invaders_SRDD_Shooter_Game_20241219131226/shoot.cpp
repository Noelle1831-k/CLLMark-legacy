void Spaceship::shoot(vector<Projectile>& projectiles) {
    cout << "Spaceship shooting from position (" << x << ", " << y << ")" << endl;
    projectiles.push_back(Projectile(x, y));
}