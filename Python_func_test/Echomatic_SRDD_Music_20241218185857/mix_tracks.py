def mix_tracks(original, echo, decay):
    max_length = max(len(original), len(echo))
    mixed_track = np.zeros(max_length)
    mixed_track[:len(original)] = mixed_track[:len(original)] + original
    mixed_track[:len(echo)] = mixed_track[:len(echo)] + echo * decay
    return mixed_track