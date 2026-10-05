def process_input(self, input_source):
        '''
        Processes the input source, determining if it is a local file or a URL.
        Parameters:
            input_source (str): Path to the audio file or URL to the online track.
        Returns:
            file_path (str): Path to the processed audio file.
        '''
        if os.path.isfile(input_source):
            return self._handle_local_file(input_source)
        elif input_source.startswith("http"):
            return self._download_file(input_source)
        else:
            raise ValueError("Invalid input source. Please provide a valid file path or URL.")