void Event::trackRSVP(string guestName, bool isAttending) {
    if (guestList.find(guestName) != guestList.end()) {
        guestList[guestName] = isAttending;
        cout << "RSVP for " << guestName << " updated.\n";
    } else {
        cout << "Guest " << guestName << " not found.\n";
    }
}