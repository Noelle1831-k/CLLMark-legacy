def _handle_local_file(self, file_path):
        '''
        Handles the local file input by verifying its existence and copying it to a temporary directory.
        Parameters:
            file_path (str): Path to the local audio file.
        Returns:
            temp_file_path (str): Path to the copied audio file in the temporary directory.
        '''
        if not os.path.exists(file_path):
            raise FileNotFoundError(f"The file {file_path} does not exist.")
        temp_file_path = os.path.join(self.temp_dir, os.path.basename(file_path))
        shutil.copy(file_path, temp_file_path)
        return temp_file_path