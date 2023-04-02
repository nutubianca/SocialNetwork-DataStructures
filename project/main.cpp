#include <iostream>
#include "array.h"
#include "tests.h"
#include "RepoInMemory.h"
#include "UI.h"
using namespace std;

int main() {
    allTests();
    RepoInMemory repository;
    Network network(repository);
    UI userInterface(network);
    userInterface.menu();
    return 0;
}
