Athlete* findAthlete(vector<Athlete>& athletes, const string& name) {
    for (size_t i = 0; i < athletes.size(); i++) {
        if (athletes[i].getName() == name) {
            return &athletes[i];
        }
    }
    return nullptr;
}