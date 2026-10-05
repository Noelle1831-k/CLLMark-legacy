vector<string> Key::getScale() const {
    if (name == "C") {
        return {"C", "D", "E", "F", "G", "A", "B"};
    } else if (name == "D") {
        return {"D", "E", "F#", "G", "A", "B", "C#"};
    } else {
        return {"C", "D", "E", "F", "G", "A", "B"}; 
    }
}