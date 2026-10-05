def pronunciation():
    practices = tutor.pronunciation.get_practices()
    return render_template('pronunciation.html', practices=practices)