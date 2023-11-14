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

	std::string file_title_;

	void get_file_path();


	void create_name();

	std::string buffer;
public:
	Memo();

	~Memo();

	void get_title();

	void get_buffer();

	void write_memo();


};

