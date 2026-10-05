def extract_features(audio_data, rate):
    peaks, _ = find_peaks(audio_data, height=0)
    return {
        'peak_count': len(peaks),
        'peak_heights': audio_data[peaks]
    }