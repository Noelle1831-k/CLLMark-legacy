def apply_echo(track, delay, decay):
    sample_rate = 44100  # Assuming a standard sample rate
    delay_samples = calculate_delay_samples(delay, sample_rate)
    echo_track = np.zeros(len(track) + delay_samples)
    echo_track[:len(track)] = track
    echo_track[delay_samples:] += track * decay
    return mix_tracks(track, echo_track, decay)