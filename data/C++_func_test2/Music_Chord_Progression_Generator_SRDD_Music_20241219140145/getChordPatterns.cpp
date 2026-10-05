vector<string> Mood::getChordPatterns() const {
    if (name == "happy") {
        return {"maj", "maj7", "maj", "maj7"}; 
    } else if (name == "sad") {
        return {"min", "min7", "dim", "min7"}; 
    } else if (name == "jazz") {
        return {"maj7", "min7", "7", "dim7"}; 
    } else {
        return {"maj", "min", "dim", "aug"}; 
    }
}