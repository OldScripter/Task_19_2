#include <iostream>
#include <fstream>
#include <cassert>

/*
 *  Read file from ifstream to buffer and close the stream.
 */
void readFile(std::ifstream& stream, char* buffer, const int buffer_size)
{
    assert(stream.is_open());
    std::cout << "********************* File *********************\n";
    while (!stream.eof())
    {
        stream.read(buffer, buffer_size);
        if (stream.gcount() < buffer_size)
        {
            buffer[stream.gcount()] = '\0';
        }
        std::cout << buffer;
    }
    stream.close();
    std::cout << "\n****************** End of file ******************\n";
    return;
}

/*
 *  Ask user for directory and open the ifstream.
 */
void initializeFileStream(std::ifstream& stream)
{
    assert(!stream.is_open());
    do {
        std::string dir;
        std::cout << "Please enter the path to file:\n";
        std::getline(std::cin, dir);
        stream.open(dir, std::ios::binary);
        if (!stream.is_open()) std::cout << "File can't be opened - please check the path.\n";
    } while (!stream.is_open());
    std::cout << "File is found\n";
    return;
}

int main() {
    const int BUFFER_SIZE = 100;
    std::ifstream input_stream;

    //Path input:
    //Use to test: ..\text_for_test.txt
    initializeFileStream(input_stream);

    char buffer[BUFFER_SIZE];
    readFile(input_stream, buffer, BUFFER_SIZE);

    return 0;
}
