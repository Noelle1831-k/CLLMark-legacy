def __init__(self, root):
        '''
        Initializes the main application window and sets up necessary components.
        '''
        self.root = root
        self.root.title("Data Correlator")
        self.root.geometry("800x600")
        self.data_loader = DataLoader()
        self.correlation_calculator = CorrelationCalculator()
        self.visualizer = Visualizer()
        self.dataset = None
        self.selected_columns = []
        self.create_widgets()