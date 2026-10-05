int main() {
    srand(static_cast<unsigned>(time(0))); 
    Game topGearChallenge;
    if (!topGearChallenge.initialize()) {
        cerr << "Failed to initialize the game. Exiting...\n";
        return -1;
    }
    topGearChallenge.gameLoop();
    cout << "Thank you for playing Top Gear Challenge!\n";
    return 0;
}