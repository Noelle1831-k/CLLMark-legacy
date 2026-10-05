def load_progress(file_path):
    try:
        with open(file_path, 'r') as file:
            user_data = json.load(file)
            user = User(user_data['username'], user_data['proficiency_level'], user_data['learning_goals'])
            user.phrasebook = Phrasebook()
            for category, phrases in user_data['phrasebook']['categories'].items():
                user.phrasebook.add_category(category)
                for phrase_data in phrases:
                    phrase = Phrase(phrase_data['text'], phrase_data['audio_pronunciation'], phrase_data['examples'])
                    user.phrasebook.add_phrase(category, phrase)
            user.progress = user_data['progress']
            return user
    except FileNotFoundError:
        print(f'Error: The file {file_path} was not found.')
        return None
    except json.JSONDecodeError:
        print(f'Error: The file {file_path} is not a valid JSON.')
        return None