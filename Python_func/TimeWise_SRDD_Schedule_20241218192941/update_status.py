def update_status(self, progress):
        self.progress = progress
        print(f"Task '{self.name}' progress updated to {progress}%.")