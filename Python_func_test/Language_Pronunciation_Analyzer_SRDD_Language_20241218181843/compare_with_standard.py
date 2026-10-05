def compare_with_standard(processed_audio):
    standard_features = {
        "peak_count": 100,
        "peak_heights": np.random.rand(100)
    }
    audio_features = extract_features(processed_audio, 44100)
    score = np.mean(np.abs(audio_features["peak_heights"] - standard_features["peak_heights"]))
    return f"Similarity Score: {100 - score*100:.2f}%"