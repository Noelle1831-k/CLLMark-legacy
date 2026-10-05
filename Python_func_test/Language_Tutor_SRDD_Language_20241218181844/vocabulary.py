def vocabulary():
    exercises = tutor.vocabulary.get_exercises()
    return render_template('vocabulary.html', exercises=exercises)