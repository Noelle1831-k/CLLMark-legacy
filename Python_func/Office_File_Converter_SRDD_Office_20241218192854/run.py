def run(self):
        self.ui.display_interface()
        input_file = self.ui.upload_file()
        output_format = self.ui.select_output_format()
        self.converter.convert_file(input_file, output_format)