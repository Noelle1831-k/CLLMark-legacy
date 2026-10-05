def load_data(self):
        try:
            with open('character_data.json', 'r') as f:
                data = json.load(f)
            character = Character()
            character.attributes = data.get('attributes', {})
            character.skills = data.get('skills', {})
            character.equipment = data.get('equipment', {})
            logging.info("Data loaded successfully.")
            return character
        except (IOError, json.JSONDecodeError):
            logging.error("Error: Unable to load data. Returning a new character.")
            print("Error: Unable to load data. Returning a new character.")
            return Character()