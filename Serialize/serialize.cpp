#if 1
//http://stackoverflow.com/questions/2602013/read-whole-ascii-file-into-c-stdstring

//http://codereview.stackexchange.com/questions/4593/serialization-unserialization-of-a-list-of-strings-c

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
    std::vector<std::string> input;

    std::string tmp;
    while (std::cin >> tmp)
    {
        input.push_back(tmp);
    }

    std::ofstream out("out.txt", std::ios::out);
    for (std::vector<std::string>::const_iterator iter = input.begin();
         iter != input.end();
         ++iter)
    {
        out << (*iter).size() << "|" << *iter;
    }
    out.close();

    std::vector<std::string> output;
    std::ifstream in("out.txt", std::ios::in);
    if (in.is_open())
    {
        std::string tmp;
        if (!in.eof())
        {
            getline(in, tmp);
            size_t pos;
            int length = 0;
            std::string str;

            while (!tmp.empty())
            {
                pos = tmp.find('|');
                if (pos != std::string::npos)
                {
                    length = atoi(tmp.substr(0, pos).c_str());
                    str = tmp.substr(pos+1, length);     
                    tmp = tmp.substr(pos+str.size() + 1);

                    output.push_back(str);
                }
            }
        }

        in.close();
    }

    for (std::vector<std::string>::const_iterator iter = output.begin();
         iter != output.end();
         ++iter)
    {
        std::cout << *iter << "\n";
    }

    return 0;
}
#endif

#if 0

//http://stackoverflow.com/questions/16543519/serialization-of-struct

#include <iostream>
#include <cstring>

#define BUFSIZE 512
#define PACKETSIZE sizeof(MSG)

using namespace std;

typedef struct MSG
{
    int type;
    int priority;
    int sender;
    char message[BUFSIZE];
}MSG;

void serialize(MSG* msgPacket, char *data);
void deserialize(char *data, MSG* msgPacket);
void printMsg(MSG* msgPacket);

int main()
{
    MSG* newMsg = new MSG;
    newMsg->type = 1;
    newMsg->priority = 9;
    newMsg->sender = 2;
    strcpy(newMsg->message, "hello from server\0");
    printMsg(newMsg);

    char data[PACKETSIZE];

    serialize(newMsg, data);

    MSG* temp = new MSG;
    deserialize(data, temp);
    printMsg(temp);

    return 0;
}

void serialize(MSG* msgPacket, char *data)
{
    int *q = (int*)data;    
    *q = msgPacket->type;       q++;    
    *q = msgPacket->priority;   q++;    
    *q = msgPacket->sender;     q++;

    char *p = (char*)q;
    int i = 0;
    while (i < BUFSIZE)
    {
        *p = msgPacket->message[i];
        p++;
        i++;
    }
}

void deserialize(char *data, MSG* msgPacket)
{
    int *q = (int*)data;    
    msgPacket->type = *q;       q++;    
    msgPacket->priority = *q;   q++;    
    msgPacket->sender = *q;     q++;

    char *p = (char*)q;
    int i = 0;
    while (i < BUFSIZE)
    {
        msgPacket->message[i] = *p;
        p++;
        i++;
    }
}

void printMsg(MSG* msgPacket)
{
    cout << msgPacket->type << endl;
    cout << msgPacket->priority << endl;
    cout << msgPacket->sender << endl;
    cout << msgPacket->message << endl;
}

#endif

int main()
{

}