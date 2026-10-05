void InputHandler::handleInput(vector<Player>& players) {
    cout << "Handling input for players..." << endl;
    for (int i = 0; i < players.size(); i++) {
        players[i].getVehicle().accelerate();
    }
}