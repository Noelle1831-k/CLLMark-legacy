def play_scale(self, scale):
        frequency_map = {
            "C": 261.63, "C#": 277.18, "D": 293.66, "D#": 311.13, "E": 329.63,
            "F": 349.23, "F#": 369.99, "G": 392.00, "G#": 415.30, "A": 440.00,
            "A#": 466.16, "B": 493.88, "Eb": 311.13, "Gb": 369.99, "Bb": 466.16
        }
        sample_rate = 44100
        duration = 0.5
        for note in scale:
            frequency = frequency_map.get(note, 440.00)
            t = np.linspace(0, duration, int(sample_rate * duration), False)
            wave = 0.5 * np.sin(2 * np.pi * frequency * t)
            audio = wave * (2**15 - 1) / np.max(np.abs(wave))
            audio = audio.astype(np.int16)
            play_obj = sa.play_buffer(audio, 1, 2, sample_rate)
            play_obj.wait_done()