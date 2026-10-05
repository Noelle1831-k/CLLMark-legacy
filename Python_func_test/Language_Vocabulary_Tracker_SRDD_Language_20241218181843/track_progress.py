def track_progress(self):
        '''
        Track and print the user's progress in learning vocabulary.
        '''
        progress = self.progress_tracker.get_progress()
        print("Progress:")
        for word, status in progress.items():
            print(f"Word: {word}, Status: {status}")