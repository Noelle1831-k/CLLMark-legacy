def save_settings(self, settings):
        # Save settings to a file
        with open(f'settings.txt', f'w') as file:
            for key, value in settings.items():
                file.write(f'{key}: {value}\n')