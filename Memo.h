#pragma once

#include<string>
#include<fstream>
#include"Time.h"
#include<iostream>
class Memo{
private:
	// variables
	Time time_;

	std::fstream file_;

	std::string file_name_;

	void get_file_path();

public:
	Memo();

	~Memo();

	void write_memo(const char* buffer);
};

