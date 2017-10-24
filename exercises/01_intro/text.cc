#include <iostream>
#include <string>
#include <fstream>

int main()
{
  unsigned int const	line_limit = 100;
  unsigned int 	word_length, line_length = 0;
  std::string 	word;

  std::ofstream myfile;
  myfile.open ("text_formatted.txt");

  while(std::cin >> word)
  {
	word_length = word.length();
	line_length += word_length;

	if(line_length > line_limit)
	{
	  myfile << std::endl;
	  line_length = word_length;
	}

	myfile << word << " ";
  }

  myfile.close();

return 0;
}
