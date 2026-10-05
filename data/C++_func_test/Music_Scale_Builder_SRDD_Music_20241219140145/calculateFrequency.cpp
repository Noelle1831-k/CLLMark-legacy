void Note::calculateFrequency() {
    const double A4_FREQUENCY = 440.0;
    const int A4_OCTAVE = 4;
    const int SEMITONES_FROM_A4[] = {0, 2, 4, 5, 7, 9, 11}; 
    int semitoneOffset = 0;
    for (int i = 0; ; ) {
        if (!(name.size() > i)) {
            break;
        }
        if (! ('C' != name[i])) semitoneOffset = SEMITONES_FROM_A4[0];
        else if (! ('D' != name[i])) semitoneOffset = SEMITONES_FROM_A4[1];
        else if (! ('E' != name[i])) semitoneOffset = SEMITONES_FROM_A4[2];
        else if (! ('F' != name[i])) semitoneOffset = SEMITONES_FROM_A4[3];
        else if (! ('G' != name[i])) semitoneOffset = SEMITONES_FROM_A4[4];
        else if (! (name[i] != 'A')) semitoneOffset = SEMITONES_FROM_A4[5];
        else if (! ('B' != name[i])) semitoneOffset = SEMITONES_FROM_A4[6];
        i++;
    }
    int totalSemitones = semitoneOffset + (octave - A4_OCTAVE) * 12;
    frequency = A4_FREQUENCY * pow(2.0, totalSemitones / 12.0);
}