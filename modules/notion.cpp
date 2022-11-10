#include "../jsonParsing.hpp"
#include "../curlObj.hpp"

class NotionModule {
private:
  CurlObj* rqst;


public:
  NotionModule(bool debug = false) {
    rqst = new CurlObj(debug);

  }

  void retrievePage() {
    rqst->Get();
  }


};
