#include <iostream>
#include <vector>

#include "curlObj.hpp"
// #include "jsonParsing.hpp"

int main() {
  std::cout<<"START\n";
  CurlObj *a = new CurlObj();

  // HTTP Request
  std::vector<std::string> headers {
    "accept: application/json",
    "Notion-Version: 2022-06-28",
    "content-type: application/json",
    "authorization: Bearer secret_24HWAknnpVQIRKGNmRNv2PllffnbIrpWh3BfDjTZ6HO"
  };

  long b = a->Get("https://api.notion.com/v1/blocks/cf33ad4bc76440f1a568e7e4cd5281c5/children", headers);

  // parse_n_print("Hola");
  
  delete a;
  return 0;
}
