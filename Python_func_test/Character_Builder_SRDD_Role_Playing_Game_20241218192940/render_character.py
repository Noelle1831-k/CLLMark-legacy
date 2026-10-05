def render_character(self, character):
        print(f'Rendering character: {character.name}')
        print(f'Race: {character.race.name}, Class: {character.class_type.name}')
        print(f'Level: {character.level}, Experience: {character.experience}')
        print('Attributes:')
        for attr, value in character.attributes.items():
            print(f'  {attr}: {value}')
        print('Abilities:')
        for ability in character.abilities:
            print(f'  {ability.name}')
        print('Equipment:')
        for item in character.equipment:
            print(f'  {item.name}')