def sanitize_input(user_input):
    return html.escape(user_input.strip())