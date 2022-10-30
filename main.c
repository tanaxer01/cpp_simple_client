#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "util.h"

CURL *setup_handle(char *url, struct MemoryStruct *chunk) {
  CURL *curl_handle = curl_easy_init();
  if( curl_handle == NULL ) {
    fprintf(stderr, "error on curl_easy_init\n");
    return NULL;
  }
  
  curl_easy_setopt(curl_handle, CURLOPT_URL, url);
  curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1L);
  curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
  curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)chunk);
  curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");

  return curl_handle;
}


int main(int argc, char *argv[]) {
  if( argc != 2 ) {
    printf("usage: try './curl [url]' to make a get request.\n");
    return 1;
  }

  CURL *curl_handle;
  CURLcode res;

  struct MemoryStruct chunk;
  chunk.memory = malloc(1);  
  chunk.size = 0;

  curl_handle = setup_handle(argv[1], &chunk);

  for(int i =0;i<2;i++) {
    res = curl_easy_perform(curl_handle);

    if(res != CURLE_OK) {
      fprintf(stderr, "error: %s\n", curl_easy_strerror(res));
    } else {
      printf("Size: %lu\n", (unsigned long)chunk.size);
      printf("Data: %s\n", chunk.memory);
    }

    curl_easy_setopt(curl_handle, CURLOPT_URL, "https://pokeapi.co/api/v2/gender/3/");
    chunk.memory = malloc(1);  
    chunk.size = 0;
  }

  curl_easy_cleanup(curl_handle);
  free(chunk.memory);
 
  return 0;
}
