def extract_features(self, processed_audio):
        '''
        Extracts features from the processed audio for analysis.
        Arguments:
        processed_audio -- The filtered audio signal.
        Returns:
        A list of extracted features, including MFCCs and spectral features.
        '''
        print("Extracting features from processed audio...")
        # Extract MFCC features
        mfcc_features = self.calculate_mfcc(processed_audio)
        # Extract Spectral Centroid
        spectral_centroid = self.calculate_spectral_centroid(processed_audio)
        # Extract Zero-Crossing Rate
        zero_crossing_rate = self.calculate_zero_crossing_rate(processed_audio)
        # Extract Spectral Roll-off
        spectral_rolloff = self.calculate_spectral_rolloff(processed_audio)
        # Return all features as a dictionary
        features = {
            "mfcc": mfcc_features,
            "spectral_centroid": spectral_centroid,
            "zero_crossing_rate": zero_crossing_rate,
            "spectral_rolloff": spectral_rolloff
        }
        return features