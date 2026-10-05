def main():
    print("Welcome to the Language Pronunciation Evaluation App!")
    while True:
        print("\nPlease choose an option:")
        print("1. Record Pronunciation")
        print("2. Exit")
        choice = input("Enter your choice: ")
        if choice == '1':
            sentence = input("Enter the sentence you want to practice: ")
            audio_file = audio_recorder.record_audio(sentence)
            analysis_result = pronunciation_analyzer.analyze_pronunciation(audio_file, sentence)
            feedback_generator.generate_feedback(analysis_result)
        elif choice == '2':
            print("Thank you for using the Language Pronunciation Evaluation App!")
            break
        else:
            print("Invalid choice. Please try again.")