def logout():
        logout_user(session.get('user_id'))
        session.pop('user_id', None)
        return jsonify({'status': 'success'})