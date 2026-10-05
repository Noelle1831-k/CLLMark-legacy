def adjust_tempo(self, audio_data, target_tempo):
        '''
        Adjust the tempo of the audio data while maintaining pitch.
        Parameters:
        - audio_data: A tuple containing the audio array and sample rate.
        - target_tempo: The desired tempo in beats per minute (BPM).
        Returns:
        - A tuple containing the adjusted audio array and sample rate.
        '''
        y, sr = audio_data
        # Detect the original tempo of the audio
        tempo, beat_frames = librosa.beat.beat_track(y=y, sr=sr)
        # Calculate the rate of tempo change
        rate = target_tempo / tempo
        # Stretch the audio to the new tempo
        y_stretched = librosa.effects.time_stretch(y, rate)
        return y_stretched, sr