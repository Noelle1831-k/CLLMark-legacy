def _crossfade(self, track1, track2, duration):
        fade_length = min(len(track1['data']), len(track2['data']), duration)
        for i in range(fade_length):
            alpha = i / fade_length
            track1['data'][-fade_length + i] = (1 - alpha) * track1['data'][-fade_length + i] + alpha * track2['data'][i]
            track2['data'][i] = alpha * track1['data'][-fade_length + i] + (1 - alpha) * track2['data'][i]