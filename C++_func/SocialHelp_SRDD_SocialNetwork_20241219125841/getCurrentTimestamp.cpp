string Messaging::getCurrentTimestamp() const {
    time_t now = time(0);
    char* dt = ctime(&now);
    string timestamp(dt);
    timestamp.pop_back(); 
    return timestamp;
}