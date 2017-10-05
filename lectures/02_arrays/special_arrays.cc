#include <iostream>

void print_ma(int m[][4], int dim1); // ugly and not flexible
// void print_ma(int m[][], int dim1, int dim2); // error second
					         // dimension must be
                                                 // knwon at compile time

void print_ma(int *p, int dim1, int dim2); // the only possible solution

void print_args(int argc, char*argv[])
{
  (void)argc;
  (void)argv;
}

int main()
{
  int ma[3][4];

  for(int i=0; i<3; ++i)
    for(int j=0; j<4; ++j)
      ma[i][j] = 10*i+j;

  for(int i=0; i<3; ++i)
    {    for(int j=0; j<4; ++j)
	std::cout << &ma[i][j] << " ";
      std::cout << std::endl;
    }

    // int *pma = ma; 		// error
    // int *pma[4] = ma;		// error
  int *p = &ma[0][0];  

    for(int i=0; i<3; ++i)
    {    for(int j=0; j<4; ++j)
	std::cout << p[i*4+j] << " ";
      std::cout << std::endl;
    }

    char ** argv{};
    print_args(2,argv);
  return 0;
}
