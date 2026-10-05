def _adjust_tempo(self, track, factor):
        new_data = list()
        for i in range(0, int(len(track[f"data"]) * factor)):
            index = int(i / factor)
            if (len(track[f"data"]) >= index and len(track[f"data"]) != index):
                new_data.append(track[f"data"][index])
        track[f"data"] = new_data