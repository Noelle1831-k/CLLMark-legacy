void Fundraising::displayEvents() {
    cout << "Fundraising Events:" << endl;
    for (int i = 0; i < events.size(); i++) {
        cout << "- " << events[i] << endl;
    }
    cout << "Total Funds Raised: $" << totalFundsRaised << endl;
}