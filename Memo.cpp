#include "Memo.h"

Memo::Memo(){
}

Memo::~Memo() {
	if (this->file_.is_open()) {
		this->file_.close();
	}
}

void Memo::get_buffer(){
	char temp_char;
	std::cin >> std::noskipws;
	while ((std::cin >> temp_char) && (temp_char != '\n')) {
		this->buffer += temp_char;
	}
}


void Memo::get_file_path() {
	std::fstream temp_file("./file_path.txt", std::ios::in);
	std::getline(temp_file, this->file_name_);
	temp_file.close();
}

void Memo::get_title(){
	std::cout << "Please enter title (first line): ";

	char temp_char;
	std::cin >> std::noskipws;
	while ((std::cin >> temp_char) && (temp_char != '\n')) {
		this->buffer += temp_char;
	}
	this->file_title_ += this->buffer;
	this->buffer.clear();
}

void Memo::create_name(){
	this->time_.get_time_str();
	this->file_name_ += this->time_.time_str_;
	this->file_name_ += '[';
	this->file_name_ += this->file_title_;
	this->file_name_ += ']';
	this->file_name_ += ".data";
}

void Memo::write_memo(){
	if (this->file_name_.empty()){
		this->get_file_path();
		this->create_name();
	}
	if (!this->file_.is_open()){
		this->file_.open(this->file_name_.c_str(), std::ios::out | std::ios::app);
	}
	this->file_ << this->buffer << std::endl;
	this->buffer.clear();
}
