int main() {
    shared_ptr<Application> app = make_shared<Application>();
    app->run();
    return 0;
}