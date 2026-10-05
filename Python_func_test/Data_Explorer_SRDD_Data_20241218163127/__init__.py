def __init__(self):
        # Initialize attributes for data, visualizer, operations, and file handler
        self.data = None
        self.grouped_data = None
        self.visualizer = DataVisualizer()
        self.operations = DataOperations()
        self.file_handler = FileHandler()