#include "curlObj.hpp"

CurlObj::CurlObj(bool debug) {
  http_code = 0;

  curl = curl_easy_init();
  if(!curl){
    std::cerr << "curl_easy_init() failed\n";
    delete this;
  }

  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &CurlObj::curlWriter);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &curlBuffer);

  if(debug == true) curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
}

CurlObj::~CurlObj() {
  std::cout <<"\nCurlObj Deleted\n";
  curl_easy_cleanup(curl);
}
  
long CurlObj::Get(std::string url) {
  curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

  CURLcode res = curl_easy_perform(curl);
  if(res != CURLE_OK) {
    std::cerr << "curl_easy_perform() failed: " <<curl_easy_strerror(res);
  }

  curl_easy_getinfo (curl, CURLINFO_RESPONSE_CODE, &http_code);
  return http_code;
}

long CurlObj::Get(std::string url, std::vector<std::string> header_arr) {
  struct curl_slist *headers = NULL;

  for(std::string s: header_arr)
    headers = curl_slist_append(headers, s.c_str());

  curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
  curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

  CURLcode res = curl_easy_perform(curl);
  if(res != CURLE_OK) {
    std::cerr << "curl_easy_perform() failed: " <<curl_easy_strerror(res);
  }

  curl_slist_free_all(headers);
  return http_code;
}

long CurlObj::Post(std::string url, std::string data) {
  curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
  curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");

  this->Get( url );
  curl_easy_reset( this->curl );

  return http_code;
}

long CurlObj::Post(std::string url, std::string data, std::vector<std::string> header_arr) {
  curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
  curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");

  this->Get( url, header_arr );
  curl_easy_reset( this->curl );

  return http_code;
}

std::string CurlObj::getData() {
  return curlBuffer;
}
  
void CurlObj::modData(std::string input) {
  curlBuffer = input;
}

