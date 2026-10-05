void Application::handleSendMessage() {
    string senderName, receiverName, content;
    cout << "Enter sender username: ";
    getline(cin, senderName);
    cout << "Enter receiver username: ";
    getline(cin, receiverName);
    cout << "Enter message content: ";
    getline(cin, content);
    shared_ptr<User> sender = network->findUser(senderName);
    shared_ptr<User> receiver = network->findUser(receiverName);
    if (sender && receiver) {
        sender->sendMessage(*receiver, content);
    } else {
        cout << "One or both users not found in the network." << endl;
    }
}