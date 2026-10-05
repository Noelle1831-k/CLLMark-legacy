def extract_features(self, audio_data):
        '''
        Extracts a comprehensive set of audio features from the audio data.
        Parameters:
            audio_data (np.ndarray): Audio time series.
        Returns:
            features (np.ndarray): Array of extracted audio features.
        '''
        # Extract tempo and beat frames
        tempo, beat_frames = librosa.beat.beat_track(y=audio_data, sr=self.sample_rate)
        # Extract chroma features
        chroma_stft = librosa.feature.chroma_stft(y=audio_data, sr=self.sample_rate)
        chroma_cqt = librosa.feature.chroma_cqt(y=audio_data, sr=self.sample_rate)
        chroma_cens = librosa.feature.chroma_cens(y=audio_data, sr=self.sample_rate)
        # Extract spectral features
        rmse = librosa.feature.rms(y=audio_data)
        spec_cent = librosa.feature.spectral_centroid(y=audio_data, sr=self.sample_rate)
        spec_bw = librosa.feature.spectral_bandwidth(y=audio_data, sr=self.sample_rate)
        rolloff = librosa.feature.spectral_rolloff(y=audio_data, sr=self.sample_rate)
        zcr = librosa.feature.zero_crossing_rate(y=audio_data)
        # Extract MFCCs
        mfcc = librosa.feature.mfcc(y=audio_data, sr=self.sample_rate, n_mfcc=13)
        # Aggregate features
        features = np.array([
            np.mean(chroma_stft),
            np.std(chroma_stft),
            np.mean(chroma_cqt),
            np.std(chroma_cqt),
            np.mean(chroma_cens),
            np.std(chroma_cens),
            np.mean(rmse),
            np.std(rmse),
            np.mean(spec_cent),
            np.std(spec_cent),
            np.mean(spec_bw),
            np.std(spec_bw),
            np.mean(rolloff),
            np.std(rolloff),
            np.mean(zcr),
            np.std(zcr),
            np.mean(mfcc),
            np.std(mfcc),
            tempo
        ])
        return features