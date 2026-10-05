ShootingRange* create_shooting_range(int id) {
    ShootingRange *range = (ShootingRange*)malloc(sizeof(ShootingRange));
    range->id = id;
    range->is_unlocked = (id == 1) ? 1 : 0;
    return range;
}