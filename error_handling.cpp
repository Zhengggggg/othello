#include <iostream>
#include "error_handling.h"
using namespace std;

error_handling::error_handling(string s)
{
	msg = s;
}

string error_handling::getMessage()
{
	return msg;
}