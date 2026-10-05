bool Bubble::checkCollision(BubbleBlaster &blaster) {
    return (x == blaster.getX() && y == blaster.getY());
}