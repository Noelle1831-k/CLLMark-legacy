int main() {
    cout << "Welcome to EventConnect!" << endl;
    User user;
    EventManager eventManager;
    Messaging messaging;
    user.createProfile();
    eventManager.listEvents();
    user.viewProfile();
    eventManager.searchEvents();
    messaging.sendMessage();
    return 0;
}