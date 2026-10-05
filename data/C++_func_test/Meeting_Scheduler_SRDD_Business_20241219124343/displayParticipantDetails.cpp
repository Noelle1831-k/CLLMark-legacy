void Participant::displayParticipantDetails() {
    cout << "Name: " << name << "\n";
    cout << "Email: " << email << "\n";
    cout << "Available: " << (availability ? "Yes" : "No") << "\n";
}