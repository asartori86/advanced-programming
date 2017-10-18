#include<iostream>
#include<string>

void newline() {std::cout << std::endl;}

int main()
{
  int unsigned cont = 1;
  std::string line;
  std::string old_line;
  getline(std::cin, old_line);
  while(std::getline(std::cin,line))
  {
	if (line.compare(old_line) != 0){
	  std::cout << cont << " " << old_line;
	  newline();
	  cont = 1;}
	else
	  cont++;

	old_line = line;
  }
  //last line, which was ignored in the while loop
  std::cout << cont << " " << old_line;
  newline();

  return 0;
}
