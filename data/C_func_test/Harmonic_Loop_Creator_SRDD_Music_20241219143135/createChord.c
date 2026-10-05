Chord* createChord(const char* name, int duration) {
    Chord* chord = (Chord*)malloc(sizeof(Chord));
    chord->name = strdup(name);  
    chord->duration = duration;
    return chord;
}