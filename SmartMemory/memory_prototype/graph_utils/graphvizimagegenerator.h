#ifndef GRAPHVIZIMAGEGENERATOR_H
#define GRAPHVIZIMAGEGENERATOR_H

#include <string>
#include <fstream>

namespace gu {
    class GraphVizImageGenerator
    {
    private:
        std::string dot_path;
        std::string tmp_path;
    public:
        GraphVizImageGenerator(std::string dot_path, std::string tmp_path);
        void process_dot(std::string dot_sources, std::string result_path);
    };
}
#endif // GRAPHVIZIMAGEGENERATOR_H
