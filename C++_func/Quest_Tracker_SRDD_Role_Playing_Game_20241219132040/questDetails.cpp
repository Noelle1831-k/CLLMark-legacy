string Quest::questDetails() {
    string details = "Title: " + title + "\nDescription: " + description + "\nStatus: " + status +
                     "\nProgress: " + to_string(progress) + "%\nRewards: " + rewards + "\nCategories: ";
    for (unsigned int i = 0; i < categories.size(); i++) {
        details += categories[i] + ", ";
    }
    details += "\nTags: ";
    for (unsigned int i = 0; i < tags.size(); i++) {
        details += tags[i] + ", ";
    }
    return details;
}