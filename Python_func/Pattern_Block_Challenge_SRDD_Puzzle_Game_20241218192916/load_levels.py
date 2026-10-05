def load_levels(self):
        # Load level configurations from a JSON file
        config = load_config("levels.json")
        for level_data in config["levels"]:
            level = Level(level_data)
            self.levels.append(level)