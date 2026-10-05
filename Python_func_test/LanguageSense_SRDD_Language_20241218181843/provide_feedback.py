def provide_feedback(analysis):
    # Provide feedback based on analysis result
    if analysis['correct']:
        feedback = Feedback("Correct!", "Your answer is accurate.")
    else:
        feedback = Feedback("Incorrect.", "Consider revising the grammar rules.")
    print(feedback.message)
    print(feedback.explanation)