def run(self):
        '''
        Runs the command-line interface loop.
        '''
        while True:
            command = input("Enter command (add, remove, play, save, share, exit): ")
            if command == "exit":
                break
            elif command == "add":
                song_path = input("Enter song path: ")
                self.mixer.create_playlist([song_path])
            elif command == "remove":
                song_path = input("Enter song path to remove: ")
                self.mixer.playlist.remove_song(song_path)
            elif command == "play":
                print("Playing playlist...")
            elif command == "save":
                filename = input("Enter filename to save: ")
                self.mixer.save_mix(filename)
            elif command == "share":
                platform = input("Enter platform to share: ")
                self.mixer.share_mix(platform)