def main():
    display_interface()
    user_input = get_user_input()
    if validate_input(user_input):
        if isinstance(user_input, list):
            key_signature = analyze_notes(user_input)
        else:
            key_signature = analyze_chords(user_input)
        show_key_signature(key_signature)
        explain_key_signature(key_signature)
        provide_resources()
    else:
        print("Invalid input. Please try again.")