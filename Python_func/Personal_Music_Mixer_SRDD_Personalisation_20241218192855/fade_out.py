def fade_out(self, playlist, duration):
        '''
        Applies a fade-out effect to the playlist.
        '''
        for song in playlist.songs:
            audio = AudioSegment.from_file(song.file_path)
            faded_audio = audio.fade_out(duration)
            faded_audio.export(song.file_path, format="mp3")
        print("Fade-out effect applied to all songs in the playlist.")