void Application::viewAssistances() {
    vector<Assistance> assistances = db.getAssistances();
    for (const Assistance& assistance : assistances) {
        cout << "Assistance: " << assistance.getType() << " by " << assistance.getUser() << "\n";
    }
}