#ifndef GENERATERANDOMSTRING_H
#define GENERATERANDOMSTRING_H
#include <iostream>
#include <random>

using namespace std;

class GenerateRandomString{
    private:
        string randomString;
    public:
        GenerateRandomString(){
            int length = 40;
            string CHARSET = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
            for (int i = 0; i < length; ++i) {
                int randomIndex = (int)(((float)rand()/RAND_MAX) * (CHARSET.length() - 1));
                randomString += CHARSET[randomIndex];
            }
        }
        GenerateRandomString(int length){
            string CHARSET = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
            for (int i = 0; i < length; ++i) {
                int randomIndex = (int)(((float)rand()/RAND_MAX) * (CHARSET.length() - 1));
                randomString += CHARSET[randomIndex];
            }
        }
        string getString(){
            return randomString;
        }
};
#endif