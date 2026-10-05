void Event::addGuest(string guestName) {
    guestList[guestName] = false;
    cout << "Guest " << guestName << " added to the event.\n";
}