def _adjust_tempo(self, track, factor):
        new_data = []
        for i in range(int(len(track['data']) * factor)):
            index = int(i / factor)
            if index < len(track['data']):
                new_data.append(track['data'][index])
        track['data'] = new_data