string Quest::getDetails() const {
    string details = "Name: " + name + "\nDescription: " + description +
                     "\nCategory: " + category + "\nStatus: " + status +
                     "\nReward: " + reward + "\nTags: ";
    for (int i = 0; i < tags.size(); i++) {
        details += tags[i];
        if (i < tags.size() - 1) details += ", ";
    }
    return details;
}