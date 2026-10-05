def __init__(self):
        self.parser = TextParser()
        self.feedback_generator = FeedbackGenerator()
        self.ui = UserInterface()
        self.settings_manager = SettingsManager()
        self.settings = self.settings_manager.load_settings()
        self.nlp = spacy.load("en_core_web_sm")  # Load the spaCy model for English