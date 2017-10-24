#include <iostream>

int main()
{
  bool flag = true;
  double num;

  do
  {
	// if the input is a WORD, I get an error
	if(!(std::cin >> num))
	{
	  std::cout << "This is a word!" << "\n";
	  std::cout << "Enter a number!" << "\n";
	}
	// if the input is rational, I get an error
	else if(int(num) != num)
	{
	  std::cout << "This is a rational!" << "\n";
	  std::cout << "Enter an integer!" << "\n";
	}else
	  flag = false;

	/* clear and ignore are important because, if the condition in the if is not met,
	   the buffer in cin is not flushed and the loop infinitely goes (always with the error).
	   In this way, we clean the buffer and ask a new input.
	   Note the (1000, '\n'): it ignores up to 1000 characters, until a "\n" is met. */
	std::cin.clear();
	std::cin.ignore(1000, '\n');

  }while(flag);

  std::cout << "\n";
  std::cout << "Number entered correctly: " << num << "\n";

return 0;
}
