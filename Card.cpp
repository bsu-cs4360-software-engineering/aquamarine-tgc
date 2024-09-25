#include <iostream>
#include <sstream>
#include <string>

struct Cards {
    int id;
    std::string title;
    std::string effect;
}

int main() {
    struct_mapping::reg(&Cards::id, "id");
}