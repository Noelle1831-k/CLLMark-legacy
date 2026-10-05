def extract_tempo_data(self, music_data):
        '''
        Extracts the tempo and beat data from the audio data.
        '''
        if music_data:
            data, sr = music_data
            try:
                tempo, beats = librosa.beat.beat_track(y=data, sr=sr)
                print(f"Tempo extracted: {tempo} BPM", flush=True)
                return beats
            except Exception as e:
                print(f"Error extracting tempo data: {e}", flush=True)
                return None
        print("No music data provided for tempo extraction.", flush=True)
        return None