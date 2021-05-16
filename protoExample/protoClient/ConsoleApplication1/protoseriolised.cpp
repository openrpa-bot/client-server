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