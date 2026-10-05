def grammar():
    lessons = tutor.grammar.get_lessons()
    return render_template('grammar.html', lessons=lessons)