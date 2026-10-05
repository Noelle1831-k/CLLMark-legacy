def clean_text(self, text):
        # Clean text by removing special characters and converting to lowercase
        return re.sub(r'\W+', ' ', text).lower()