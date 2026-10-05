def evaluate_pronunciation(self, user_input, recording):
        recognizer = sr.Recognizer()
        try:
            with sr.AudioFile(recording) as source:
                native_audio = recognizer.record(source)
                native_text = recognizer.recognize_google(native_audio, language=self.language_code())
            user_audio = sr.AudioData(user_input, 16000, 2)
            user_text = recognizer.recognize_google(user_audio, language=self.language_code())
            similarity = self.compare_pronunciations(native_text, user_text)
            return self.generate_evaluation(similarity)
        except sr.UnknownValueError:
            return "Could not understand the pronunciation."
        except sr.RequestError as e:
            return f"Could not request results from Google Speech Recognition service; {e}"