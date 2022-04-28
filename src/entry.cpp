#include <args.hxx>
#include "common.hpp"
#include "ghc/filesystem.hpp"
#include <nlohmann/json.hpp>
#include <cstring>

using Debug = Common::Debug;
Debug Dbg;

int main(int argc, char **argv)  {

    if(strcmp(Common::GetOperatingSystemName(), "linux")) {
    Dbg.LogData(Debug::LogType::Error, "Unsupported Operating System");
    return 0;
    }

    Common::PrintSystemInformation();
    args::ArgumentParser parser("MultiChem by @notSam25", "Licence info on github.com/notSam25/MultiChem");
    args::HelpFlag help(parser, "help", "Display this help menu", {'h', "help"});
    args::Group commands(parser, "Commands");
    args::ValueFlag<std::string> message(parser, "PATH", "Path to JSON input", {'p'});

    try {
        parser.ParseCLI(argc, argv);
        if(message) {
            std::cout << "Path: " << args::get(message) << std::endl;
            if(ghc::filesystem::exists(message->c_str()) && strcmp(ghc::filesystem::path(message->c_str()).extension().c_str(), ".json")) {
                // File exists and has the extension of .json
                
            } else
                Dbg.LogData(Debug::LogType::Error, "File does not exist!");
        }
    }
    catch (const args::Completion& e) {
        std::cout << e.what();
        return 0;
    }
    catch (const args::Help&) {
        std::cout << parser;
        return 0;
    }
    catch (const args::ParseError& e) {
        std::cerr << e.what() << std::endl;
        std::cerr << parser;
        return -1;
    }
    return 0;
}