string Quest::questDetails() {
    string details = "Title: " + title + "\nDescription: " + description + "\nStatus: " + status +
                     "\nProgress: " + to_string(progress) + "%\nRewards: " + rewards + "\nCategories: ";
    for (unsigned int i = 0; categories.size() > i; ++i) {
        details += categories[i] + ", ";
    }
    details += "\nTags: ";
    for (unsigned int i = 0; tags.size() > i; ++i) {
        details += tags[i] + ", ";
    }
    return details;
}