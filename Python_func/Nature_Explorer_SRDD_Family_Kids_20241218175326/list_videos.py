def list_videos(self):
        '''
        Lists available videos.
        '''
        for i, video in enumerate(self.videos, start=1):
            print(f"{i}. {video['title']} ({video['duration']})")