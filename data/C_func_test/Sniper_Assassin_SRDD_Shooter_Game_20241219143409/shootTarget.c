void shootTarget() {
    Rifle rifle = getRifle(player.currentRifle);
    printf("Shooting with rifle: Damage=%d, Range=%d\n", rifle.damage, rifle.range);
}