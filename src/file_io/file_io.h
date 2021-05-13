//
// Created by petr on 08.05.21.
//

#ifndef SUDOKU_FILE_IO_H
#define SUDOKU_FILE_IO_H


#include <string>

class FileIO {
public:
    static std::string load(const char *filename);

    static void save(std::string &content);
};

class FileIOException : std::exception{
public:
    explicit
    FileIOException(const std::string &msg) {
        message = msg;
    };
    ~FileIOException() override = default;
    [[nodiscard]] const char* what() const noexcept override;
private:
    std::string message;
};


#endif //SUDOKU_FILE_IO_H