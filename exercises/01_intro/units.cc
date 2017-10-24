#include <iostream>
#include <string>

int main()
{
  unsigned int const dim = 3;
  std::string const units[dim] = {"inches", "miles", "angstrom"};
  double const conversion[dim] = {0.0254, 1609.34, 1.0e-10};

  bool 		flag_exit = true;
  unsigned int 	i = 0;
  double 	val_in, val_converted;
  std::string 	unit_in;

  std::cout << "Insert a measurement to convert: ";
  std::cin >> val_in >> unit_in;

  do
  {
	if( !(unit_in.compare(units[i])) )
	{
	  std::cout << i << std::endl;
	  val_converted = conversion[i] * val_in;
	  flag_exit = false;
	}
  }while(flag_exit && ++i < dim);

  if(flag_exit == false)
	std::cout << "Converted value = " << val_converted << " m\n";
  else
	std::cout << "Measure unit not recognized!\n";

  return 0;
}
