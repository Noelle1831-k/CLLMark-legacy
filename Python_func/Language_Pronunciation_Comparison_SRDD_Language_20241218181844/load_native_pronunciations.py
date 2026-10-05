def load_native_pronunciations():
    '''
    Loads native speaker audio files for comparison.
    This function loads a set of native speaker pronunciation audio files and returns them as a list.
    '''
    native_audio_files = ["native_audio_1.wav", "native_audio_2.wav", "native_audio_3.wav"]
    native_audio = []
    for file in native_audio_files:
        native_audio.append(utils.load_audio_file(file))
    return native_audio