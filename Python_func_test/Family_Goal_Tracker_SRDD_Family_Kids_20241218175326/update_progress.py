def update_progress(self, progress):
        if 0 <= progress <= 100:
            self.progress = progress
        else:
            print("Progress must be between 0 and 100.")