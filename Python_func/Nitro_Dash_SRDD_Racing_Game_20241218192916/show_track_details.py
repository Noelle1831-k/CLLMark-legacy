def show_track_details(self):
        print(f"Track Name: {self.name}")
        print(f"Obstacles: {', '.join(self.obstacles)}")
        print(f"Shortcuts: {', '.join(self.shortcuts)}")