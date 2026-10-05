std::string Track::getSection(int index) const {
    if (index >= 0 && index < trackLayout.size()) {
        return trackLayout[index];
    }
    return "Unknown Section";
}