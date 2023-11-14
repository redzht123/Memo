#pragma once
#include<chrono>
#include<ctime>
class Time{
private:
	int buffer_size_;

	tm *time_struct_;

public:

	Time();

	~Time();

	char* time_str_;

	void get_time_str();

	static long long int time_now();
};

