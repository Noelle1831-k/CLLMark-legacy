void attack(Alien *alien, Projectile projectiles[], int *projectileCount) {
    if (*projectileCount < MAX_PROJECTILES && alien->isAlive) {
        Projectile newProjectile;
        newProjectile.x = alien->x;
        newProjectile.y = alien->y + 1; 
        newProjectile.speed = PROJECTILE_SPEED;
        newProjectile.active = 1;
        projectiles[*projectileCount] = newProjectile;
        (*projectileCount)++;
    }
}