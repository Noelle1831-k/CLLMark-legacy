void Poll::showResults() const {
    cout << "Poll Results for \"" << title << "\":\n";
    for (size_t i = 0; i < options.size(); ++i) {
        cout << options[i] << ": " << votes[i] << " votes\n";
    }
}