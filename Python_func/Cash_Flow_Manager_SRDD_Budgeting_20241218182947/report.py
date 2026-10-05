def report():
    if 'username' not in session:
        return redirect(url_for('login'))
    report = Report.generate()
    return render_template('report.html', report=report)