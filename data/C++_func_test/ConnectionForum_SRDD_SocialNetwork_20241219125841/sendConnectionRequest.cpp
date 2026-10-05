void Network::sendConnectionRequest() {
    cout << "Sending connection request..." << endl;
    string recipient;
    cout << "Enter recipient username: ";
    cin >> recipient;
    cout << "Connection request sent to " << recipient << "!" << endl;
}