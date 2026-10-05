def is_level_cleared(self):
        # Example condition: clear a certain number of blocks
        return not any(self.find_matches())