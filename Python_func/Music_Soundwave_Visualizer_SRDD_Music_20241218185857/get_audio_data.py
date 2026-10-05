def get_audio_data(self):
        if self.audio_data is not None:
            return self.audio_data
        else:
            return np.zeros(44100)  # Return silence if no audio loaded