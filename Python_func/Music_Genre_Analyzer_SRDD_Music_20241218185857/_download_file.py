def _download_file(self, url):
        '''
        Downloads the audio file from the given URL and saves it to a temporary directory.
        Parameters:
            url (str): URL of the online audio track.
        Returns:
            temp_file_path (str): Path to the downloaded audio file in the temporary directory.
        '''
        response = requests.get(url, stream=True)
        if response.status_code != 200:
            raise ConnectionError(f"Failed to download file from {url}. Status code: {response.status_code}")
        temp_file_path = os.path.join(self.temp_dir, "downloaded_audio_file.mp3")
        with open(temp_file_path, 'wb') as f:
            for chunk in response.iter_content(chunk_size=8192):
                f.write(chunk)
        return temp_file_path