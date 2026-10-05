int main() {
    MusicLoopCreator *mlc = create_music_loop_creator();
    Instrument *piano = create_instrument("Piano");
    load_sound(piano, "piano_sound.wav");
    Instrument *drum = create_instrument("Drum");
    load_sound(drum, "drum_sound.wav");
    Sequence *seq1 = create_sequence();
    Note *note1 = create_note();
    set_pitch(note1, "C4");
    set_duration(note1, 1.0);
    add_note_to_sequence(seq1, note1);
    Note *note2 = create_note();
    set_pitch(note2, "E4");
    set_duration(note2, 0.5);
    add_note_to_sequence(seq1, note2);
    add_sequence_to_loop(mlc->loop, seq1);
    play_loop(mlc->loop);
    export_loop(mlc->loop, "output.wav");
    adjust_tempo(mlc->loop, 140.0);
    customize_loop_length(mlc->loop, 8);
    free_music_loop_creator(mlc);
    return 0;
}