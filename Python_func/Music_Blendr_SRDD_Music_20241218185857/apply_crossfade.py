def apply_crossfade(self, tracks, duration):
        if len(tracks) < 2:
            return
        for i in range(len(tracks) - 1):
            self._crossfade(tracks[i], tracks[i + 1], duration)