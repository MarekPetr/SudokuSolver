//
// Created by petr on 08.05.21.
//

#include <fstream>
#include "file_io.h"
#include "../utils.h"

std::string FileIO::load(const char *filename) {
    std::string result;
    std::string line;
    std::ifstream infile(filename);
    if (infile.is_open()) {
        while (getline(infile, line)) {
            result.append(line);
            result.append("\n");
        }
        infile.close();
    } else {
        std::string error = Formatter() << "Unable to open file: " << filename;
        throw(FileIOException(error));
    }
    return result;
}
