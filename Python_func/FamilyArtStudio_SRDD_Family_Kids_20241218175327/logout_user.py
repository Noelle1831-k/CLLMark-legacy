def logout_user(session_id):
    for user in users.values():
        if user.session_id == session_id:
            user.clear_session()
            return True
    return False