bool Quest::hasTag(string tag) {
    return find(tags.begin(), tags.end(), tag) != tags.end();
}