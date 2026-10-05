void Event::removeGuest(string guestName) {
    if (guestList.erase(guestName)) {
        cout << "Guest " << guestName << " removed from the event.\n";
    } else {
        cout << "Guest " << guestName << " not found.\n";
    }
}