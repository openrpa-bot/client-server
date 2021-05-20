#include <iostream>
#include <fstream>
#include <string>
#include "protoseriolised.h"
#include ".\protoclasses\service.pb.h"

using namespace std;
void protoseriolised::deseriolised(std::string result) {
	GOOGLE_PROTOBUF_VERIFY_VERSION;

	algorithm::Response responce;

	if (!responce.ParseFromString(result)) {
		cerr << "Failed to parse address book." << endl;
		return;
	}

	std::cout << "\n\n" << "deseriolised result: " << responce.result() << "\n\n";
	google::protobuf::ShutdownProtobufLibrary();
}

std::string protoseriolised::seriolised(algorithm::Request request) {
	return request.SerializeAsString();
}

std::string protoseriolised::seriolised(int a, int b) {
	algorithm::Request request;
	request.set_a(a);
	request.set_a(b);
	return request.SerializeAsString(); 

}
std::string protoseriolised::seriolised(int a, int b, void **data, int &size ) {
	algorithm::Request request, request1;
	request.set_a(a);
	request.set_b(b);
	size = request.ByteSizeLong()* sizeof(long);
	*data = new long[size]();	
	request.SerializeToArray(*data, size);
	request1.ParseFromArray(*data, size);
	return request.SerializeAsString();;
	}
std::string protoseriolised::seriolisedAsString(int a, int b) {
	algorithm::Request request, request1;
	request.set_a(a);
	request.set_b(b);
	return request.SerializeAsString();
}