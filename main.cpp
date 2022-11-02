#include <iostream>
#include <vector>

#include "curlObj.cpp"
// #include "rapidjson/document.h"
//#include "jsonParsing.cpp"

int main() {
  CurlObj *a = new CurlObj(true);
  std::vector<std::string> headers {
    "Content-Type: application/json",
    "X-Apple-OAuth-Client-Id: d39ba9916b7251055b22c7f910e2ea796ee65e98b2ddecea8f5dde8d9d1a815d",
    "X-Apple-OAuth-Client-Type: firstPartyAuth",
    "X-Apple-OAuth-Redirect-URI: https://www.icloud.com",
    "X-Apple-OAuth-Require-Grant-Code: true",
    "X-Apple-OAuth-Response-Mode: web_message",
    "X-Apple-OAuth-Response-Type: code",
    //"X-Apple-OAuth-State":              {fmt.Sprintf("auth-%s", uuid.New().String())},
    "X-Apple-Widget-Key: d39ba9916b7251055b22c7f910e2ea796ee65e98b2ddecea8f5dde8d9d1a815d",
    "Origin: https://www.icloud.com",
    "Referer: https://www.icloud.com/",
  };

  // long b = a->Post("https://curlql.free.beeceptor.com", "");
  long b = a->Post("https://idmsa.apple.com/appleauth/auth/signin?isRememberMeEnabled=true", "user=jpbrione&password=P!LL!Ngatuno101&rememberMe=True&trustedTokens=[]", &headers);
  std::cout<<b <<"\n" <<a->getData() <<"\n";

  // a->Get("https://asdfg.free.beeceptor.com/test");
  // a->sendRequest("https://idmsa.apple.com/appleauth/auth/signin?isRememberMeEnabled=true");
  // std::cout<< a->getData() <<"\n";
  // std::cout<<"ENDED";

  // rapidjson::Document document;
  // if (document.Parse(a->getData().c_str()).HasParseError()) {
    // std::cerr<<"Error on parse\n";
    // return -1;
  // }

  // std::cout<<document["status"].GetString() <<"\n";

  delete a;
  return 0;
}
