void Challenge::viewChallenge() const {
    std::cout << "Challenge: " << name << std::endl;
    std::cout << "Type: " << type << ", Duration: " << duration << " days, Intensity: " << intensity << "/10" << std::endl;
    std::cout << "Exercises included:" << std::endl;
    for (size_t i = 0; i < exercises.size(); ++i) {
        exercises[i].viewExercise();
    }
}