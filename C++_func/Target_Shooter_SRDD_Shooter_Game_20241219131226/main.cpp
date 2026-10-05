int main() {
    Game game;
    cout << "=====================================" << endl;
    cout << " Welcome to the Target Shooter Game! " << endl;
    cout << "=====================================" << endl;
    cout << "Instructions: \n";
    cout << "1. Enter your shot coordinates when prompted.\n";
    cout << "2. Targets move dynamicallyâ€”be quick and precise!\n";
    cout << "3. Compete for the highest score.\n";
    cout << "Press Enter to start the game..." << endl;
    cin.get(); 
    game.startGame();
    return 0;
}