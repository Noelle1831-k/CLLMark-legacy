void registerForEvent(string userID) {
        participants.push_back(userID);
        cout << "User ID: " << userID << " registered for event: " << eventName << "\n";
    }