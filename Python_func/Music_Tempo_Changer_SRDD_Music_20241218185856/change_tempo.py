def change_tempo(self, audio_data, target_tempo, original_tempo=None):
        '''
        Changes the tempo of the audio data to the target tempo.
        Allows for a fallback to user-provided original tempo if beat detection fails.
        '''
        try:
            y, sr = audio_data
            # Estimate the current tempo
            tempo, _ = librosa.beat.beat_track(y=y, sr=sr)
            # If tempo estimation fails or is unreliable, use the provided original tempo
            if original_tempo and (tempo <= 0 or abs(tempo - original_tempo) > 20):
                print(f"Using user-provided original tempo: {original_tempo}")
                tempo = original_tempo
            # Adjust the tempo
            y_fast = librosa.effects.time_stretch(y, target_tempo / tempo)
            return y_fast, sr
        except Exception as e:
            print(f"Error changing tempo: {e}")
            return None