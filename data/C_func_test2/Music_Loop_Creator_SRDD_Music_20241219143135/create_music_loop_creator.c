MusicLoopCreator* create_music_loop_creator() {
    MusicLoopCreator *mlc = (MusicLoopCreator*)malloc(sizeof(MusicLoopCreator));
    mlc->loop = create_loop();
    return mlc;
}