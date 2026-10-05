void Session::displaySession() {
    cout << "Session ID: " << sessionId << "\nTutor: " << tutor->getName()
         << "\nLearner: " << learner->getName() << "\nSubject: " << subject
         << "\nTime: " << time << "\nStatus: " << status << endl;
}