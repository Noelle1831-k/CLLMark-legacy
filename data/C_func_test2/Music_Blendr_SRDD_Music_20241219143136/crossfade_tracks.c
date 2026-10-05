void crossfade_tracks(Track *track1, Track *track2) {
    int fade_length = 44100 * 5; 
    for (int i = 0; i < fade_length; i++) {
        float factor1 = 1.0f - (float)i / fade_length;
        float factor2 = (float)i / fade_length;
        track1->samples[track1->duration * 44100 - fade_length + i] = track1->samples[track1->duration * 44100 - fade_length + i] * factor1;
        track2->samples[i] = track2->samples[i] * factor2;
    }
}