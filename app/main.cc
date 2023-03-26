#include <iostream>
#include "pstream.h"

int main()
{
    // get the current working directory
    // redi::ipstream in("pwd", redi::pstream::pstdout);
    // std::string dir;

    // std::getline(in.out(), dir);

    // in.close();

    const redi::pstreams::pmode mode = redi::pstreams::pstdout | redi::pstreams::pstderr;
    redi::ipstream run("./sheller 23", mode);
    std::string output;

    while (std::getline(run.out(), output))
        std::cout << output << std::endl;

    run.clear();

    while (std::getline(run.err(), output))
        std::cout << output << std::endl;

    run.close();

    return 0;
}