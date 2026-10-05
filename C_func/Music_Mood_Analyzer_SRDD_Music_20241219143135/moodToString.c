const char* moodToString(MoodDescriptor mood) {
    switch (mood) {
        case HAPPY: return "Happy";
        case SAD: return "Sad";
        case ENERGETIC: return "Energetic";
        case CALM: return "Calm";
        default: return "Unknown";
    }
}