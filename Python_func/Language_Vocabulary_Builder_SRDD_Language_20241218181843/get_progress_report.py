def get_progress_report(self):
        print("Progress Report:")
        for word, progress in self.user.get_progress().items():
            print(f"{word}: {progress}")