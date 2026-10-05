def __init__(self, source_dir, output_dir):
        '''
        Initializes the Main class with source and output directories.
        '''
        self.source_dir = source_dir
        self.output_dir = output_dir
        self.parser = CodeParser()
        self.generator = DocumentationGenerator()
        self.exporter = FileExporter()