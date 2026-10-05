def __init__(self, athletes):
        self.athletes = athletes
        self.visualization = Visualization(athletes)
        self.report_generator = ReportGenerator(athletes)