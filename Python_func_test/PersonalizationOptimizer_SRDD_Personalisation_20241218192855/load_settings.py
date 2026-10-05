def load_settings(self):
        # Load settings from a file
        settings = {}
        with open("settings.txt", "r") as file:
            for line in file:
                key, value = line.strip().split(": ")
                settings[key] = value
        return settings