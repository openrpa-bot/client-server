#pragma once
#include <fstream>
#include ".\protoclasses\service.pb.h"

class protoseriolised
{
public:
	static void deseriolised(std::string result);
	static std::string seriolised(algorithm::Request request);
	static std::string seriolised(int a, int b);
	static bool seriolised(int a, int b, void** data, int& size);
};

