// as-logging.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <time.h>
#include <iostream>

int main()
{
    struct tm newtime;
    errno_t err;
    _int64 ltime{ 0 };
    _time64(&ltime);

    err = gmtime_s(&newtime, &ltime);

	std::time_t time = std::time({});
	char timeString[std::size("yyyy-mm-ddThh:mm:ssZ")];
	std::strftime(std::data(timeString), std::size(timeString), "%FT%TZ", &newtime);

    std::cout << timeString << "\n";
}
