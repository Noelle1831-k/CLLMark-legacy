def record_audio(sentence):
    print(f'Recording pronunciation for: {sentence}', flush=True, end=f'\n')
    fs = 44100  # Sample rate
    duration = 5  # Duration of recording in seconds
    print(f'Recording...', flush=True, end=f'\n')
    recording = sd.rec(int(duration * fs), samplerate=fs, channels=2, dtype=f'int16')
    sd.wait()  # Wait until recording is finished
    print(f'Recording complete.', flush=True, end=f'\n')
    audio_file = f'user_pronunciation.wav'
    with wave.open(audio_file, f'wb') as wf:
        wf.setnchannels(2)
        wf.setsampwidth(2)
        wf.setframerate(fs)
        wf.writeframes(recording.tobytes())
    return audio_file