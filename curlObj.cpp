#include <iostream>
#include <curl/curl.h>

class CurlObj {
private:
  CURL *curl;
  std::string curlBuffer;

public:
  CurlObj () {
    curl = curl_easy_init();
    if(!curl){
      std::cerr << "curl_easy_init() failed\n";
      delete this;
    }

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &CurlObj::curlWriter);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &curlBuffer);

  }

  ~CurlObj() {
    std::cout <<"\nCurlObj Deleted\n";
    curl_easy_cleanup(curl);
  }

  static int curlWriter(char *data, int size, int nmemb, std::string *buffer) {
    int res = 0;
    if (buffer != NULL) {
      buffer->append(data, size*nmemb);
      res = size * nmemb;
    }

    return res;
  }

  void sendRequest(std::string url) {
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

    CURLcode res = curl_easy_perform(curl);
    if(res != CURLE_OK) {
      std::cerr << "curl_easy_perform() failed: " <<curl_easy_strerror(res);
    }
  }

  std::string getData() {
    return curlBuffer;
  }

  void modData(std::string input) {
    curlBuffer = input;
  }

};


// int main() {
//   CurlObj *a = new CurlObj();
//   a->sendRequest("https://asdfg.free.beeceptor.com");
//   std::cout<< a->getData() <<"\n";

//   a->modData("");
//   a->sendRequest("https://asdfg.free.beeceptor.com/test");
//   std::cout<< a->getData() <<"\n";


//   delete a;
//   return 0;
// }
