def load_classes_from_file(file_path):
    '''
    Loads character classes from a file.
    '''
    with open(file_path, 'r') as file:
        data = json.load(file)
    character_classes = [CharacterClass(cls['name'], cls['abilities']) for cls in data]
    return character_classes