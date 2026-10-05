def load_online_audio(self, url):
        # Download and load audio data from the URL
        try:
            response = requests.get(url)
            response.raise_for_status()
            audio_data, sr = librosa.load(io.BytesIO(response.content), sr=None)
            return audio_data
        except requests.exceptions.RequestException as e:
            print(f"Error downloading audio from URL: {e}")
            return np.array([])
        except Exception as e:
            print(f"Error processing audio data from URL: {e}")
            return np.array([])