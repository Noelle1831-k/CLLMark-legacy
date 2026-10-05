void Network::acceptConnection() {
    cout << "Accepting connection request..." << endl;
    string requester;
    cout << "Enter requester username: ";
    cin >> requester;
    connections.push_back(requester);
    cout << "Connection request from " << requester << " accepted!" << endl;
}