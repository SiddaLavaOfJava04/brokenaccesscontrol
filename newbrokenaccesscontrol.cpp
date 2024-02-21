#include <iostream>
#include <curl/curl.h>
#include <jsoncpp/json/json.h>
#include <sstream> // For std::istringstream

size_t WriteCallback(char* buf, size_t size, size_t nmemb, void* userp) {
    std::string* response = (std::string*)userp;
    response->append(buf, size * nmemb);
    return size * nmemb;
}

int main() {
    for (int id = 1111; id < 9999; id++) {
        std::string url = "https://api.grades.patch.edu/grades?subjectID=1293&studentID=2022" + std::to_string(id);
        CURL* curl = curl_easy_init();
        std::string response;

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        CURLcode res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            Json::Value jsonData;
            Json::CharReaderBuilder jsonBuilder;
            std::string errors;
            std::istringstream is(response);

            if (Json::parseFromStream(jsonBuilder, is, &jsonData, &errors)) {
                std::cout << "Student: 2022" << id << ", Grade: " << jsonData["grade"].asString() << std::endl;
            } else {
                std::cerr << "Error parsing JSON response: " << errors << std::endl;
            }
        } else {
            std::cerr << "Error making request: " << curl_easy_strerror(res) << std::endl;
        }
        curl_easy_cleanup(curl);
    }
    return 0;
}
