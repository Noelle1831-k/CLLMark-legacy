def language_code(self):
        language_codes = {
            'English': 'en-US',
            'Spanish': 'es-ES',
            'French': 'fr-FR',
            'German': 'de-DE',
            'Chinese': 'zh-CN'
        }
        return language_codes.get(self.language, 'en-US')