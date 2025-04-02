#include "tiny_obj_loader.h"

class Mesh {
public:
    Mesh(const std::string& filename);
    ~Mesh();

    void draw();
}