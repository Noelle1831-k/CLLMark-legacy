def load_audio(self, input_path):
        '''
        Load audio from a file or URL.
        '''
        try:
            if input_path.startswith('http://') or input_path.startswith('https://'):
                # Handle URL input
                response = requests.get(input_path)
                response.raise_for_status()
                with tempfile.NamedTemporaryFile(delete=True) as temp_file:
                    temp_file.write(response.content)
                    temp_file.flush()
                    audio_data, sr = librosa.load(temp_file.name, sr=None)
            else:
                # Handle file input
                audio_data, sr = librosa.load(input_path, sr=None)
            return audio_data
        except Exception as e:
            print(f"Error loading audio: {e}")
            return None