#include "graphvizimagegenerator.h"

using namespace gu;

GraphVizImageGenerator::GraphVizImageGenerator(std::string dot_path, std::string tmp_path) :
    dot_path{dot_path}, tmp_path{tmp_path}
{

}

// dot command example
//cmd = exec.Command("cmd", "/C", "D:\\CherepNick\\ASTU\\2_course\\4_semester\\ASD\\graphs\\release\\bin\\dot.exe -Tgif
//D:\\CherepNick\\ASTU\\2_course\\4_semester\\ASD\\graphs\\lr6\\data\\output.dot -o D:\\CherepNick\\ASTU\\2_course\\4_semester\\ASD\\graphs\\lr6\\data\\output.png")
void GraphVizImageGenerator::process_dot(std::string dot_sources, std::string result_path)
{
    // 1. write dot sources to tmp file
    std::string tmp_dot = tmp_path + "\\" + "tmp.dot";
    std::ofstream tmp_out(tmp_dot);
    tmp_out << dot_sources;
    tmp_out.close();
    // 2. prepare system command
    std::string cmd = dot_path + " -Tgif " + tmp_dot + " -o " + result_path;
    // 3. run command
    system(cmd.c_str());
    system((std::string("explorer ") + result_path).c_str());
}
