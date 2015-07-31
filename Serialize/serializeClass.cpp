//http://www.careercup.com/question?id=5979667
//http://www.careercup.com/question?id=5676446924144640
//http://www.careercup.com/question?id=3507065

//http://stackoverflow.com/questions/2602013/read-whole-ascii-file-into-c-stdstring

#include <iostream>
#include <vector>
#include <string>

#include <fstream>

#include <sstream>

//#include <stdio.h>
using namespace std;

//http://stackoverflow.com/questions/4533063/how-does-ifstreams-eof-work

class MySerialClass
{
	//typedef vector<string> list;

	public:
		void serialize(vector<string> const&l)
		{
			//iterate through char in string - check for special chars e.g. \n " \r \
			//append second \ for special char
			// e.g. hello my \n name => hello my \\n name

			ofstream out("out.txt", ios::out);

			int len = l.size();
			for (int i=0; i<len; i++)
				out << l[i].size() << "|" << l[i];		
			//for (vector<string>::const_iterator iter = l.begin(); iter != l.end(); iter++)
			//	out << (*iter).size() << "|" << *iter;
			out.close();
		}

		vector<string> deserialize()
		{
			vector<string> deserializedOutput;
			ifstream in("out.txt", ios::in);
			if (in.is_open())
			{
				size_t length;
				char   sep    = '|';

				// Use the stream operators to get the size (and separator)
				// Much nicer than using tha atoi() function.
				//
				string data;
				while ((in >> length >> sep) && (sep == '|'))
				{
					// Resize the string to the correct size and put the word into it.
					data.resize(length);
					in.read(&data[0], length);

					deserializedOutput.push_back(data);
				}
			}
			return deserializedOutput;
		}

		vector<string> deserialize(std::stringstream &in)
		{
			vector<string> deserializedOutput;
			if (!in.eof())
			{
				size_t length = -1;
				char   sep    = '|';

				// Use the stream operators to get the size (and separator)
				// Much nicer than using tha atoi() function.
				//
				string data;
				while ((in >> length >> sep) && (sep == '|'))
				{
					// Resize the string to the correct size and put the word into it.
					data.resize(length);
					in.read(&data[0], length);

					deserializedOutput.push_back(data);
				}
			}
			return deserializedOutput;
		}

		vector<string> deserialize(string &inS)
		{
			vector<string> deserializedOutput;
			{
				string data;
				size_t length;
				char   sep    = '|';

				size_t pos = inS.find(sep);
				while (pos != std::string::npos)
				{
					length = atoi(inS.substr(0, pos).c_str());			
					data = inS.substr(pos + 1, length);
					inS = inS.substr(pos + data.size() + 1); //From pos + data.size() + 1 to end of the string.

					deserializedOutput.push_back(data);
					pos = inS.find(sep);
				}
			}
			return deserializedOutput;
		}
};

/*
http://stackoverflow.com/questions/10789740/passing-stdstring-by-value-or-reference

1) Using the string as an id (will not be modified). Passing it in by const reference is probably the best idea here: (std::string const&)

2) Modifying the string but not wanting the caller to see that change. Passing it in by value is preferable: (std::string)

3) Modifying the string but wanting the caller to see that change. Passing it in by reference is preferable: (std::string &)

4) Sending the string into the function and the caller of the function will never use the string again. Using move semantics might be an option (std::string &&)

*/

void function(string &s)
{
	s = "There";
}

int main()
{
	string test = "test";
	function(test);

	MySerialClass serial;

	/* Input
	 */
	//vector<string> input;
	//string tmp;
	//while (cin >> tmp) // Read input from cin
	//    input.push_back(tmp);
	//serial.serialize(input);

	/* Output
	 */
	vector<string> deserializedOutput;
	// 1) 
	//deserializedOutput = serial.deserialize();
	
	ifstream in("out.txt");
	
	/*
	in.seekg(0, std::ios::end);
	size_t size = in.tellg();
	in.seekg(0);
	string buffer(size, ' ');
	in.read(&buffer[0], size);
	// 2)
	deserializedOutput = serial.deserialize(buffer);
	*/

	//http://stackoverflow.com/questions/132358/how-to-read-file-content-into-istringstream
	//*** NOTE BELOW LINK ***
	//http://stackoverflow.com/questions/1494182/setting-the-internal-buffer-used-by-a-standard-stream-pubsetbuf

	/*
     * Create your string stream.
     * Get the stringbuffer from the stream and set the vector as it source.
     */
    std::stringstream       localStream;
	/* If you are trying to copy in the data via the above in.read method into a std string
	 * However pubsetbuf has no effect in VS.
	 *
	 * std::vector<char> buffer(size); // read into a char vector
	 * in.read(&buffer[0], size);
	 *
	 * localStream.rdbuf()->pubsetbuf(&buffer[0],size);
	 */
	localStream << in.rdbuf(); // *** SLOW *** operator<< will read the filebuf character by character
	deserializedOutput = serial.deserialize(localStream);

	int len = deserializedOutput.size();
	for (int i=0; i<len; i++)
		cout << deserializedOutput[i] << endl;;
		
	return 0;
}