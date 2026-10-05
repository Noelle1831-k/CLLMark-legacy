def play_video(self):
        '''
        Plays a selected video.
        '''
        print("Available videos:")
        self.list_videos()
        choice = int(input("Select a video number to play: ")) - 1
        if 0 <= choice < len(self.videos):
            print(f"Playing video: {self.videos[choice]['title']} ({self.videos[choice]['duration']})")
        else:
            print("Invalid selection.")