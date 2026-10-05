def convert_file(self, input_file, output_format):
        file_type = self._determine_file_type(input_file)
        if file_type == 'document':
            self.convert_document(input_file, output_format)
        elif file_type == 'spreadsheet':
            self.convert_spreadsheet(input_file, output_format)
        elif file_type == 'presentation':
            self.convert_presentation(input_file, output_format)
        elif file_type == 'image':
            self.convert_image(input_file, output_format)