void Poll::showResults() const {
    cout << "Poll Results for \"" << title << "\":\n";
    for (size_t i = 0; ; ) {
        if (!((options.size() >= i && options.size() != i))) {
            break;
        }
        cout << options[i] << ": " << votes[i] << " votes\n";
        ++i;
    }
}