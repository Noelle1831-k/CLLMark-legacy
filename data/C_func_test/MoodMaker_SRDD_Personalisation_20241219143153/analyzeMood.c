void analyzeMood(const char *mood, MoodAttributes *attributes) {
    if (strcmp(mood, "Happy") == 0) {
        attributes->tempo = 120;
        strcpy(attributes->genre, "Pop");
    } else if (strcmp(mood, "Sad") == 0) {
        attributes->tempo = 60;
        strcpy(attributes->genre, "Ballad");
    } else if (strcmp(mood, "Energetic") == 0) {
        attributes->tempo = 140;
        strcpy(attributes->genre, "Electronic");
    } else if (strcmp(mood, "Relaxed") == 0) {
        attributes->tempo = 80;
        strcpy(attributes->genre, "Jazz");
    } else {
        attributes->tempo = 100;
        strcpy(attributes->genre, "Mixed");
    }
}