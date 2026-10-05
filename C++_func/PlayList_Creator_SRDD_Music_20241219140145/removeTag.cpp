void Playlist::removeTag(const string& tag) {
    for (vector<string>::iterator it = tags.begin(); it != tags.end(); ++it) {
        if (*it == tag) {
            tags.erase(it);
            break;
        }
    }
}