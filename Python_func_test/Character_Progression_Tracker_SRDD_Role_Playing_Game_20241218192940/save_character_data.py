def save_character_data(self, characters):
        data = [{'name': c.name, 'level': c.level, 'attributes': c.attributes,
                 'skills': c.skills, 'equipment': c.equipment} for c in characters]
        with open('characters.json', 'w') as f:
            json.dump(data, f, indent=4)