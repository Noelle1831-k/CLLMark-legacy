def export_loop(self):
        '''
        Exports the loop to a specified audio format.
        '''
        format = input("Enter the format to export (e.g., wav, mp3): ")
        file_name = input("Enter the file name: ")
        self.exporter.export(self.patterns, format, file_name)