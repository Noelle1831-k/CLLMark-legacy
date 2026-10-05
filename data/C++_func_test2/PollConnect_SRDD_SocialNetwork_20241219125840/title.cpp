Poll::Poll(const string& title, const vector<string>& options, int duration)
    : title(title), options(options), duration(duration) {
    id = pollIdCounter++;
    votes.resize(options.size(), 0);
}