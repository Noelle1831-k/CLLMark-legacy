def get_user_input(prompt):
    try:
        return input(prompt)
    except EOFError:
        return 'exit'