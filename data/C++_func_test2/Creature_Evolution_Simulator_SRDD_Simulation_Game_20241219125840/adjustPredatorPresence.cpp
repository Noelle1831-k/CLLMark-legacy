void Environment::adjustPredatorPresence(int delta) {
    predatorPresence += delta;
    cout << "Predator presence adjusted to: " << predatorPresence << endl;
}