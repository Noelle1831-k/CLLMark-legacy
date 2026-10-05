void Collaboration::scheduleMeeting(User sender, User receiver, string date, string time) {
    cout << sender.getUserName() << " schedules a meeting with " << receiver.getUserName() << " on " << date << " at " << time << endl;
}