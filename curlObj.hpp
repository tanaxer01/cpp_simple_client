
#include <iostream>
#include <vector>

#include <curl/curl.h>

class CurlObj{
private:
  long http_code;

  CURL *curl;
  std::string curlBuffer;
  
public:
  CurlObj(bool debug = false);
  ~CurlObj();

  static int curlWriter(char *data, int size, int nmemb, std::string *buffer) {
    int res = 0;
    if (buffer != NULL) {
      buffer->append(data, size*nmemb);
      // buffer->assign(data, size*nmemb);
      res = size * nmemb;
    }

    return res;
  }
  
  long Get(std::string url);

  long Get(std::string url, std::vector<std::string> header_arr);

  long Post(std::string url, std::string data);

  long Post(std::string url, std::string data, std::vector<std::string> header_arr);
  std::string getData();
  void modData(std::string input);
};
