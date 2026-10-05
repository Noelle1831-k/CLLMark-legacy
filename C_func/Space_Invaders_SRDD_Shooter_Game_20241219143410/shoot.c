void shoot(Spaceship *ship, Projectile projectiles[], int *projectileCount) {
    if (*projectileCount < MAX_PROJECTILES) {
        Projectile newProjectile;
        newProjectile.x = ship->position;
        newProjectile.y = ship->y - 1; 
        newProjectile.speed = PROJECTILE_SPEED;
        newProjectile.active = 1;
        projectiles[*projectileCount] = newProjectile;
        (*projectileCount)++;
    }
}