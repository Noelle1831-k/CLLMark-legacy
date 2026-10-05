def login_user(username):
    if username not in users:
        users[username] = User(username)
    session_id = generate_session_id()
    users[username].set_session_id(session_id)
    return session_id