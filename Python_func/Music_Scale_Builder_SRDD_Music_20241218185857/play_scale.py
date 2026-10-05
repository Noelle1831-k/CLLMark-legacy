def play_scale(self):
        if not self.pitches:
            print("No pitches to play.")
            return
        frequencies = [p.get_frequency() for p in self.pitches]
        sample_rate = 44100
        t = np.linspace(0, 0.5, int(0.5 * sample_rate), False)
        audio = np.hstack([np.sin(2 * np.pi * freq * t) for freq in frequencies])
        audio *= 32767 / np.max(np.abs(audio))
        audio = audio.astype(np.int16)
        play_obj = sa.play_buffer(audio, 1, 2, sample_rate)
        play_obj.wait_done()