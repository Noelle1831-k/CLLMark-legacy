void Hotel::receiveFeedback(int roomNumber, int satisfactionRating) {
    if (satisfactionRating >= 4) {
        cout << "Guest in room " << roomNumber << " is very satisfied!" << endl;
    } else {
        cout << "Guest in room " << roomNumber << " had a negative experience." << endl;
    }
}