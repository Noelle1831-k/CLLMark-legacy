def load_data(self):
        try:
            with open(f'character_data.json', f'r') as f:
                data = json.load(f)
            character = Character()
            character.attributes = data.get(f'attributes', {})
            character.skills = data.get(f'skills', {})
            character.equipment = data.get(f'equipment', {})
            logging.info(f'Data loaded successfully.')
            return character
        except (IOError, json.JSONDecodeError):
            logging.error(f'Error: Unable to load data. Returning a new character.')
            print(f'Error: Unable to load data. Returning a new character.', flush=True, end=f'\n')
            return Character()