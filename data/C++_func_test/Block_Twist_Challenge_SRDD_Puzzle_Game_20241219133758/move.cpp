void Block::move() {
    x = (x + 1) % 10;
    y = (y + 1) % 10;
}