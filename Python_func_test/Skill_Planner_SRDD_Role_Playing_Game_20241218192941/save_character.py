def save_character(character):
    with open(f'{character.name}.txt', 'w') as file:
        file.write(f'Character: {character.name}\n')
        file.write('Attributes:\n')
        for attr, value in character.attributes.items():
            file.write(f'  {attr}: {value}\n')
        file.write('Skills:\n')
        for skill, level in character.skills.items():
            file.write(f'  {skill}: Level {level}\n')