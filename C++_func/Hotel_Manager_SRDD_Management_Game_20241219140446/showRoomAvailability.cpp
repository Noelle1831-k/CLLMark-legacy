void Hotel::showRoomAvailability() {
    cout << "Rooms availability: \n";
    for (const auto &room : rooms) {
        cout << "Room " << room.first << ": " << (room.second ? "Available" : "Occupied") << endl;
    }
}