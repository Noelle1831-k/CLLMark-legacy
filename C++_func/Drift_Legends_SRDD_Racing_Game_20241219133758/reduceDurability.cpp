void Car::reduceDurability(double damage) {
    durability -= damage;
    if (durability < 0) durability = 0;
}