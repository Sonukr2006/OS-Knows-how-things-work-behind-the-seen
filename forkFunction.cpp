#include<iostream>
#include<unistd.h>
using namespace std;

int main(){

    pid_t p = fork();

    if(p < 0)
        cout << "Fork fail." << '\n';
    else if(p == 0)
        cout << "Child process return 0 value." << '\n';
    else
        cout << "Parent process return child process id(pid)." << '\n';

    return 0;
}