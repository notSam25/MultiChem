#include "Include/args.hpp"
#include "Include/common.hpp"

#include "ghc/filesystem.hpp"
#include <nlohmann/json.hpp>

int main(int argc, char **argv)  {
    // make sure ghc::filesystem works
    std::cout << "current path: " << ghc::filesystem::current_path() << std::endl;

    Common::PrintSystemInformation();

    args::ArgumentParser parser("MultiChem by @notSam25", "Thanks for building!");
    args::HelpFlag help(parser, "help", "Display this help menu", {'h', "help"});
    args::Group commands(parser, "Commands");
    args::Command add(commands, "path", "path to JSON file");
    
    try {
        parser.ParseCLI(argc, argv);
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