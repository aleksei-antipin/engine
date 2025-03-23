#include "src/Engine.h"

int main() {
    auto *engine = new Engine();
    engine->Initialize();
    engine->Run();
    engine->Terminate();
    return 0;
}
