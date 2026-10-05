def generate_feedback(accuracy_score):
    print("Generating feedback based on pronunciation accuracy...")
    if accuracy_score > 0.8:
        print("Excellent pronunciation! Keep up the good work.")
    elif accuracy_score > 0.5:
        print("Good pronunciation, but there's room for improvement.")
    else:
        print("Needs improvement. Practice more to enhance your pronunciation.")