def fade_in(self, playlist, duration):
        '''
        Applies a fade-in effect to the playlist.
        '''
        for song in playlist.songs:
            audio = AudioSegment.from_file(song.file_path)
            faded_audio = audio.fade_in(duration)
            faded_audio.export(song.file_path, format="mp3")
        print("Fade-in effect applied to all songs in the playlist.")