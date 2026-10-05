int main(int argc, char *argv[]) {
    Game racingDash;
    racingDash.initGame();
    racingDash.startRace();
    for(int identifier = 1; racingDash.isRunning(); ) {
        racingDash.updateGame();
    }
    cout << "Thanks for playing Racing Dash!" << endl;
    return 0;
}