/*
    File Stream Classes: ifstream, ofstream, fstream
    
    A) ifstream (Input File Stream) - Read from files
       --------------------------------------------------
       Constructor:
         ifstream(const string& filename, ios::openmode mode = ios::in);
         ifstream file("input.txt");
       
       Member functions:
         - open(const string& filename, ios::openmode mode = ios::in)
         - close()
         - is_open()
         - eof()                   // End of file?
         - fail()                  // Any error?
         - good()                  // Everything OK?
         - bad()                   // Serious error?
         - clear()                 // Reset error flags
         - get()                   // Read single character
         - get(char& c)
         - getline(string& str, char delim = '\n')
         - read(char* buffer, streamsize count)
         - seekg(pos_type pos)     // Set read position
         - seekg(off_type offset, seekdir dir)
         - tellg()                 // Get read position
         - ignore(streamsize count, char delim = EOF)
         - peek()                  // Peek next character without reading
         - putback(char c)         // Put character back
         - operator>>              // Extract operator (formatted input)
         - operator bool()         // Check if stream is good
    
    B) ofstream (Output File Stream) - Write to files
       --------------------------------------------------
       Constructor:
         ofstream(const string& filename, ios::openmode mode = ios::out);
         ofstream file("output.txt");
       
       Member functions:
         - open(const string& filename, ios::openmode mode = ios::out)
         - close()
         - is_open()
         - fail()
         - good()
         - bad()
         - clear()
         - put(char c)             // Write single character
         - write(const char* buffer, streamsize count)
         - seekp(pos_type pos)     // Set write position
         - seekp(off_type offset, seekdir dir)
         - tellp()                 // Get write position
         - flush()                 // Flush output buffer
         - operator<<              // Insert operator (formatted output)
    
    C) fstream (File Stream) - Read and Write
       --------------------------------------------------
       Constructor:
         fstream(const string& filename, ios::openmode mode);
         fstream file("data.txt", ios::in | ios::out);
       
       Combines all ifstream and ofstream functions.
       Can read and write to same file (requires ios::in | ios::out).
    
    D) Open Modes (use | to combine)
       --------------------------------------------------
       - ios::in              // Open for reading (ifstream default)
       - ios::out             // Open for writing, truncate (ofstream default)
       - ios::app             // Append mode, write at end
       - ios::ate             // Open and seek to end immediately
       - ios::binary          // Binary mode (default is text)
       - ios::trunc           // Truncate file if exists (out default)
    
       Examples:
         ifstream in("file.txt");                    // Read only
         ofstream out("file.txt");                   // Write (truncate)
         ofstream app("file.txt", ios::app);        // Append
         fstream rw("file.txt", ios::in | ios::out); // Read/Write
         ifstream bin("data.bin", ios::binary);     // Binary read
    
    E) Error Handling
       --------------------------------------------------
       After open or read/write operations:
         if (!file.is_open())   // file didn't open
         if (file.fail())       // operation failed
         if (file.bad())        // serious error
         if (file.eof())        // reached end
         if (file.good())       // all OK
         
       Standard approach:
         ifstream file("input.txt");
         if (!file) {
             cerr << "Cannot open file" << endl;
             return -1;
         }
    
    F) Seek Direction (for seekg/seekp)
       --------------------------------------------------
       - ios::beg             // Beginning of file
       - ios::cur             // Current position
       - ios::end             // End of file
       
       Examples:
         file.seekg(0, ios::beg);        // Go to start
         file.seekg(-10, ios::end);      // 10 bytes before end
         file.seekp(0, ios::end);        // Go to end for append
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    // Create and open a text file
    fstream MyFile("filename.txt");

    // Write to the file
    MyFile << "Files can be tricky, but it is fun enough!";

    // Read from the file
    string myText;
    getline(MyFile, myText);
    cout << myText;
    

    // Close the file
    MyFile.close();
}