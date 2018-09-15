#include <iostream>
#include <fstream>
using namespace std;


int main()
{
	ofstream fout;
  fout.open("borrame.txt", ios::out | ios::app);
  fout << "Fil"<<endl;
  fout.close();

return 1;
}
