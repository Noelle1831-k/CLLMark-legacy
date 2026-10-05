void create_sequence(MusicLoopCreator *mlc) {
    Sequence *sequence = create_sequence();
    Note *note = create_note();
    set_pitch(note, "C4");
    set_duration(note, 1.0);
    add_note_to_sequence(sequence, note);
    add_sequence_to_loop(mlc->loop, sequence);
}