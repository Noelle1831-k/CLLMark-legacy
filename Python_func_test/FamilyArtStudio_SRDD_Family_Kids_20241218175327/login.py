def login():
        username = request.form.get('username')
        session_id = login_user(username)
        if session_id:
            session['user_id'] = session_id
            return jsonify({'status': 'success'})
        return jsonify({'status': 'failure'})