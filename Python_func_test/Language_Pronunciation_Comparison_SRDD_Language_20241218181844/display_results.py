def display_results(similarity_score):
    '''
    Displays comparison results to the user.
    This function displays the similarity score and gives feedback on the user's pronunciation.
    '''
    print(f"\n--- Pronunciation Comparison Results ---")
    print(f"Similarity Score: {similarity_score:.2f}")
    if similarity_score > 0.8:
        print("Great job! Your pronunciation is very close to the native speaker.")
    elif similarity_score > 0.5:
        print("Good effort! Keep practicing to improve your pronunciation.")
    else:
        print("Needs improvement. Try listening to the native speaker and practice more.")
    print("------------------------------------------")