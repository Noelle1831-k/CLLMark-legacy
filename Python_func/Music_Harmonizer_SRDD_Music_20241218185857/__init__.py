def __init__(self):
        self.file_uploader = file_handler.FileUploader()
        self.melody_analyzer = melody_analyzer.MelodyAnalyzer()
        self.harmony_generator = harmony_generator.HarmonyGenerator()
        self.ui_manager = ui_manager.UIManager()
        self.run()