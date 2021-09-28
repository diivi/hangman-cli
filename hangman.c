#include <curl/curl.h>
#include <jansson.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct string {
  char *ptr;
  size_t len;
};

void init_string(struct string *s) {
  s->len = 0;
  s->ptr = malloc(s->len + 1);
  if (s->ptr == NULL) {
    fprintf(stderr, "malloc() failed\n");
    exit(EXIT_FAILURE);
  }
  s->ptr[0] = '\0';
}

size_t writefunc(void *ptr, size_t size, size_t nmemb, struct string *s) {
  size_t new_len = s->len + size * nmemb;
  s->ptr = realloc(s->ptr, new_len + 1);
  if (s->ptr == NULL) {
    fprintf(stderr, "realloc() failed\n");
    exit(EXIT_FAILURE);
  }
  memcpy(s->ptr + s->len, ptr, size * nmemb);
  s->ptr[new_len] = '\0';
  s->len = new_len;

  return size * nmemb;
}

int main(int argc, char *argv[]) {

  if (argc != 3) {
    printf("\033[0;32m");
    printf("\nUsage: %s <genre> <difficulty>\n\n", argv[0]);
    printf("\033[0;36m");
    printf(
        "----------------------------Genre----------------------------\n\n(1 "
        "word str) - Words related to this genre/topic will be fetched\n\n");
    printf("\033[0;34m");
    printf("--------------------------Difficulty--------------------------\n\n("
           "1 word str {hard/easy} ) - Sets the difficulty for this round\n\n");
    return 1;
  }

  // Fetch related words from api as string
  char fetch_url[256] = "https://api.datamuse.com/words?ml=";
  strcat(fetch_url, argv[1]);
  struct string s;

  CURLcode res;

  CURL *curl = curl_easy_init();
  if (curl) {
    init_string(&s);

    curl_easy_setopt(curl, CURLOPT_URL, fetch_url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);
    res = curl_easy_perform(curl);

    if (res != CURLE_OK)
      printf("Fetch request failed: %s\n", curl_easy_strerror(res));

    curl_easy_cleanup(curl);
  }
  
  // convert string to json

  json_t *root;
  json_error_t error;

  root = json_loads(s.ptr, 0, &error);
  free(s.ptr);

  if (!root) {
    fprintf(stderr, "error: on line %d: %s\n", error.line, error.text);
    return 1;
  }
  if (!json_is_array(root)) {
    fprintf(stderr, "error: root is not an array\n");
    json_decref(root);
    return 1;
  }
  for (int i = 0; i < json_array_size(root); i++) {

    json_t *data, *word, *score, *tags;
    data = json_array_get(root, i);
    const char *word_str;

    if (!json_is_object(data)) {
      fprintf(stderr, "error: word data %d is not an object\n", i + 1);
      json_decref(root);
      return 1;
    }

    word = json_object_get(data, "word");
    score = json_object_get(data, "score");
    word_str = json_string_value(word);
    printf("%s\n", word_str);
  }
}