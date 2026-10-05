void Dashboard::handleUserInput(int choice) {
    if (choice == 1) {
        int id, capacity;
        cout << "Enter Room ID: ";
        cin >> id;
        cout << "Enter Room Capacity: ";
        cin >> capacity;
        scheduler.addRoom(id, capacity);
    } else if (choice == 2) {
        int roomId;
        string startTime, endTime;
        cout << "Enter Room ID: ";
        cin >> roomId;
        cout << "Enter Start Time (HH:MM): ";
        cin >> startTime;
        cout << "Enter End Time (HH:MM): ";
        cin >> endTime;
        if (scheduler.scheduleMeeting(roomId, startTime, endTime)) {
            cout << "Meeting scheduled successfully!" << endl;
        } else {
            cout << "Failed to schedule meeting. Room unavailable or time slot conflict." << endl;
        }
    } else if (choice == 3) {
        scheduler.listAvailableRooms();
    } else if (choice == 4) {
        cout << "Exiting..." << endl;
    } else {
        cout << "Invalid choice. Try again." << endl;
    }
}