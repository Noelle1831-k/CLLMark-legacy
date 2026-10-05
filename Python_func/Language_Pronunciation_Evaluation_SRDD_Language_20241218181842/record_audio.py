def record_audio(sentence):
    print(f"Recording pronunciation for: {sentence}")
    fs = 44100  # Sample rate
    duration = 5  # Duration of recording in seconds
    print("Recording...")
    recording = sd.rec(int(duration * fs), samplerate=fs, channels=2, dtype='int16')
    sd.wait()  # Wait until recording is finished
    print("Recording complete.")
    audio_file = "user_pronunciation.wav"
    with wave.open(audio_file, 'wb') as wf:
        wf.setnchannels(2)
        wf.setsampwidth(2)
        wf.setframerate(fs)
        wf.writeframes(recording.tobytes())
    return audio_file