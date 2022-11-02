#include <iostream>

#include "curlObj.cpp"
#include "rapidjson/document.h"
//#include "jsonParsing.cpp"

int main() {
  CurlObj *a = new CurlObj();
  a->sendRequest("https://asdfg.free.beeceptor.com");
  std::cout<< a->getData() <<"\n";


  a->modData("");
  a->sendRequest("https://asdfg.free.beeceptor.com/test");
  std::cout<< a->getData() <<"\n";

  rapidjson::Document document;
  if (document.Parse(a->getData().c_str()).HasParseError()) {
    std::cerr<<"Error on parse\n";
    return -1;
  }

  std::cout<<document["status"].GetString() <<"\n";

  delete a;
  return 0;
}
