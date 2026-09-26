#include<iostream>
#include<fcntl.h> // open() aur uske flags (O_WRONLY, O_CREAT) ke liye
#include<unistd.h> // write() aur close() ke liye
#include<cstring> // strlen() ke liye
using namespace std;

int main(){
    // 1. File open (ya create) karna
    // O_WRONLY : Sirf write karne ke liye kholo
    // O_CREAT  : Agar file exist nahi karti, toh nayi bana do
    // O_TRUNC  : Agar file pehle se hai, toh uska purana data mita do
    // 0644     : Nayi file ki Linux permissions (Owner ko Read/Write, baakiyo ko sirf Read)
    int fd = open("systemcall.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if(fd == -1){
        cout << "Error: File open ya create nahi ho payi!" << endl;
        return 1;
    }
        
    cout << "Success: File open ho gayi. System ne File Descriptor diya hai: " << fd << endl;

    // 2. Data likhna (Write)
    const char* data = "Hello, yeh data direct C++ OS system calls ke through likha gaya hai!\n";

    // write(file_descriptor, data_array, kitne_bytes_likhne_hai)
    // ssize_t bas ek data type hai jo bytes ka count ya error (-1) store karta hai
    ssize_t bytesWritten = write(fd, data, strlen(data));

    if (bytesWritten == -1) {
        cout << "Error: File mein data write nahi ho paya." << endl;
        close(fd); // Error aane par bhi file close karna zaroori hai
        return 1;
    }

    cout << "Success: " << bytesWritten << " bytes file mein likh diye gaye." << endl;

    // 3. File close karna
    close(fd);
    cout << "Success: File safely close ho gayi aur memory free ho gayi." << endl;

    return 0;
}