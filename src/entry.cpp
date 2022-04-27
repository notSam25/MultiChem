#include "Include/args/args.hxx"
#include "Include/cpp-header/src/common.hpp"
#include <cstring>
using Debug = Common::Debug;
Debug Dbg;

#include "ghc/filesystem.hpp"
#include <nlohmann/json.hpp>

int main(int argc, char **argv)  {
    // make sure ghc::filesystem works
    std::cout << "current path: " << ghc::filesystem::current_path() << std::endl;

    Common::PrintSystemInformation();
    if(strcmp(Common::GetOperatingSystemName(), "linux")) {
    Dbg.LogData(Debug::LogType::Error, "Unsupported Operating System");
    return 0;
    }
    args::ArgumentParser parser("MultiChem by @notSam25", "Thanks for building!");
    args::HelpFlag help(parser, "help", "Display this help menu", {'h', "help"});
    args::Group commands(parser, "Commands");
    args::ValueFlag<std::string> message(parser, "MESSAGE", "commit message", {'m'});
    try {
        parser.ParseCLI(argc, argv);
        if(message) {
            std::cout << "Path: " << args::get(message) << std::endl;
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