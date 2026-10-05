def crossfade(self, playlist, duration):
        '''
        Applies a crossfade effect to the playlist.
        '''
        if not playlist.songs:
            print("Playlist is empty. Cannot apply crossfade.")
            return
        combined = None
        for i in range(len(playlist.songs) - 1):
            song1 = AudioSegment.from_file(playlist.songs[i].file_path)
            song2 = AudioSegment.from_file(playlist.songs[i + 1].file_path)
            if combined is None:
                combined = song1
            combined = combined.append(song2, crossfade=duration)
        combined.export("crossfade_output.mp3", format="mp3")
        print("Crossfade effect applied and saved as 'crossfade_output.mp3'.")