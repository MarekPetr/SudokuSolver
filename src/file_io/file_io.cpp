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
        }
        infile.close();
    } else {
        std::string error = Formatter() << "Unable to open file: " << filename;
        throw(FileIOException(error));
    }
    return std::string();
}

void FileIO::save(std::string &content) {

}

FileIOException::FileIOException(const std::string &msg) {

}


const char *FileIOException::what() const noexcept
{
    return this->message.c_str();
}

