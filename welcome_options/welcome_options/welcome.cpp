#include <iostream>
#include <string>
using namespace std;

void usage(const string& cmd)
{
    string opt[] = {
        "where\n",
        "-h host     the host name.\n",
        "-v guest    the guest name.\n",
        "-? guide    the manuel of using this CLI.\n",
    };

    cout << "Usage; \n";
    cout << "" << cmd << " -h host -v guest\n";
    for (int i = 0; i < (sizeof(opt)) / sizeof(string); i++)
        cout << opt[i];
    exit(-1);
}

void error(const string& msg)
{
    cerr << "Error:\n " << msg << endl;
}

int main(int argc, char* argv[])
{
    string host;
    string guest;
    string quest = argv[1];
    if (argc < 5 || argc>5)
    {
        if (argc==2&&quest == "-?") {
            usage(argv[0]);
        }
        else
        {
            error("Wrong Value. You can only input 2 names.");
            usage(argv[0]);
        }
    }
    else
    {
        string vox = argv[1];
        if (vox == "-v") {
            error("Wrong Value. Please input the value of -h first");
            usage(argv[0]);
        }
        else {
            for (int i = 1; i < argc; i = i + 2)
            {
                string arg = argv[i];
                if (arg == "-h") {
                    host = argv[i + 1];
                }
                else if (arg == "-v") {
                    guest = argv[i + 1];
                    cout << "Hello!! " << guest << ". Welcome to " << host << "'s house. " << endl;
                }
                else {
                    error("Unknown options: " + arg);
                    usage(argv[0]);
                }
            }
        }
    }
    return 0;
}

