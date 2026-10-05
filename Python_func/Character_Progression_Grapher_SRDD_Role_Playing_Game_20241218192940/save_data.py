def save_data(self, character):
        try:
            with open('character_data.json', 'w') as f:
                json.dump(character.get_progression_data(), f)
            logging.info("Data saved successfully.")
        except IOError:
            logging.error("Error: Unable to save data.")
            print("Error: Unable to save data.")