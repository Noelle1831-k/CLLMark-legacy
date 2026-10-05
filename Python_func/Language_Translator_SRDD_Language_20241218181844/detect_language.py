def detect_language(self, text):
        try:
            logging.info("Sending language detection request to API.")
            response = requests.post(
                self.api_url,
                headers={"Authorization": f"Bearer {self.api_key}"},
                json={"text": text}
            )
            response.raise_for_status()
            detection_data = response.json()
            language = detection_data.get('language', 'Unknown')
            logging.info(f"Language detected: {language}")
            return language
        except requests.exceptions.RequestException as e:
            logging.error(f"Error during language detection: {str(e)}")
            return f"Error during language detection: {str(e)}"