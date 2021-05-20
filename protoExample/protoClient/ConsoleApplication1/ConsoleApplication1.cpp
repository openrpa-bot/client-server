// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define CURL_STATICLIB
#include <iostream>
#include <string>

#include <curl.h>
#include ".\protoclasses\service.pb.h"
#include "protoseriolised.h"


static size_t my_write(void* buffer, size_t size, size_t nmemb, void* param)
{
	std::string& text = *static_cast<std::string*>(param);
	size_t totalsize = size * nmemb;
	text.append(static_cast<char*>(buffer), totalsize);
	return totalsize;
}

int main()
{
	int size = 0 ;
	char* data = NULL;

	protoseriolised::seriolised(5, 6, (void **)&data, size);
	//printf("%d, %d, %d, %d, %d, %d, %d, %d\n", data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7]);
	//printf("%d, %d\n", ((long *)data)[0], ((long*)data)[1]);
	char* dataToSend = new char[size + 12]();
	memcpy(dataToSend,"byteRequest=",12);
	memcpy(dataToSend+12, data, size);
	//size = 12; //"byteRequest="

	std::string url = "http://localhost:8338/AdditionRequest";//?request=" + protoseriolised::seriolised(2, 3);
	//url = "http://localhost:8338/AddMe?x=1&y=2";
	//url = "http://localhost:8338/AddMe";
	//url =  + std::string(data);
	//char cUrl[1000] = "http://localhost:8338/AR?request=";
	char cUrl[1000] = "http://localhost:8338/AR";
	//strcat_s(cUrl, data);
	std::string result;
	CURL* curl;
	CURLcode res;
	curl_global_init(CURL_GLOBAL_DEFAULT);
	curl = curl_easy_init();
	if (curl) {
		//curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:8338");
		curl_easy_setopt(curl, CURLOPT_URL, cUrl);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, my_write);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);
		curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE_LARGE, size);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, size);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, dataToSend);
		
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
		if (CURLE_OK != res) {
			std::cerr << "CURL error: " << res << '\n';
		}
	}
	curl_global_cleanup();
	protoseriolised::deseriolised(result);
}

