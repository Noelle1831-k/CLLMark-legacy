def alert_on_change(self):
        # Simulate change detection
        original_hash = utilities.hash_file("system_file")
        current_hash = utilities.hash_file("system_file")
        return original_hash != current_hash