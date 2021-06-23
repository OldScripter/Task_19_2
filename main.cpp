#include <iostream>
#include <fstream>


void readFileToBuffer(std::ifstream& stream, char* buffer, const int buffer_size)
{
    do
    {
        std::string dir;
        std::cout << "Please enter the path to file:\n";
        std::getline(std::cin, dir);
        stream.open(dir, std::ios::binary);
        if (!stream.is_open())
            std::cerr << "File can't be opened - please check the path.\n";
    } while (!stream.is_open());
    std::cout << "********************* File *********************\n";
    while (!stream.eof())
    {
        stream.read(buffer, buffer_size);
        buffer[stream.gcount()] = '\0';
        std::cout << buffer;
    }
    stream.close();
    std::cout << "\n****************** End of file ******************\n";
}

int main()
{
    const int BUFFER_SIZE = 100;
    std::ifstream inputStream;
    //Use to test: ..\text_for_test.txt
    char buffer[BUFFER_SIZE];
    readFileToBuffer(inputStream, buffer, BUFFER_SIZE);

    return 0;
}
