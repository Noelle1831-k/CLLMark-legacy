Game::Game() : player("Player1") {
    cars.push_back(Car("Drift King", 8.5, 200, 100));
    cars.push_back(Car("Speed Demon", 7.0, 220, 90));
    tracks.push_back(Track("Mountain Pass", 5, 3.5));
    tracks.push_back(Track("City Circuit", 3, 2.0));
}