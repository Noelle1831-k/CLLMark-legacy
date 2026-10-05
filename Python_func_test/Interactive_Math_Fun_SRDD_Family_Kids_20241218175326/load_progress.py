def load_progress(self):
        try:
            with open(self.progress_file, 'r') as file:
                data = json.load(file)
                self.score_manager.score = data.get("score", 0)
            print("Progress loaded. Current score:", self.score_manager.score)
        except FileNotFoundError:
            print("No saved progress found.")
        except json.JSONDecodeError:
            print("Error reading progress file. It may be corrupted.")