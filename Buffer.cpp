#include <iostream>
 #include <fstream>
 #include <vector>
 #include <chrono>
using namespace std;
 using namespace chrono;
 void transferWithoutBuffer(const string&
inputFile, const string& outputFile)
 {
    ifstream in(inputFile, ios::binary);
    ofstream out(outputFile, ios::binary);
    if (!in || !out) {
        cerr << "Error opening files!" << endl;
        return;
    }
    char ch;
    while (in.get(ch)) {
        out.put(ch);
    }
    in.close();
    out.close();
 }
 void transferWithBuffer(const string&
inputFile, const string& outputFile, size_t
bufferSize)
 {
    ifstream in(inputFile, ios::binary);
    ofstream out(outputFile, ios::binary);
    if (!in || !out) {
        cerr << "Error opening files!" << endl;
        return;
    }
    vector<char> buffer(bufferSize);
    while (in.read(buffer.data(),
buffer.size())) {
        out.write(buffer.data(), in.gcount());
    }
    out.write(buffer.data(), in.gcount());
    in.close();
    out.close();
 }
 int main()
 {
    string inputFile = "input.txt";
    string outputFile1 =
"output_no_buffer.txt";
    string outputFile2 =
"output_with_buffer.txt";
    size_t bufferSize = 4096;
    auto start =
high_resolution_clock::now();
    transferWithoutBuffer(inputFile,
outputFile1);
    auto end = high_resolution_clock::now();
    cout << "Transfer time without Buffer: "
<< duration<double>(end - start).count()
<< " second\n";
    start = high_resolution_clock::now();
    transferWithBuffer(inputFile,
outputFile2, bufferSize);
    end = high_resolution_clock::now();
    cout << "Transfer time with Buffer: " <<
duration<double>(end - start).count() << "second\n";

    return 0;
    }
