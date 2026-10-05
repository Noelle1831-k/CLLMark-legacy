def translate(self, text, target_language):
        try:
            logging.info("Sending translation request to API.")
            response = requests.post(
                self.api_url,
                headers={"Authorization": f"Bearer {self.api_key}"},
                json={"text": text, "target_language": target_language}
            )
            response.raise_for_status()
            translation_data = response.json()
            translated_text = translation_data.get('translated_text', 'Translation failed.')
            logging.info("Translation successful.")
            return translated_text
        except requests.exceptions.RequestException as e:
            logging.error(f"Error during translation: {str(e)}")
            return f"Error during translation: {str(e)}"