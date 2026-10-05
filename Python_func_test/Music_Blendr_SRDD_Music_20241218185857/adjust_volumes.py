def adjust_volumes(self, tracks, volume_levels):
        for track, volume in zip(tracks, volume_levels):
            track['data'] = [x * volume for x in track['data']]