def __init__(self):
        # Initialize data and component classes
        self.data = None
        self.importer = DataImporter()
        self.transformer = DataTransformer()
        self.exporter = DataExporter()