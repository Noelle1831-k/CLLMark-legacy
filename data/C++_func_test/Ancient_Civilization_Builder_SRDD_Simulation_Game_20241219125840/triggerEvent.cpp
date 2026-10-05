void EventManager::triggerEvent() {
    int event = rand() % 3;
    switch (event) {
        case 0:
            cout << "A drought has occurred! Resources are reduced." << endl;
            break;
        case 1:
            cout << "A trade caravan has arrived! Resources are increased." << endl;
            break;
        case 2:
            cout << "A neighboring civilization has attacked! Defend yourself!" << endl;
            break;
    }
}