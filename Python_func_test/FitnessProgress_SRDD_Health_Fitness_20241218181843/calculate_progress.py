def calculate_progress(self, username):
        # Calculate progress over time
        entries = self.fitness_data_manager.get_entries(username)
        progress = sum(entry['distance'] for entry in entries)
        return progress