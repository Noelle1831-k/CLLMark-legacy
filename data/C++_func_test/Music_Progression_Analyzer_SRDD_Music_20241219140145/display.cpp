void Visualizer::display() {
    cout << "Displaying chord progression visualization:" << endl;
    for (size_t i = 0; i < progression.size(); i++) {
        cout << "[" << progression[i] << "] ";
    }
    cout << endl;
}