bool Recipe::matchesTags(const vector<string>& userTags) const {
    for (vector<string>::const_iterator it = tags.begin(); it != tags.end(); ++it) {
        if (find(userTags.begin(), userTags.end(), *it) != userTags.end()) {
            return true;
        }
    }
    return false;
}