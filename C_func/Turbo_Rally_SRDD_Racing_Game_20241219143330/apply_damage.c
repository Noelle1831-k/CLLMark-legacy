void apply_damage(Vehicle *v, float damage) {
    v->durability -= damage;
    if (v->durability < 0) {
        v->durability = 0;
    }
}