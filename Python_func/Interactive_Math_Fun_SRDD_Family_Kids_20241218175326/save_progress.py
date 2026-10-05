def save_progress(self):
        try:
            with open(self.progress_file, 'w') as file:
                json.dump({"score": self.score_manager.score}, file)
            print("Progress saved.")
        except IOError:
            print("An error occurred while saving progress.")