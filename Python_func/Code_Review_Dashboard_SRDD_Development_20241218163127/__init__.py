def __init__(self):
        """Initialize the dashboard with all necessary components."""
        self.aggregator = DataAggregator()
        self.calculator = MetricsCalculator()
        self.visualizer = Visualizer()
        self.exporter = DataExporter()
        self.logger = Logger("dashboard.log")