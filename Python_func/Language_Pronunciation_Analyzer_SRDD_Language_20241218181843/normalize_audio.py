def normalize_audio(audio_data):
    return audio_data / np.max(np.abs(audio_data))