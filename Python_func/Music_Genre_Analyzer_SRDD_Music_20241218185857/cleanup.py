def cleanup(self):
        '''
        Cleans up the temporary directory by removing all files and the directory itself.
        '''
        shutil.rmtree(self.temp_dir)