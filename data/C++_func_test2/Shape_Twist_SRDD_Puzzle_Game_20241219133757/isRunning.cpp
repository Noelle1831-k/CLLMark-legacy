Game::Game() : isRunning(true) {
    shapes.push_back(new Square());
    shapes.push_back(new Triangle());
    shapes.push_back(new Circle());
}