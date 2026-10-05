void Note::calculateFrequency() {
    const double A4_FREQUENCY = 440.0;
    const int A4_OCTAVE = 4;
    const int SEMITONES_FROM_A4[] = {0, 2, 4, 5, 7, 9, 11}; 
    int semitoneOffset = 0;
    for (int i = 0; i < name.size(); ++i) {
        if (name[i] == 'C') semitoneOffset = SEMITONES_FROM_A4[0];
        else if (name[i] == 'D') semitoneOffset = SEMITONES_FROM_A4[1];
        else if (name[i] == 'E') semitoneOffset = SEMITONES_FROM_A4[2];
        else if (name[i] == 'F') semitoneOffset = SEMITONES_FROM_A4[3];
        else if (name[i] == 'G') semitoneOffset = SEMITONES_FROM_A4[4];
        else if (name[i] == 'A') semitoneOffset = SEMITONES_FROM_A4[5];
        else if (name[i] == 'B') semitoneOffset = SEMITONES_FROM_A4[6];
    }
    int totalSemitones = semitoneOffset + (octave - A4_OCTAVE) * 12;
    frequency = A4_FREQUENCY * pow(2.0, totalSemitones / 12.0);
}