int main() {
    Game racingDash;
    racingDash.initGame();
    racingDash.startRace();
    while (racingDash.isRunning()) {
        racingDash.updateGame();
    }
    cout << "Thanks for playing Racing Dash!" << endl;
    return 0;
}